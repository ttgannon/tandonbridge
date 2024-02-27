#include <iostream>
using namespace std;

const int FLOOR_ROUND = 1;
const int CEILING_ROUND = 2;
const int ROUND = 3;

int main()
{
    double userRealNumber, inputRemainder;
    int roundingMethod;

    cout << "Please enter a real number: " << endl;
    cin >> userRealNumber;
    cout << "Choose your rounding method:\n 1. Floor round \n 2. Ceiling round \n 3. Round to the nearest whole number " << endl;
    cin >> roundingMethod;

    switch (roundingMethod)
    {
    case FLOOR_ROUND:
        userRealNumber = (int)userRealNumber;
        break;
    case CEILING_ROUND:
        userRealNumber = (int)userRealNumber + 1;
        break;
    case ROUND:
        inputRemainder = userRealNumber - (int)userRealNumber;
        if (inputRemainder < .5)
        {
            userRealNumber = (int)userRealNumber;
        }
        else
        {
            userRealNumber = (int)userRealNumber + 1;
        }
        break;
    }
    cout << userRealNumber << endl;

    return 0;
}