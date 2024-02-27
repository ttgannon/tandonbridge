#include <iostream>
#include <string>

using namespace std;

int main()
{
    int userInput, numberRemainder, binaryCounter = 0;
    string binaryRep;

    cout << "Enter a decimal number:" << endl;
    cin >> userInput;

    numberRemainder = userInput;

    while (numberRemainder > 0)
    {
        if (numberRemainder % 2 > 0)
        {
            binaryRep += '1';
        }
        else
        {
            binaryRep += '0';
        }
        binaryCounter += 1;
        numberRemainder = numberRemainder / 2;
    }

    string binaryCopy = binaryRep;
    int binaryCounterCopy = binaryCounter;

    for (int i = 0; i < binaryCounter; i++)
    {
        binaryCopy[i] = binaryRep[i + binaryCounterCopy - 1];
        binaryCounterCopy -= 2;
    }

    cout << "The binary representation of " << userInput << " is " << binaryCopy << endl;

    return 0;
}