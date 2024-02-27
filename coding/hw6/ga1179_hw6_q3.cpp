#include <iostream>
using namespace std;

void printArray(int arr[], int arrSize);
void reverseArray(int arr[], int arrSize);
void removeOdd(int arr[], int &arrSize);
void splitParity(int arr[], int arrSize);

int main()
{
    int arr1[10] = {9, 2, 14, 12, -3};
    int arr1Size = 5;

    int arr2[10] = {21, 12, 6, 7, 14};
    int arr2Size = 5;

    int arr3[10] = {3, 6, 4, 1, 12};
    int arr3Size = 5;

    reverseArray(arr1, arr1Size);
    printArray(arr1, arr1Size);

    removeOdd(arr2, arr2Size);
    printArray(arr2, arr2Size);

    splitParity(arr3, arr3Size);
    printArray(arr3, arr3Size);

    return 0;
}
void printArray(int arr[], int arrSize)
{
    int i;

    for (i = 0; i < arrSize; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

void reverseArray(int arr[], int arrSize)
{
    int temp = 0, endOfArray = arrSize - 1;
    for (int i = 0; i < arrSize / 2; i++)
    {
        temp = arr[i];
        arr[i] = arr[endOfArray];
        arr[endOfArray] = temp;
        endOfArray--;
    }
}

void removeOdd(int arr[], int &arrSize)
{
    int newSize = 0;

    for (int i = 0; i < arrSize; i++)
    {
        if (arr[i] % 2 == 0)
        {
            arr[newSize] = arr[i];
            newSize++;
        }
    }
    arrSize = newSize;
}

void splitParity(int arr[], int arrSize)
{
    int oddIdx = 0;
    int evenIdx = arrSize - 1;

    while (oddIdx < evenIdx)
    {
        while (arr[oddIdx] % 2 != 0 && oddIdx < evenIdx)
        {
            oddIdx++;
        }
        while (arr[evenIdx] % 2 == 0 && oddIdx < evenIdx)
        {
            evenIdx--;
        }
        if (oddIdx < evenIdx)
        {
            int temp = arr[oddIdx];
            arr[oddIdx] = arr[evenIdx];
            arr[evenIdx] = temp;
            oddIdx++;
            evenIdx--;
        }
    }
}
