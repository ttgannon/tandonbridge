#include <iostream>
#include <string>
using namespace std;

int main()
{
    string day;
    int durationCall, hours24, minutes24;
    double cost;
    char temp;

    cout << "Please enter the time the call started: ";
    cin >> hours24 >> temp >> minutes24;
    cout << "Please enter the day of the week of the call: ";
    cin >> day;
    cout << "Please enter the duration of the call: ";
    cin >> durationCall;

    if (day == "Sa" || day == "Su")
    {
        cost = durationCall * 0.15;
    }
    else
    {
        if (hours24 >= 8 && hours24 < 18)
        {
            cost = durationCall * 0.4;
        }
        else
        {
            cost = durationCall * 0.25;
        }
    }

    cout << cost << endl;
    return 0;
}