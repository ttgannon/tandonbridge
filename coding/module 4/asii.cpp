#include <iostream>
#include <cmath>
using namespace std;

int main() {
    char inputChar;
    int asciiValue;

    cout<<"Please enter a character:"<<endl;
    cin>>inputChar;

    asciiValue = inputChar;
    //this causes an implicit cast of the Char into an asciiValue

    cout<<"The ASCII value of "<<inputChar<<" is "<<asciiValue<<endl;

    return 0;
}