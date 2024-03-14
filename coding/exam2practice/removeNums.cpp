#include <iostream>
using namespace std;

void printResults(vector<string> formattedStrings, int numRemoved);
bool checkForZerosAndOnes(string userInput);
int main()
{
    string userInput;
    vector<string> formattedStrings;
    int numRemoved = 0;

    cout << "Please enter a non-empty sequence of Strings. Each string should"
         << "be in a separate line and consists of only decimal digit"
         << "characters. To indicate the end of the input, enter an empty"
         << "string in one line." << endl;

    while (true)
    {
        getline(cin, userInput);
        if (userInput.empty())
            break;

        // remove string with anything but zeros and ones
        bool hasOnlyZerosAndOnes = checkForZerosAndOnes(userInput);
        // push it into vector
        if (hasOnlyZerosAndOnes)
            formattedStrings.push_back(userInput);
        else
            numRemoved += 1;
    }

    printResults(formattedStrings, numRemoved);
}

bool checkForZerosAndOnes(string userInput)
{
    for (int i = 0; i < userInput.length(); i++)
    {
        if (userInput[i] != '0' && userInput[i] != '1')
        {
            return false;
        }
    }
    return true;
}

void printResults(vector<string> formattedStrings, int numRemoved)
{
    for (int i = 0; i < formattedStrings.size(); i++)
    {
        cout << formattedStrings[i] << endl;
    }
    cout << "Number of Strings in the input sequence that get deleted for containing "
         << "at least one character which is not 0 or 1: " << numRemoved << endl;
}