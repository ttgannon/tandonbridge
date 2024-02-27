/*

Gavin Arneson
ga1179

*/

#include <iostream>
using namespace std;

int main()
{
    int userInput, numExcellent = 0, numVeryGood = 0, numAverageStudents = 0, numBelowAverage = 0, totalStudents = 0, maxScore = 0, minScore = 100;
    double totalScoreAllStudents = 0;

    cout << "Please enter a sequence of numbers in between 1 and 100, each one in a separate line. End your sequence by typing -1: " << endl;

    while (userInput != -1)
    {
        cin >> userInput;

        if (userInput == -1)
        {
            break;
        }

        if (userInput >= 90)
        {
            numExcellent += 1;
        }
        else if (userInput >= 80 && userInput < 90)
        {
            numVeryGood += 1;
        }
        else if (userInput >= 70 && userInput < 80)
        {
            numAverageStudents += 1;
        }
        else if (userInput < 70)
        {
            numBelowAverage += 1;
        }

        if (userInput >= maxScore)
        {
            maxScore = userInput;
        }

        if (userInput <= minScore)
        {
            minScore = userInput;
        }

        totalStudents += 1;
        totalScoreAllStudents += userInput;
    }
    double overallAverageScore = totalScoreAllStudents / totalStudents;

    cout << "Number of students in the Excellent Category: " << numExcellent << endl;
    cout << "Number of students in the Very Good Category: " << numVeryGood << endl;
    cout << "Number of students in the Average Category: " << numAverageStudents << endl;
    cout << "Number of students in the numBelowAverage Category: " << numBelowAverage << endl;
    cout << "Total number of people in the given sequence of scores: " << totalStudents << endl;
    cout << "Maximum score among the given sequence of scores: " << maxScore << endl;
    cout << "Minimum score among the given sequence of scores: " << minScore << endl;
    cout << "Overall Average score of the given sequence of scores: " << overallAverageScore << endl;

    return 0;
}