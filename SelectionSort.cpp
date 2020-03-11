#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void selectionSort(int *array, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (array[j] < array[min_index])
                min_index = j;
        }
        swap(&array[i], &array[min_index]);
    }
}

int main()
{
    int n;
    cout << "Enter array size: ";
    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Element " << i << ": ";
        cin >> array[i];
    }

    selectionSort(array, n);

    cout << "Sorted array: ";
    for (int j = 0; j < n; j++)
    {
        cout << array[j] << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}
