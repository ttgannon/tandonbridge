#include <iostream>
#include <string>
using namespace std;

void printArray(string *array, int arrSize);

// diff bw returning an arr of strings like string?
string *createWordsArray(string sentence, int &outWordsArrSize);

int main()
{
    string sentence = "You can do it";
    int outWordsArrSize = 1;

    string *sentenceArrayPtr = createWordsArray(sentence, outWordsArrSize);
    printArray(sentenceArrayPtr, outWordsArrSize);

    delete[] sentenceArrayPtr;

    return 0;
}

void printArray(string *array, int arrSize)
{
    int i;

    for (i = 0; i < arrSize; i++)
    {
        cout << array[i] << ' ';
    }
    cout << endl;
}

string *createWordsArray(string sentence, int &outWordsArrSize)
{
    for (int i = 0; i < sentence.length(); i++)
    {
        if (sentence[i] == ' ')
            outWordsArrSize++;
    }

    string *newArrayPtr = new string[outWordsArrSize];

    int idx1 = 0, newArrayPtrIdx = 0;
    for (int i = 0; i <= sentence.length(); i++)
    {
        if (sentence[i] == ' ' || i == sentence.length())
        {
            newArrayPtr[newArrayPtrIdx] = sentence.substr(idx1, i - idx1);
            idx1 = i + 1;
            newArrayPtrIdx++;
        }
    }

    return newArrayPtr;
}