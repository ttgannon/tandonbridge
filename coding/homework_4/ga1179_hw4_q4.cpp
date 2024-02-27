#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    int userInput, geometricNums, lengthOfSequence, root;
    double geometricMean;

    cout << "section a" << endl;
    cout << "Please enter the length of the sequence: ";
    cin >> lengthOfSequence;

    root = lengthOfSequence;
    geometricNums = 1.0;

    cout << "Please enter your sequence:" << endl;

    while (lengthOfSequence)
    {
        cin >> userInput;
        geometricNums *= userInput;
        lengthOfSequence -= 1;
    }

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(4);

    geometricMean = pow(geometricNums, (1.0 / root));

    cout << "The geometric mean is " << geometricMean << endl;

    cout << "section b" << endl;
    cout << "Please enter a non-empty sequence of positive integers, each one in a separate line. End your sequence by typing -1: " << endl;

    geometricNums = 1;
    root = 0;
    while (userInput != -1)
    {
        cin >> userInput;
        if (userInput != -1)
        {
            geometricNums *= userInput;
            root += 1;
        }
    }

    geometricMean = pow(geometricNums, (1.0 / root));
    cout << "The geometric mean is " << geometricMean << endl;

    return 0;
}