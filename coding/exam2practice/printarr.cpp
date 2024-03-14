#include <iostream>
using namespace std;

int *first10Squares()
{
    int *arr = new int[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = (i + 1) * (i + 1);
    }
    return arr;
}

void printArray(int arr[], int arrSize)
{
    for (int i = 0; i < arrSize; i++)
        cout << arr[i] << "\t";
    cout << endl;
}
int main()
{
    int *arr;
    arr = first10Squares();
    printArray(arr, 10);

    delete[] arr;

    return 0;
}