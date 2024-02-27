#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    const int TOTAL_GUESSES = 5;
    int guessesRemaining, secretNumber, highestGuess = 100, smallestGuess = 1, userInput = 1;

    srand(time(0));
    secretNumber = (rand() % 100) + 1;
    guessesRemaining = 5;

    cout << "I thought of a number between 1 and 100! Try to guess it." << endl;

    while (guessesRemaining > 0 && userInput != secretNumber)
    {
        cout << "Range: [" << smallestGuess << ", " << highestGuess << "], Number of guesses left: " << guessesRemaining << "\nYour guess: ";
        cin >> userInput;
        guessesRemaining -= 1;

        if (userInput == secretNumber)
        {
            int numGuesses = TOTAL_GUESSES - guessesRemaining;
            cout << "Congrats! You guessed my number in " << TOTAL_GUESSES - guessesRemaining << " guesses." << endl;
            break;
        }

        if (guessesRemaining == 0)
        {
            cout << "Out of guesses! My number is " << secretNumber << endl;
            break;
        }

        if (userInput > secretNumber)
        {
            cout << "Wrong! My number is smaller." << endl;
            highestGuess = userInput;
        }
        else
        {
            cout << "Wrong! My number is bigger." << endl;
            smallestGuess = userInput;
        }
    }

    return 0;
}
