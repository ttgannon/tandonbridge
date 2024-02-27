#include <iostream>

using namespace std;

int main()
{
    int numberOfIterations;
    int counter = 0;

    cout << "section a" << endl;
    cout << "Please enter a positive integer: ";
    cin >> numberOfIterations;

    while (counter < numberOfIterations)
    {
        counter += 1;
        cout << 2 * counter << endl;
    }

    cout << "section b" << endl;
    cout << "Please enter a positive integer: ";
    cin >> numberOfIterations;

    for (counter = 1; numberOfIterations >= counter; counter++)
    {
        cout << 2 * counter << endl;
    }

    return 0;
}