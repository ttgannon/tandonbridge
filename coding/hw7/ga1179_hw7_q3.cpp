#include <iostream>
using namespace std;

void printArray(int arr[], int arrSize);
void oddsKeepEvensFlip(int arr[], int arrSize);

int main()
{
    int arr[10] = {5, 2, 11, 7, 6, 4};
    int arrSize = 6;

    oddsKeepEvensFlip(arr, arrSize);
    printArray(arr, arrSize);

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

void oddsKeepEvensFlip(int arr[], int arrSize)
{
    int oddIdx = 0, evenIdx = arrSize - 1;
    int tempArr[arrSize];

    for (int i = 0; i < arrSize; i++)
    {
        if (arr[i] % 2 == 0)
        {
            tempArr[evenIdx] = arr[i];
            evenIdx--;
        }
        else
        {
            tempArr[oddIdx] = arr[i];
            oddIdx++;
        }
    }

    for (int i = 0; i < arrSize; i++)
    {
        arr[i] = tempArr[i];
    }
}