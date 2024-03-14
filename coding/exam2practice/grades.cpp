#include <iostream>
using namespace std;

int findHighestGrade(vector<int> &studentIDs, vector<int> &studentGrades);
int compareGrades(int studentGrade, int highestGrade);
void printStudentsWithHighestGrade(int highestGrade, vector<int> studentIDs, vector<int> studentGrades);

int main()
{
    vector<int> studentIDs;
    vector<int> studentGrades;

    cout << "Please enter a non-empty sequence of lines.\n"
            "Each line should have a student ID and"
            "their grade(0 - 100),"
            "separated by a space.\n"
            "To indicate the end of the input, "
            "enter - 1 as a student ID : "
         << endl;

    int highestGrade = findHighestGrade(studentIDs, studentGrades);

    printStudentsWithHighestGrade(highestGrade, studentIDs, studentGrades);

    return 0;
}

int findHighestGrade(vector<int> &studentIDs, vector<int> &studentGrades)
{
    int studentGrade, studentID;
    int highestGrade = 0;

    while (true)
    {
        cin >> studentID;
        if (studentID == -1)
        {
            break;
        }
        studentIDs.push_back(studentID);
        cin >> studentGrade;
        studentGrades.push_back(studentGrade);
        highestGrade = compareGrades(studentGrade, highestGrade);
    }
    return highestGrade;
}

int compareGrades(int studentGrade, int highestGrade)
{
    if (studentGrade > highestGrade)
        return studentGrade;
    else
        return highestGrade;
}

void printStudentsWithHighestGrade(int highestGrade, vector<int> studentIDs, vector<int> studentGrades)
{
    cout << "The highest grade is " << highestGrade << ".\n";
    cout << "The students with grade " << highestGrade << " are:";

    for (int i = 0; i < studentIDs.size(); i++)
    {
        if (studentGrades[i] == highestGrade)
            cout << ' ' << studentIDs[i];
        if (i == studentIDs.size() - 1)
            cout << '.' << endl;
    }
}