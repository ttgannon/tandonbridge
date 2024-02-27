#include <iostream>
using namespace std;

int main()
{
    int firstInteger, secondInteger;

    cout << "Please enter two positive integers, separated by a space: ";
    cin >> firstInteger >> secondInteger;
    cout << firstInteger << " + " << secondInteger << " = " << firstInteger + secondInteger << endl;
    cout << firstInteger << " - " << secondInteger << " = " << firstInteger - secondInteger << endl;
    cout << firstInteger << " * " << secondInteger << " = " << firstInteger * secondInteger << endl;
    cout << firstInteger << " / " << secondInteger << " = " << (double)firstInteger / (double)secondInteger << endl;
    cout << firstInteger << " div " << secondInteger << " = " << firstInteger / secondInteger << endl;
    cout << firstInteger << " mod " << secondInteger << " = " << firstInteger % secondInteger << endl;

    return 0;
}