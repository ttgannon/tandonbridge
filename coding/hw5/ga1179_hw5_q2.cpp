#include <iostream>
using namespace std;

void printShiftedTriangle(int n, int m, char symbol);
void printPineTree(int n, char symbol);

int main()
{
    int a, b;
    char symbol;
    cout << "Please enter two positive integers separated by a space and a symbol: " << endl;
    cin >> a >> b >> symbol;

    printShiftedTriangle(a, b, symbol);

    cout << "Please enter one positive integer separated by a space and a symbol: " << endl;
    cin >> a >> symbol;
    printPineTree(a, symbol);
    return 0;
}

void printShiftedTriangle(int n, int m, char symbol)
{
    int line = 0, spaces = n - 1, numChars = 1;

    while (line < n)
    {
        for (int i = 0; i < m; i++)
        {
            cout << ' ';
        }

        for (int i = 0; i < spaces; i++)
        {
            cout << ' ';
        }

        for (int i = 0; i < numChars; i++)
        {
            cout << symbol;
        }
        cout << endl;
        numChars += 2;
        spaces--;
        line++;
    }
}

void printPineTree(int n, char symbol)
{
    int triangle = 0, lengthOfTriangle = 2, line = 0;

    while (triangle < n)
    {
        int numSpaces = n, numChars = 1, line = 0;
        while (line < lengthOfTriangle)
        {
            for (int i = 0; i < numSpaces; i++)
            {
                cout << ' ';
            }

            for (int i = 0; i < numChars; i++)
            {
                cout << symbol;
            }
            cout << endl;
            numChars += 2;
            numSpaces--;
            line++;
        }
        lengthOfTriangle++;
        triangle++;
    }
}