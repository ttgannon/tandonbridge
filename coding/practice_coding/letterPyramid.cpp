#include <iostream>
using namespace std;

int main()
{
    char inLetter;
    char firstLetter = 'a';

    int spacesBefore, letterLength = 1;

    cout << "Please enter a lower-case letter:" << endl;
    cin >> inLetter;

    while (inLetter >= firstLetter)
    {
        spacesBefore = inLetter - firstLetter;
        for (int i = 0; i < spacesBefore; i++)
        {
            cout << ' ';
        }

        if (firstLetter % 2 == 0)
        {
            firstLetter -= 32;
        }

        for (int j = 0; j < letterLength; j++)
        {
            cout << firstLetter;
        }

        cout << endl;

        if (firstLetter % 2 == 0)
        {
            firstLetter += 32;
        }

        letterLength += 2;
        firstLetter += 1;
    }
    return 0;
}