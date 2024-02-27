#include <iostream>
#include <string>

using namespace std;

int main()
{
    int lengthOfSequence, numberOfStars, numberOfSpaces, spacesTracker, userInput;
    string lineOutput;

    cout << "Please enter a number: ";
    cin >> lengthOfSequence;
    int totalWhiteSpace = lengthOfSequence + (lengthOfSequence - 1);
    userInput = lengthOfSequence;

    while (lengthOfSequence > 0)
    {
        string lineOutput;
        numberOfStars = lengthOfSequence + (lengthOfSequence - 1);
        numberOfSpaces = totalWhiteSpace - numberOfStars;

        if (numberOfSpaces > 0)
        {
            for (spacesTracker = 0; spacesTracker < numberOfSpaces / 2; spacesTracker++)
            {
                lineOutput += ' ';
            }
        }

        while (numberOfStars > 0)
        {
            lineOutput += '*';
            numberOfStars -= 1;
        }

        if (numberOfSpaces > 0)
        {
            while (spacesTracker < numberOfSpaces)
            {
                lineOutput += ' ';
                spacesTracker += 1;
            }
        }

        cout << lineOutput << endl;
        lengthOfSequence -= 1;
    }
    lengthOfSequence = 1;
    totalWhiteSpace = userInput + (userInput - 1);

    while (lengthOfSequence <= userInput)
    {
        string lineOutput;
        numberOfStars = lengthOfSequence + (lengthOfSequence - 1);
        numberOfSpaces = totalWhiteSpace - numberOfStars;

        if (numberOfSpaces > 0)
        {
            for (spacesTracker = 0; spacesTracker < numberOfSpaces / 2; spacesTracker++)
            {
                lineOutput += ' ';
            }
        }

        while (numberOfStars > 0)
        {
            lineOutput += '*';
            numberOfStars -= 1;
        }

        if (numberOfSpaces > 0)
        {
            while (spacesTracker < numberOfSpaces)
            {
                lineOutput += ' ';
                spacesTracker += 1;
            }
        }

        cout << lineOutput << endl;
        lengthOfSequence += 1;
    }

    return 0;
}