#include <iostream>
using namespace std;

int midIdx = 0;
int findIndex(int S[], int x, int left, int right);
int main()
{
    int x, left, right;
    int S[8] = {10, 15, 20, 25, 28, 40, 55, 90};
    x = 10;
    left = 0;
    right = 7;
    int idx = findIndex(S, x, left, right);
    cout << idx << endl;
}

int findIndex(int S[], int x, int left, int right)
{
    // base case
    if (left > right)
    {
        return -1;
    }

    int midIdx = left + (right - left) / 2;

    if (S[midIdx] == x)
    {
        return midIdx;
    }
    else if (S[midIdx] > x)
        return findIndex(S, x, left, midIdx - 1);
    else
        return findIndex(S, x, midIdx + 1, right);
}