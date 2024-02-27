#include <iostream>
using namespace std;

int main()
{
    int userInput, currentLine = 0, numSpaces, numStars = 1;

    cout << "Please enter a positive integer:" << endl;
    cin >> userInput;

    const int TOTAL_LINES = 4 * (userInput)-3;

    while (currentLine <= TOTAL_LINES / 2)
    {
        numSpaces = 2 * (userInput) - (currentLine + 2);

        for (int i = 0; i < numSpaces; i++)
        {
            cout << ' ';
        }

        for (int j = 0; j < numStars; j++)
        {
            cout << '*';
        }

        cout << endl;
        numStars++;
        currentLine++;
    }

    numStars -= 2;
    currentLine -= 2;
    while (currentLine >= 0)
    {
        numSpaces = 2 * (userInput) - (currentLine + 2);

        for (int i = 0; i < numSpaces; i++)
        {
            cout << ' ';
        }

        for (int j = 0; j < numStars; j++)
        {
            cout << '*';
        }
        cout << endl;
        numStars--;
        currentLine--;
    }

    return 0;
}