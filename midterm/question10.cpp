#include <iostream>
#include <string>
#include "Stack.h" // assuming the stack is implemented accord to specs in the book

using namespace std;

void vowels(string str)
{
    Stack<char> vowels; // to hold the vowels
    int numVowels = 0;

    int length = str.length();

    // Go through each character in the string and push vowels into the stack
    for (int i = 0; i < length; i++)
    {
        // If the character is a vowel, push it onto the vowels stack and increment the count of vowels
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
        {
            vowels.push(str[i]);
            numVowels++;
        }
    }

    // Print the contents of the stack
    while (!vowels.isEmpty())
    {
        cout << vowels.peek() << endl;
        vowels.pop();
    }

    cout << "The number of vowels is " << numVowels << endl;
}

int main()
{
    vowels("the blah");
    return 0;
}
