#include <iostream>
using namespace std;

int fib(int n);

int main()
{
    int userInput;
    cout << "Please enter a positive integer: " << endl;
    cin >> userInput;

    int fibonacci = fib(userInput);
    cout << fibonacci << endl;
    return 0;
}

int fib(int n)
{
    int counter = 3;
    int F1 = 1, F2 = 1;
    int F3 = 2;

    if (n < 3)
    {
        return 1;
    }

    while (n > counter)
    {
        F3 = F2 + F3;
        F2 = F3 - F2;
        counter += 1;
    }
    return F3;
}
