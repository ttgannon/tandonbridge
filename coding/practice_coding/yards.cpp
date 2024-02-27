#include <iostream>
using namespace std;

int main()
{
    // initialize all variables to be 1; flag is -1, so adding -1 will negate the -1 start
    int inchesTraveled = 1, userInput = 1, dayNumber = 1;
    int yards = 0, feet = 0, inches = 0;

    while (userInput != -1)
    {
        cout << "Enter the number of inches the snail traveled on day #" << dayNumber << ", or type -1 if they reached their destination:" << endl;
        cin >> userInput;

        if (userInput == -1)
        {
            dayNumber -= 1;
        }
        else
        {
            dayNumber += 1;
        }

        inchesTraveled += userInput;
    }

    inches = inchesTraveled;

    if (inches / 36)
    {
        yards += inchesTraveled / 36;
    }

    inches = inches % 36;

    if (inches / 12)
    {
        feet += inches / 12;
    }

    inches = inches % 12;

    cout << "In " << dayNumber << " days, the snail traveled " << yards << " yards, " << feet << " feet "
         << "and " << inches << "inches." << endl;

    return 0;
}