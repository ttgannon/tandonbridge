#include <iostream>
using namespace std;

int palindromeDistance(int *arr, int n);
int main()
{
    // palindrome distance is number of opposite pairs that are not equal to each other
    int arr[6] = {1, 3, 6, 6, 3, 1};
    int n = 6;

    int d = palindromeDistance(arr, n);

    cout << d << endl;
}

int palindromeDistance(int *arr, int n)
{
    // base case
    if (n == 0)
    {
        return 0;
    }

    int distance = palindromeDistance(arr + 1, n - 2);

    if (arr[0] != arr[n - 1])
        distance += 1;
    return distance;
}