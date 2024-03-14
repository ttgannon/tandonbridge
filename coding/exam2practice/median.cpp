#include <iostream>
using namespace std;

double findMedian(int arr[], int n);

int main()
{
    int arr[10] = {4, 1, 6, 2, 7, 3, 2, 8, 9};
    int n = 9;

    double median = findMedian(arr, n);

    cout << median << endl;
}

double findMedian(int arr[], int n)
{
    int midIdx = n / 2;
    // arr is in range 1, 2, ..., n
    int *newArray = new int[n];
    for (int i = 0; i < n; i++)
    {
        newArray[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        newArray[arr[i] - 1]++;
    }

    double median;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        count += newArray[i];
        if (count >= midIdx + 1)
        {
            median = i + 1;
            break;
        }
    }

    delete[] newArray;

    return median;
}