#include <iostream>
using namespace std;

void countLetters(char letter, int count[]);
bool checkIfSpace(char userChar, int &numWords);
char makeLowerCase(char userChar);

int main()
{
    string userInput;
    int numWords = 0;
    int count[26] = {0};

    cout << "Please enter a line of text: " << endl;
    getline(cin, userInput);

    for (int i = 0; i < userInput.length(); i++)
    {
        // check if period, exclamation point, question mark, or space; function adds 1 to numWords by ref if yes
        bool isSpace = checkIfSpace(userInput[i], numWords);
        if (isSpace)
            continue;

        // make it lowercase if uppercase
        char userChar = makeLowerCase(userInput[i]);

        // keep track of number of letters
        countLetters(userChar, count);
    }

    cout << numWords << '\t'
         << "words" << endl;

    for (int i = 0; i < 26; i++)
    {
        char character = i + 97;
        if (count[i] > 0)
        {
            cout << count[i] << '\t' << character << endl;
        }
    }
    return 0;
}

void countLetters(char letter, int count[])
{
    if (letter >= 'a' && letter <= 'z')
    {
        int letterIdx = letter - 97;
        count[letterIdx] += 1;
    }
}

bool checkIfSpace(char userChar, int &numWords)
{
    if (userChar == 32 || userChar == 33 || userChar == 63 || userChar == 46)
    {
        numWords += 1;
        return true;
    }
    return false;
}

char makeLowerCase(char userChar)
{
    if (userChar >= 'A' && userChar <= 'Z')
    {
        userChar += 32;
    }

    return userChar;
}