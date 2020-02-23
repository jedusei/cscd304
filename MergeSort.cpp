#include <iostream>
#include <stdlib.h>
#include <sys/time.h>
#include <fstream>
using namespace std;

void randomize(int *, int);
void startTimer();
unsigned int stopTimer();
void mergeSort(int *, int, int);

// Array max size
const int MAX_SIZE = 100000;
// Initialize array with the maximum size
int array[MAX_SIZE];
// Name of the file to store the results in
const char *filename = "MergeSortResults.csv";

int main()
{
    // Create/Open file for writing
    ofstream fout = ofstream(filename);
    fout << "Array Size, Time Taken (ms)" << endl;

    cout << "[Array Size]: [Time Taken]" << endl;

    for (int n = 2; n <= MAX_SIZE; n *= 2)
    {
        // Randomize the first n values of the array
        randomize(array, n);
        // Record the current time so we can measure the elapsed time at the end of the sort operation
        startTimer();
        // Sort the first n values of the array
        mergeSort(array, 0, n);
        // Measure the elapsed time
        unsigned int elapsedTime = stopTimer();
        // Display results
        cout << n << " elements: " << elapsedTime << " ms" << endl;
        // Write results to file
        fout << n << ", " << elapsedTime << endl;
    }

    fout.close();
    cout << "Results written to '" << filename << "'." << endl;
    cout << "Open in Microsoft Excel or another similar application to plot the graph." << endl;
    system("pause");
    return 0;
}

void randomize(int *array, int n)
{
    for (int i = 0; i < n; i++)
        array[i] = (rand() % 100) + 1; // Random number in the range [1, 100]
}

unsigned long long startTime = 0;
void startTimer()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    startTime = ((((unsigned long long)tv.tv_sec) * 1000) + (((unsigned long long)tv.tv_usec) / 1000));
}
unsigned int stopTimer()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    unsigned long long stopTime = ((((unsigned long long)tv.tv_sec) * 1000) + (((unsigned long long)tv.tv_usec) / 1000));
    return stopTime - startTime;
}

void merge(int *array, int l, int m, int r)
{
    int i, j, k, leftSize, rightSize;
    leftSize = m - l + 1;
    rightSize = r - m;
    int leftArray[leftSize], rightArray[rightSize];

    // Extract left and right parts into separate arrays
    for (i = 0; i < leftSize; i++)
        leftArray[i] = array[l + i];
    for (j = 0; j < rightSize; j++)
        rightArray[j] = array[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    // Merge left and right parts
    while (i < leftSize && j < rightSize)
    {
        if (leftArray[i] <= rightArray[j])
        {
            array[k] = leftArray[i];
            i++;
        }
        else
        {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }
    while (i < leftSize)
    {
        array[k] = leftArray[i];
        i++;
        k++;
    }
    while (j < rightSize)
    {
        array[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSort(int *array, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        // Sort first and second arrays
        mergeSort(array, l, m);
        mergeSort(array, m + 1, r);
        merge(array, l, m, r);
    }
}