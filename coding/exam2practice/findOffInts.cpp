#include <iostream>
using namespace std;

int findOddIntegersAndSum(int S[], int length, int &sumOdds);
int main()
{
    int sumOdds = 0;
    int S[10] = {10, -5, -20, 0, 7, -15, -5, -100};
    int length = 8;
    int intsSum = findOddIntegersAndSum(S, length, sumOdds);

    cout << intsSum << " and " << sumOdds << endl;
}

int findOddIntegersAndSum(int S[], int length, int &sumOdds)
{
    // base case
    if (length == 0)
    {
        if (S[0] % 2 != 0)
        {
            sumOdds += S[0];
            return 1;
        }
        else
            return 0;
    }
    int totalOddNums = findOddIntegersAndSum(S, length - 1, sumOdds);
    if (S[length] % 2 != 0)
    {
        sumOdds += S[length];
        totalOddNums += 1;
    }
    return totalOddNums;
}