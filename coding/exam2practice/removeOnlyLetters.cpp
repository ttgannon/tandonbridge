#include <iostream>
using namespace std;

bool checkForDigits(string userInput);
int main()
{
    cout << "Please enter a non-empty sequence of Strings. Each string should "
         << "be in a separate line and consists of only lowercase English "
         << "letters and/or numerical characters. To indicate the end of the "
         << "input, enter an empty string in one line." << endl;

    string userInput;
    vector<string> stringsWithNums;
    int numberStringsExcluded = 0;

    while (true)
    {
        getline(cin, userInput);
        if (userInput.empty())
            break;

        bool hasDigits = checkForDigits(userInput);

        if (hasDigits)
        {
            stringsWithNums.push_back(userInput);
        }
        else
        {
            numberStringsExcluded += 1;
        }
    }

    // print stringswithnums

    for (int i = 0; i < stringsWithNums.size(); i++)
    {
        cout << stringsWithNums[i] << endl;
    }
    cout << "Number of Strings in the input sequence that contain only lowercase "
         << "English letters: " << numberStringsExcluded << endl;

    return 0;
}

bool checkForDigits(string userInput)
{
    for (int i = 0; i < userInput.length(); i++)
    {
        if (userInput[i] >= '0' && userInput[i] <= '9')
            return true;
    }
    return false;
}