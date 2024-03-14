#include <iostream>
using namespace std;

string removeChars(string userInput);
void countCharType(string returnString, string userInput);
void printStrings(vector<string> stringsVector);

int onlySpecialChars = 0, onlyEnglishChars = 0;

int main()
{
    string userInput, stringWithoutChars;
    vector<string> stringsVector;

    cout << "Please enter a non-empty sequence of Strings. Each string should"
         << "be in a separate line and consists of only lowercase English"
         << "letters and/or special characters @, #, $, !, &. To indicate the"
         << "end of the input, enter an empty string in one line." << endl;

    while (true)
    {
        getline(cin, userInput);

        if (userInput.empty())
        {
            break;
        }

        stringWithoutChars = removeChars(userInput);
        if (stringWithoutChars.empty())
        {
            continue;
        }
        stringsVector.push_back(stringWithoutChars);
    }

    printStrings(stringsVector);
}

string removeChars(string userInput)
{
    string returnString;
    for (int i = 0; i < userInput.length(); i++)
    {
        if (userInput[i] == '!' || userInput[i] == '#' || userInput[i] == '@' || userInput[i] == '$' || userInput[i] == '&')
        {
            continue;
        }
        else
            returnString += userInput[i];
    }

    countCharType(returnString, userInput);

    return returnString;
}

void countCharType(string returnString, string userInput)
{
    if (returnString.empty())
        onlySpecialChars += 1;

    if (returnString.length() == userInput.length())
        onlyEnglishChars += 1;
}

void printStrings(vector<string> stringsVector)
{
    for (int i = 0; i < stringsVector.size(); i++)
    {
        cout << stringsVector[i] << endl;
    }

    cout << "Number of Strings in the input sequence that contain only "
         << "special characters: " << onlySpecialChars << endl;

    cout
        << "Number of Strings in the input sequence that contain only "
        << "lowercase English letters: " << onlyEnglishChars << endl;
}