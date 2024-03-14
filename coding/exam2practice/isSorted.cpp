#include <iostream>
using namespace std;

bool isSorted(int S[], int length);

int main()
{
    int S[12] = {100, 75, 27, 15, 8, -5, -5, -10};
    int length = 8;

    bool sorted = isSorted(S, 8);

    if (sorted)

        cout << "true" << endl;
    else
        cout << "false" << endl;

    int F[12] = {-1, -5, -7, -15, -26, -44, 0, 5, -1, -3};
    sorted = isSorted(F, 10);

    if (sorted)

        cout << "true" << endl;
    else
        cout << "false" << endl;

    int G[12] = {1, 15, 81, 199, 300, 400};
    sorted = isSorted(G, 6);

    if (sorted)

        cout << "true" << endl;
    else
        cout << "false" << endl;

    int H[12] = {69, 50, 33, 25, 23, 14, 5, 3, 0, -7, -9};
    sorted = isSorted(H, 11);

    if (sorted)

        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}

bool isSorted(int S[], int length)
{
    // base case
    if (length <= 1)
        return true;

    // do the work
    if (S[length - 2] < S[length - 1])
        return false;

    // recursive call
    return isSorted(S, length - 1);
}