#include <iostream>
#include <string>
#include <ctime>
using namespace std;

const string PIN = "43567";
string generateRandomNum();
int generatePinEquivalent(string PIN, string randNumString);

int main()
{
    int userInput;
    srand(time(0));

    cout << "Please enter your PIN according to the following mapping:" << endl;
    cout << "PIN:   0 1 2 3 4 5 6 7 8 9" << endl;
    cout << "NUM:   ";

    // generate nums 1-3 of length 10 on the screen;
    string randNumString = generateRandomNum();

    cin >> userInput;

    // generate pinEquivalent using digits 1-3
    // of length PIN mapped to the PIN;
    int pinEquivalent = generatePinEquivalent(PIN, randNumString);

    if (pinEquivalent == userInput)
    {
        cout << "Your pin is correct" << endl;
    }
    else
    {
        cout << "Your pin is not correct" << endl;
    }

    // output the nums;
    // take user input and check the mapping;
    return 0;
}

string generateRandomNum()
{
    string randNumString;
    for (int i = 0; i <= 9; i++)
    {
        int randNum = (rand() % 3) + 1;
        cout << randNum << ' ';
        string s = to_string(randNum);
        randNumString += s;
    }
    cout << endl;
    return randNumString;
}

int generatePinEquivalent(string PIN, string randNumString)
{
    string pinEquivalent;

    for (int i = 0; i < PIN.length(); i++)
    {
        int num = PIN[i];
        pinEquivalent += randNumString[num - 48];
    }
    int intPinEquivalent = stoi(pinEquivalent);

    return intPinEquivalent;
}