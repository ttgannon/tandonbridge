#include <iostream>
using namespace std;

int main()
{
    int userInput, numSpaces, numStars, currLine = 0;

    cout << "Please enter a positive integer:" << endl;
    cin >> userInput;

    const int TOTAL_LINES = (2 * userInput) + 1;

    while (currLine <= TOTAL_LINES / 2)
    {
        numSpaces = userInput - currLine;

        for (int i = 0; i < numSpaces; i++)
        {
            cout << ' ';
        }
        numStars = (2 * currLine) + 1;
        for (int j = 0; j < numStars; j++)
        {
            cout << '*';
        }

        cout << endl;
        currLine++;
    }

    while (currLine < TOTAL_LINES)
    {
        numSpaces++;

        for (int i = 0; i < numSpaces; i++)
        {
            cout << ' ';
        }
        numStars -= 2;
        for (int j = 0; j < numStars; j++)
        {
            cout << '*';
        }

        cout << endl;
        currLine++;
    }

    return 0;
}