#include <iostream>
#include <string>

using namespace std;

int main()
{
    int graduationYear, currentYear, studentStatus;
    string studentName;

    cout << "Please enter your name: ";
    cin >> studentName;
    cout << "Please enter your graduation year: ";
    cin >> graduationYear;
    cout << "Please enter your current year: ";
    cin >> currentYear;

    studentStatus = graduationYear - currentYear;

    switch (studentStatus)
    {
    case 0:
        cout << studentName << ", you graduated" << endl;
        break;
    case 1:
        cout << studentName << ", you are a "
             << "Senior" << endl;
        break;
    case 2:
        cout << studentName << ", you are a "
             << "Junior" << endl;
        break;
    case 3:
        cout << studentName << ", you are a "
             << "Sophomore" << endl;
        break;
    case 4:
        cout << studentName << ", you are a "
             << "Freshman" << endl;
        break;
    default:
        cout << studentName << ", you are not in college yet" << endl;
        break;
    }

    return 0;
}