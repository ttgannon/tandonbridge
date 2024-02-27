#include <iostream>
#include <cmath>
using namespace std;

void analyzeDividors(int num, int &outCountDivs, int &outSumDivs);
bool isPerfect(int num);
bool isAmicable(int num);

int outCountDivs = 0, outSumDivs = 0;

int main()
{
    int num;
    cout << "Please enter a positive integer >= 2: ";
    cin >> num;

    for (int i = 2; i <= num; i++)
    {
        outCountDivs = 0, outSumDivs = 0;
        int numPerfect = isPerfect(i);
        if (numPerfect)
        {
            cout << i << ' ';
        }
    }
    cout << endl;

    for (int i = 2; i <= num; i++)
    {
        outCountDivs = 0, outSumDivs = 0;
        analyzeDividors(i, outCountDivs, outSumDivs);
        int sumOfFirstIntDivs = outSumDivs;

        if (i > sumOfFirstIntDivs)
        {
            outCountDivs = 0, outSumDivs = 0;
            analyzeDividors(sumOfFirstIntDivs, outCountDivs, outSumDivs);
        }
        if (outSumDivs == i && sumOfFirstIntDivs != i)
        {
            cout << sumOfFirstIntDivs << ' ' << i << ' ';
        }
    }

    return 0;
}

void analyzeDividors(int num, int &outCountDivs, int &outSumDivs)
{
    for (int i = 1; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            outCountDivs += 1;
            outSumDivs += i;
            if (i > 1 && i != sqrt(num))
            {
                outSumDivs += (num / i);
                outCountDivs += 1;
            }
        }
    }
}

bool isPerfect(int num)
{
    analyzeDividors(num, outCountDivs, outSumDivs);
    if (num == outSumDivs)
    {
        return true;
    }
    else
    {
        return false;
    }
}
