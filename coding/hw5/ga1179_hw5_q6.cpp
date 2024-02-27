#include <iostream>
using namespace std;

double eApprox(int n);
double factorial(int m);

int main()
{
    cout.precision(30);
    for (int n = 1; n <= 15; n++)
    {
        cout << "n = " << n << '\t' << eApprox(n) << endl;
    }
    return 0;
}

double eApprox(int n)
{
    double approxE = 0;
    for (int i = 1; i <= n; i++)
    {
        approxE += 1 / factorial(i);
    }
    return approxE;
}

double factorial(int m)
{
    if (m == 0)
    {
        return 1;
    }
    else
    {
        return m * factorial(m - 1);
    }
}