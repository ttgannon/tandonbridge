#include <iostream>
using namespace std;

int main()
{
    int number = 0;

    while (number <= 99)
    {
        if (number % 2 && number != 13)
        {
            cout << number << endl;
        }
        number += 1;
    }
    return 0;
}