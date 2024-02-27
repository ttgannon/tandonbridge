#include <iostream>
using namespace std;

int main()
{
    int firstItemPrice, secondItemPrice;
    double taxRate, basePrice, priceAfterDiscounts, totalPrice;
    char customerClubCard;

    cout << "Enter price of first item: ";
    cin >> firstItemPrice;
    cout << "Enter price of second item: ";
    cin >> secondItemPrice;
    cout << "Does customer have club card? (Y/N): ";
    cin >> customerClubCard;
    cout << "Enter tax rate, e.g. 5.5 for 5.5% tax: ";
    cin >> taxRate;

    basePrice = firstItemPrice + secondItemPrice;

    if (firstItemPrice > secondItemPrice)
    {
        secondItemPrice = secondItemPrice / 2;
    }
    else
    {
        firstItemPrice = firstItemPrice / 2;
    }

    if (customerClubCard == 89 || customerClubCard == 121)
    {
        priceAfterDiscounts = (firstItemPrice + secondItemPrice) * .90;
    }
    else
    {
        priceAfterDiscounts = firstItemPrice + secondItemPrice;
    }

    totalPrice = priceAfterDiscounts * (1 + (taxRate / 100));

    cout << "Base price: " << basePrice << endl;
    cout << "Price after discounts: " << priceAfterDiscounts << endl;
    cout << "Total price: " << totalPrice << endl;

    return 0;
}