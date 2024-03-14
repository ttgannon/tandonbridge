#include <iostream>
using namespace std;
// base case:

// if length == 0, return if the letter is a consonant

// recursive case:

// int consonants+= = countConsonants()

// print consonants

int numConsonants = 0;

int countConsonants(string s, int length)
{
    if (length == 0)
    {
        if (s[length] == 'a' || s[length] == 'i' || s[length] == 'o' || s[length] == 'u' || s[length] == 'e' || s[length] == 'A' || s[length] == 'E' || s[length] == 'I' || s[length] == 'O' || s[length] == 'U')
        {
            return 0;
        }
        else
            return 1;
    }

    int temp = countConsonants(s, length - 1);

    if (s[length] == 'a' || s[length] == 'i' || s[length] == 'o' || s[length] == 'u' || s[length] == 'e' || s[length] == 'A' || s[length] == 'E' || s[length] == 'I' || s[length] == 'O' || s[length] == 'U')
    {
        return numConsonants;
    }
    else
        return numConsonants += 1;
}

int main()
{
    string s = "CSBridge";
    int length = s.length();
    int numConsos = countConsonants(s, length);
    cout << numConsos << endl;
    numConsonants = 0;

    s = "todayissunny";
    length = s.length();
    numConsos = countConsonants(s, length);
    cout << numConsos << endl;
    numConsonants = 0;

    s = "PathwaytoCSTandonMS";
    length = s.length();
    numConsos = countConsonants(s, length);
    cout << numConsos << endl;
    numConsonants = 0;
}