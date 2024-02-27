#include <iostream>
using namespace std;

int main()
{
    int diamondLength;
    char letter = 'a';
    char space = ' ';

    cout << "Please place an integer 1-26: ";
    cin >> diamondLength;

    int outsideSpaceLimit = diamondLength - 1;
    int insideSpaceLimit = 0;

    for (int i = 0; i <= (diamondLength * 2); i++)
    {
        for (int j = 0; j <= outsideSpaceLimit; j++)
        {
            cout << space;
        }

        cout << letter;

        for (int j = 1; j < insideSpaceLimit; j++)
        {
            cout << space;
        }

        if (i != 0 && i != ((diamondLength * 2)))
        {
            cout << letter;
        }

        if (i < diamondLength)
        {
            letter++;
            insideSpaceLimit += 2;
            outsideSpaceLimit--;
        }
        else
        {
            letter--;
            insideSpaceLimit -= 2;
            outsideSpaceLimit++;
        }

        cout << endl;
    }
    return 0;
}