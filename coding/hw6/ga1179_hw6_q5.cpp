#include <iostream>
using namespace std;

int main()
{
    string firstName, middleName, lastName;
    cout << "Please	enter your name:" << endl;
    cin >> firstName >> middleName >> lastName;

    middleName = middleName[0];

    cout << lastName << ", " << firstName << ' ' << middleName << '.' << endl;

    return 0;
}
