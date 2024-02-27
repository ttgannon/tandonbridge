#include <iostream>
using namespace std;

const int ASCII_SCPACE = 32;
const int ASCII_0 = 48;
const int ASCII_9 = 57;
int numDigits = 0;

bool isStandAloneDigit(string phrase, int i, int &numDigits);

int main()
{
    string phrase;
    cout << "Please	enter a line of text: " << endl;
    getline(cin, phrase);

    bool isDigit;
    for (int i = 0; i < phrase.length(); i++)
    {
        while ((phrase[i] < ASCII_0 || phrase[i] > ASCII_9) && i <= phrase.length()) // while the character is not a digit
        {
            cout << phrase[i];
            i++;
        }

        if (phrase[i] >= ASCII_0 && phrase[i] <= ASCII_9 && i <= phrase.length()) // if the character is a digit
        {
            isDigit = isStandAloneDigit(phrase, i, numDigits);

            if (isDigit == true)
            {
                for (int j = 0; j < numDigits; j++)
                {
                    cout << 'x';
                }
                i += numDigits;
                cout << ' ';
            }
            else
            {
                for (int j = 0; j < numDigits; j++)
                {
                    cout << phrase[i];
                    i++;
                }
                cout << ' ';
            }
        }
    }
    cout << endl;

    return 0;
}

bool isStandAloneDigit(string phrase, int i, int &numDigits)
{
    numDigits = 0;
    while (phrase[i] != ASCII_SCPACE && i < phrase.length()) // while the char is not a space
    {
        // if char before is a letter, return false;
        if ((phrase[i - 1] < ASCII_0 || phrase[i - 1] > ASCII_9) && (phrase[i - 1] != 32))
        {
            while (phrase[i] != ASCII_SCPACE && i < phrase.length())
            {
                i++;
                numDigits++;
            }
            i -= numDigits;
            return false;
        }
        numDigits++;
        i++;
    }
    return true;
}
