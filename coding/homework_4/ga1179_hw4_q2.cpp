#include <iostream>
#include <string>

using namespace std;

int main()
{
    int userInput, decimalNumber;
    int mCounter = 0, dCounter = 0, cCounter = 0, lCounter = 0, xCounter = 0, vCounter = 0, iCounter = 0;
    string romanString;

    cout << "Enter a decimal number:" << endl;
    cin >> userInput;

    decimalNumber = userInput;

    while (decimalNumber / 1000 >= 1)
    {
        mCounter += 1;
        decimalNumber -= 1000;
        romanString += 'M';
    }

    while (decimalNumber / 500 >= 1)
    {
        dCounter += 1;
        decimalNumber -= 500;
        romanString += 'D';
    }

    while (decimalNumber / 100 >= 1)
    {
        cCounter += 1;
        decimalNumber -= 100;
        romanString += 'C';
    }

    while (decimalNumber / 50 >= 1)
    {
        lCounter += 1;
        decimalNumber -= 50;
        romanString += 'L';
    }

    while (decimalNumber / 10 >= 1)
    {
        xCounter += 1;
        decimalNumber -= 10;
        romanString += 'X';
    }

    while (decimalNumber / 5 >= 1)
    {
        vCounter += 1;
        decimalNumber -= 5;
        romanString += 'V';
    }

    while (decimalNumber / 1 >= 1)
    {
        iCounter += 1;
        decimalNumber -= 1;
        romanString += 'I';
    }

    cout << userInput << " is " << romanString << endl;

    return 0;
}