#include <iostream>
using namespace std;

int main()
{
    int userInput;
    int numStars, numSpacesBetween, numSpacesBefore;

    cout << "Please enter an integer, greater or equal to 2:" << endl;
    cin >> userInput;

    numStars = ((userInput * 2) - 1);
    numSpacesBetween = numStars - 4;

    for (int i = 0; i < userInput; i++)
    {
        if (i == 0)
        {
            while (numStars)
            {
                cout << '*';
                numStars--;
            }
            cout << endl;
        }
        else
        {
            numSpacesBefore = i;
            for (int j = 0; j < numSpacesBefore; j++)
            {
                cout << ' ';
            }

            cout << '*';

            for (int k = 0; k < numSpacesBetween; k++)
            {
                cout << ' ';
            }
            numSpacesBetween -= 2;

            if (i != userInput - 1)
            {
                cout << '*' << endl;
            }
        }
    }
    cout << endl;
    return 0;
}