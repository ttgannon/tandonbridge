#include <iostream>
using namespace std;

void removeZeroes(int *arr, int arrSize);
int main()
{
    int intArr[10] = {0, 0, 0, 0, 0, 4, -3, 0, 0, 1};
    int arrSize = 10;

    removeZeroes(intArr, arrSize);

    for (int i = 0; i < arrSize; i++)
        cout << intArr[i] << endl;
}

void removeZeroes(int *arr, int arrSize)
{
    int zeroIdx = 0, nonzeroIdx = 0;
    for (int i = 0; i < arrSize; i++)
    {
        if (arr[i] == 0)
        {
            if (zeroIdx == 0)
                zeroIdx = i;
            while (arr[i] == 0)
            {
                i++;
            }
            // swap
            nonzeroIdx = i;
            int temp = arr[i];
            arr[i] = arr[zeroIdx];
            arr[zeroIdx] = temp;
            zeroIdx++;
            nonzeroIdx++;
        }
        else
        {
            if (zeroIdx > 0)
            {
                // swap
                nonzeroIdx = i;
                int temp = arr[i];
                arr[i] = arr[zeroIdx];
                arr[zeroIdx] = temp;
                zeroIdx++;
                nonzeroIdx++;
            }
            nonzeroIdx = i;
        }
    }
}