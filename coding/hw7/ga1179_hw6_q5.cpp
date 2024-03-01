#include <iostream>
using namespace std;

int *getPosNums1(int *arr, int arrSize, int &outPosArrSize);
int *getPosNums2(int *arr, int arrSize, int *outPosArrSizePtr);
void getPosNums3(int *arr, int arrSize, int *&outPosArr, int &outPosArrSize);
void getPosNums4(int *arr, int arrSize, int **outPosArrPtr, int *outPosArrSizePtr);

int main()
{
    int arr[6] = {3, -1, -3, 0, 6, 4};
    int arrSize = 6, outPosArrSize;
    int *outPosArrSizePtr = NULL;

    // for getPosNums3
    int *outPosArr;

    // for getPosNums4
    int **outPosArrPtr;

    // does it have to be the same array? i.e. can i loop over and add them to a new array?
    int *posNumsPtr1 = getPosNums1(arr, arrSize, outPosArrSize);

    int *posNumsPtr2 = getPosNums2(arr, arrSize, outPosArrSizePtr);

    getPosNums3(arr, arrSize, outPosArr, outPosArrSize);

    getPosNums4(arr, arrSize, outPosArrPtr, outPosArrSizePtr);
}

int *getPosNums1(int *arr, int arrSize, int &outPosArrSize)
{
    // should use something like a vector or dynamic alloc?
    // could create new array of size arrSize
    int newArr[arrSize];
    for (int i = 0; i < arrSize; i++)
    {
        if (arr[i] > 0)
        {
            // add it to new array
            newArr[i] = arr[i];
            outPosArrSize += 1;
        }
    }
    return &newArr[0];
}

int *getPosNums2(int *arr, int arrSize, int *outPosArrSizePtr)
{
    // should use something like a vector or dynamic alloc?
    // could create new array of size arrSize
    int newArr[arrSize];
    for (int i = 0; i < arrSize; i++)
    {
        if (arr[i] > 0)
        {
            // add it to new array
            newArr[i] = arr[i];
            *outPosArrSizePtr += 1;
        }
    }
    return &newArr[0];
}

void getPosNums3(int *arr, int arrSize, int *&outPosArr, int &outPosArrSize)
{
    int newArr[arrSize];
    for (int i = 0; i < arrSize; i++)
    {
        if (arr[i] > 0)
        {
            // add it to new array
            newArr[i] = arr[i];
            outPosArrSize += 1;
            if (i == 0)
                outPosArr = &newArr[0];
        }
    }
}

void getPosNums4(int *arr, int arrSize, int **outPosArrPtr, int *outPosArrSizePtr)
{
    int *newArr[arrSize];
    for (int i = 0; i < arrSize; i++)
    {
        if (arr[i] > 0)
        {
            // add it to new array
            newArr[i] = &arr[i];
            // *newArr[i] = arr[i];
            *outPosArrSizePtr += 1;
            if (i == 0)
                outPosArrPtr = &newArr[0];
        }
    }
}
