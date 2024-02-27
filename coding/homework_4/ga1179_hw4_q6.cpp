#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    int userInput, inputCounter, userNumber, evenCounter, tensCounter;

    cout << "Please enter a positive integer: ";
    cin >> userInput;

    inputCounter = 1, tensCounter = 1, evenCounter = 0;

    while (userInput >= inputCounter)
    {
        userNumber = inputCounter;
        tensCounter = 1;
        while (userNumber / 10)
        {
            userNumber = inputCounter / 10;
            tensCounter += 1;
        }

        for (int i = 0; i < tensCounter; i++)
        {
            if (i == 0)
            {
                if (inputCounter % 2 == 0)
                {
                    evenCounter += 1;
                }
                else
                {
                    evenCounter -= 1;
                }
            }
            else
            {
                if ((inputCounter / 10) % 2 == 0)
                {
                    evenCounter += 1;
                }
                else
                {
                    evenCounter -= 1;
                }
            }
        }

        if (evenCounter > 0)
        {
            cout << inputCounter << endl;
        }
        inputCounter += 1;
        evenCounter = 0;
    }

    return 0;
}