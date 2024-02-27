#include <iostream>
#include <string>
using namespace std;

const int ARRSIZE = 20;

int arr[20];

bool isPalindrome(string str);

int main()
{
    string str;
    cout << "Please	enter a word: " << endl;

    cin >> str;
    bool strIsPalindrome = isPalindrome(str);

    if (strIsPalindrome)
    {
        cout << str << " is a palindrome " << endl;
    }
    else
    {
        cout << str << " is not a palindrome" << endl;
    }
    return 0;
}

bool isPalindrome(string str)
{
    int oppositeIdx = str.length() - 1;

    for (int i = 0; i <= str.length() - 1; i++)
    {
        if (str[i] != str[oppositeIdx])
        {
            return false;
        }
        oppositeIdx -= 1;
    }
    return true;
}