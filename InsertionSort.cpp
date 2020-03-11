#include <iostream>
using namespace std;

void insertionSort(int *array, int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = array[i];
        int j;
        for (j = i - 1; j >= 0; j--)
        {
            if (array[j] > key)
                array[j + 1] = array[j];
            else
                break;
        }
        array[j + 1] = key;
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

    insertionSort(array, n);

    cout << "Sorted array: ";
    for (int j = 0; j < n; j++)
    {
        cout << array[j] << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}
