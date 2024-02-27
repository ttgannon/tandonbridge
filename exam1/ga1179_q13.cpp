/*

Gavin Arneson
ga1179

*/

#include <iostream>
using namespace std;

int main()
{
    int userInput, numSpaces, numAsterisks, currLine = 0;

    cout << "Please enter a positive integer:" << endl;
    cin >> userInput;

    const int NUM_OF_LINES = userInput + 1;

    while (currLine < NUM_OF_LINES)
    {
        if (currLine % 2 == 0)
        {
            numSpaces = (userInput - (currLine + 1)) / 2;
            for (int i = 0; i < numSpaces; i++)
            {
                cout << ' ';
            }

            numAsterisks = currLine + 1;
            for (int j = 0; j < numAsterisks; j++)
            {
                cout << '*';
            }
        }
        else
        {
            for (int i = 0; i < userInput; i++)
            {
                cout << '*';
            }
        }
        cout << endl;
        currLine++;
    }

    return 0;
}