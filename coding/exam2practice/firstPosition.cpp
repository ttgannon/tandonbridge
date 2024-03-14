#include <iostream>
using namespace std;

int findFirstPosition(int arr[], int arrSize, int elem);

int main()
{
    int arr[10] = {2, 15, 3, 8, 3, 10, 6, 23, 12, 32};
    int arrSize = 10;
    int elem = 2;

    int idx = findFirstPosition(arr, arrSize, elem);

    cout << idx << endl;
}

int findFirstPosition(int arr[], int arrSize, int elem)
{
    // base case
    if (arrSize == 1)
    {
        if (arr[0] == elem)
            return 0;
        else
            return -1;
    }

    int firstPosition = findFirstPosition(arr, arrSize - 1, elem);

    if (firstPosition != -1)
        return firstPosition;

    if (arr[arrSize - 1] == elem)
        return arrSize - 1;
    else
        return -1;
}