#include <iostream>
using namespace std;

const double KILOGRAM = 0.453592;
const double METER = 0.0254;

int main()
{
    double weight, height, BMI;

    cout << "Please enter weight (in pounds): ";
    cin >> weight;
    cout << "Please enter height (in inches): ";
    cin >> height;

    weight = weight * KILOGRAM;
    height = height * METER;

    BMI = weight / (height * height);

    if (BMI < 18.5)
    {
        cout << "The weight status is: Underweight" << endl;
    }
    else if (BMI >= 18.5 && BMI < 25)
    {
        cout << "The weight status is: Normal" << endl;
    }
    else if (BMI >= 25 && BMI < 30)
    {
        cout << "The weight status is: Overweight" << endl;
    }
    else if (BMI >= 30)
    {
        cout << "The weight status is: Obese" << endl;
    }

    return 0;
}