#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a, b, c, solution1, solution2, discriminant;
    double sqrtResult;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);

    cout << "Please enter value of a: ";
    cin >> a;
    cout << "Please enter value of b: ";
    cin >> b;
    cout << "Please enter value of c: ";
    cin >> c;

    discriminant = (b * b - (4 * (a) * (c)));

    if (a == 0 && b == 0 && c == 0)
    {
        cout << "There is an infinite number of solutions." << endl;
    }
    else if (a == 0 && b == 0 && c != 0)
    {
        cout << "There is no solution." << endl;
    }
    else if (discriminant > 0)
    {
        solution1 = (-1 * b + sqrt(discriminant)) / (2 * a);
        solution2 = (-1 * b - sqrt(discriminant)) / (2 * a);
        cout << "There are two real solutions, x=" << solution1 << " and x=" << solution2 << endl;
    }
    else if (discriminant == 0)
    {
        solution1 = ((-1 * b) / (2 * a));
        cout << "This equation has a single real solution x=" << solution1 << endl;
    }
    else if (discriminant < 0)
    {
        cout << "No real solution." << endl;
    }

    return 0;
}