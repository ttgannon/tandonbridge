#include <iostream>
#include <string>
using namespace std;

int printMonthCalendar(int numOfDays, int &startingDay);
bool leapYear(int year);
void printYearCalendar(int year, int &startingDay);

int main()
{
    int numOfDays, startingDay, year;
    cout << "Please input the year and the number the year starts on 1-7: " << endl;
    cin >> year >> startingDay;
    printYearCalendar(year, startingDay);

    return 0;
}

int printMonthCalendar(int numOfDays, int &startingDay)
{
    int day = 1;
    cout << "Mon\t"
         << "Tue\t"
         << "Wed\t"
         << "Thr\t"
         << "Fri\t"
         << "Sat\t"
         << "Sun\t" << endl;
    if (startingDay == 8)
    {
        startingDay = 1;
    }

    for (int i = 0; i < startingDay - 1; i++)
    {
        cout << "\t";
    }

    while (day <= numOfDays)
    {
        if (startingDay > 7)
        {
            cout << endl;
            startingDay = 1;
        }

        cout << day << "\t";
        day++;
        startingDay++;
    }

    cout << endl;
    return startingDay;
}

bool leapYear(int year)
{
    if ((year % 4 == 0 && year % 100 > 0) || (year % 4 == 0 && year % 400 == 0))
    {
        return true;
    }
    return false;
}

void printYearCalendar(int year, int &startingDay)
{
    int firstDayOfMonth = startingDay;
    int currMonth = 1;
    string monthName;
    const int MONTHS_IN_YEAR = 12;

    while (currMonth <= MONTHS_IN_YEAR)
    {
        switch (currMonth)
        {
        case 1:
            monthName = "January";
            break;
        case 2:
            monthName = "February";
            break;
        case 3:
            monthName = "March";
            break;
        case 4:
            monthName = "April";
            break;
        case 5:
            monthName = "May";
            break;
        case 6:
            monthName = "June";
            break;
        case 7:
            monthName = "July";
            break;
        case 8:
            monthName = "August";
            break;
        case 9:
            monthName = "September";
            break;
        case 10:
            monthName = "October";
            break;
        case 11:
            monthName = "November";
            break;
        case 12:
            monthName = "December";
            break;
        }

        cout << monthName << ' ' << year << endl;
        if (currMonth == 1 || currMonth == 3 || currMonth == 5 || currMonth == 7 || currMonth == 8 || currMonth == 10 || currMonth == 12)
        {
            printMonthCalendar(31, startingDay);
        }
        else if (currMonth == 2)
        {
            if (leapYear(year))
            {
                printMonthCalendar(29, startingDay);
            }
            else
            {
                printMonthCalendar(28, startingDay);
            }
        }
        else
        {
            printMonthCalendar(30, startingDay);
        }
        currMonth++;
        cout << endl;
    }
}