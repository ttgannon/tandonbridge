#include <iostream>
using namespace std;

int longestZeroes(int *arr, int arrSize);
int main()
{
    int intArr[10] = {0, 0, 0, 0, 0, 0, 2, 0, 0, 0};
    int arrSize = 10;

    int longestZeroRun = longestZeroes(intArr, arrSize);

    cout << longestZeroRun << endl;
}

int longestZeroes(int *arr, int arrSize)
{
    int numZeroes = 0;
    int arrIdx = arrSize - 1;
    // base case
    if (arrSize == 0)
    {
        return arr[0];
    }

    // recursive call
    numZeroes = longestZeroes(arr, arrSize - 1);
    if (arr[arrIdx] == 0)
    {
        numZeroes += 1;
    }
    else
    {
        return 0;
    }
    return numZeroes;
}