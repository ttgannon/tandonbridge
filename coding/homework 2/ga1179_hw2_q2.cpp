#include <iostream>
using namespace std;

int main()
{
    int quarters, nickels, dimes, pennies;
    int dollars, cents;

    cout << "Please enter your amount in the format of dollars and cents separated by a space:" << endl;
    cin >> dollars >> cents;
    cout << dollars << " dollars and " << cents << " cents are: " << endl;

    quarters = cents / 25;
    cents = cents % 25;
    dimes = cents / 10;
    cents = cents % 10;
    nickels = cents / 5;
    cents = cents % 5;
    pennies = cents / 1;

    quarters = quarters + dollars * 4;

    cout << quarters << " quarters, " << dimes << " dimes, " << nickels << " nickels and " << pennies << " pennies" << endl;

    return 0;
}
