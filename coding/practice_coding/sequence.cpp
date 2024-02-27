#include <iostream>
using namespace std;

int main()
{
    int numbersGroupOne = 0, numbersGroupTwo = 0, numbersGroupThree = 0, numbersGroupFour = 0;

    int userInput, firstDigit, lastDigit, sum;

    cout << "Please enter a sequence of numbers (with at least 2-digit and at most 8-digits), each one in a separate line. End your sequence by typing -1:" << endl;

    while (userInput != -1)
    {
        cin >> userInput;

        if (userInput == -1)
        {
            break;
        }

        lastDigit = userInput % 10;

        while (userInput / 10)
        {
            userInput = userInput / 10;
        }
        firstDigit = userInput;

        sum = firstDigit + lastDigit;

        if (sum < 5)
        {
            numbersGroupOne += 1;
        }

        else if (sum >= 5 && sum < 10)
        {
            numbersGroupTwo += 1;
        }

        else if (sum >= 10 && sum < 15)
        {
            numbersGroupThree += 1;
        }

        else if (sum >= 15)
        {
            numbersGroupFour += 1;
        }
    }

    cout << "Total count of numbers in Group 1: " << numbersGroupOne << endl;
    cout << "Total count of numbers in Group 2: " << numbersGroupTwo << endl;
    cout << "Total count of numbers in Group 3: " << numbersGroupThree << endl;
    cout << "Total count of numbers in Group 4: " << numbersGroupFour << endl;

    return 0;
}
