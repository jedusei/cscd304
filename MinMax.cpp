#include <iostream>
using namespace std;

void findMinMax(int[], int, int, int *, int *);

int main()
{
    int array[20];
    int length;

    cout << "Enter array length: ";
    cin >> length;
    for (int i = 0; i < length; i++)
    {
        cout << "Element " << i << ": ";
        cin >> array[i];
    }
    cout << endl;

    int min, max;
    findMinMax(array, 0, length - 1, &min, &max);
    cout << "Minimum: " << min << endl;
    cout << "Maximum: " << max << endl;

    system("pause");
    return 0;
}

void findMinMax(int array[], int low, int high, int *min, int *max)
{
    if (low == high)
        *min = *max = array[low];
    else if (high - low == 1)
    {
        if (array[low] > array[high])
        {
            *min = array[high];
            *max = array[low];
        }
        else
        {
            *min = array[low];
            *max = array[high];
        }
    }
    else
    {
        int mid = (low + high) / 2;
        int min1, max1, min2, max2;
        findMinMax(array, low, mid, &min1, &max1);
        findMinMax(array, mid + 1, high, &min2, &max2);

        if (min1 < min2)
            *min = min1;
        else
            *min = min2;

        if (max1 > max2)
            *max = max1;
        else
            *max = max2;
    }
}