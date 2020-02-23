#include <iostream>
using namespace std;

int findIndex(int, int[], int);

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

    int key;
    cout << "Enter element to find: ";
    cin >> key;

    int pos = findIndex(key, array, length);
    if (pos == -1)
        cout << "Element not found." << endl;
    else
        cout << "Element found at index " << pos << "." << endl;

    system("pause");
    return 0;
}

int findIndex(int key, int array[], int length)
{
    if (length == 0)
        return -1;
    else if (key == array[length - 1])
        return length - 1;
    else
        return findIndex(key, array, length - 1);
}