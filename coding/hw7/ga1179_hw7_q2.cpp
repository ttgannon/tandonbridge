#include <iostream>
using namespace std;

bool checkIfSpace(char userChar);
char makeLowerCase(char userChar);
void prepareForCount(string string1, string string2, int count[]);
void countLetters(char letter, int count[], bool add = true);

int main()
{
    int count[26] = {0};
    string string1, string2;

    cout << "Please enter a string: " << endl;
    getline(cin, string1);
    cout << "Please enter another string: " << endl;
    getline(cin, string2);

    // this removes whitespace/punctuation and calls the count function, modifying the count array by adding the letters of first
    // string and subtracting letters of second string
    prepareForCount(string1, string2, count);

    for (int i = 0; i < 26; i++)
    {
        if (count[i] != 0)
        {
            cout << "false" << endl;
            return 0;
        }
    }
    cout << "true" << endl;
    return 0;
}

char makeLowerCase(char userChar)
{
    if (userChar >= 'A' && userChar <= 'Z')
    {
        userChar += 32;
    }

    return userChar;
}

bool checkIfSpace(char userChar)
{
    if (userChar == 32 || userChar == 33 || userChar == 63 || userChar == 46)
        return true;
    else
        return false;
}

void countLetters(char letter, int count[], bool add)
{
    if (add)
    {
        if (letter >= 'a' && letter <= 'z')
        {
            int letterIdx = letter - 97;
            count[letterIdx] += 1;
        }
    }
    else
    {
        if (letter >= 'a' && letter <= 'z')
        {
            int letterIdx = letter - 97;
            count[letterIdx] -= 1;
        }
    }
}

void prepareForCount(string string1, string string2, int count[])
{
    int longestString;

    if (string1.length() > string2.length())
        longestString = string1.length();
    else
        longestString = string2.length();

    for (int i = 0; i < longestString; i++)
    {
        // check if period, exclamation point, question mark, or space, skip if so
        bool isSpace = checkIfSpace(string1[i]);
        if (!isSpace)
        {
            // make it lowercase if uppercase
            char userChar = makeLowerCase(string1[i]);

            // keep track of number of letters
            countLetters(userChar, count);
        }

        // check if period, exclamation point, question mark, or space, skip if so
        isSpace = checkIfSpace(string2[i]);
        if (!isSpace)
        {
            // make it lowercase if uppercase
            char userChar = makeLowerCase(string2[i]);

            // keep track of number of letters
            bool add = false;
            countLetters(userChar, count, add);
        }
    }
}