#include <iostream>
using namespace std;

const int ARRSIZE = 20;

int arr[20];

int minInArray(int arr[], int ARRSIZE);
void printMinIndcs(int arr[], int ARRSIZE, int minVal);

int main()
{
    cout << "Please	enter 20 integers separated by a space:" << endl;
    int minVal = minInArray(arr, ARRSIZE);

    cout << "The minimum value is " << minVal << ", and it is located in the following indices: ";

    printMinIndcs(arr, ARRSIZE, minVal);

    cout << endl;

    return 0;
}

int minInArray(int arr[], int ARRSIZE)
{
    int minVal = 0;
    for (int ind = 0; ind <= ARRSIZE - 1; ind++)
    {
        cin >> arr[ind];
        if (ind == 0)
        {
            minVal = arr[ind];
            continue;
        }

        if (arr[ind] <= minVal)
        {
            minVal = arr[ind];
        }
    }
    return minVal;
}

void printMinIndcs(int arr[], int ARRSIZE, int minVal)
{
    for (int ind = 0; ind <= ARRSIZE - 1; ind++)
    {
        if (arr[ind] == minVal)
        {
            cout << ind << ' ';
        }
    }
}