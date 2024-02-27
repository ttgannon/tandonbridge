#include <iostream>
#include <cmath>
using namespace std;

void printDivisors(int num);

int main()
{
    int userInput;
    cout << "Please enter a positive integer >= 2: ";
    cin >> userInput;

    printDivisors(userInput);

    return 0;
}

void printDivisors(int num)
{
    int highestDivisor = num;
    for (int i = 1; i < sqrt(num); i++)
    {
        if (num % i == 0)
        {
            cout << i << ' ';
        }
    }

    for (int i = sqrt(num); i >= 1; i--)
    {
        if (num % i == 0)
        {
            cout << num / i << ' ';
        }
    }
}