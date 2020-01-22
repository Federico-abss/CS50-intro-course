#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

// This program hides a message using caesar's cypher
// It takes a positive integer, that we call key, as argument and moves the letters +key positions in the alphabet
int main(int argc, string argv[])
{
    int key = 0;
    // convertes the argument of the function into an int if it exists
    if (argc == 2)
    {
        key = atoi(argv[1]);
    }

    // Takes the module of the key if it's bigger than the alphabet's length
    if (key >= 26)
    {
        key %= 26;
    }

    // validates user input, it must exist and be a positive integer, otherwise prints a message and return one
    if (argc != 2 || key <= 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // gets message to encrypt from user
    string text = get_string("plaintext: ");


    if (argc == 2)
    {
        // loop works for every letter in text
        for (int i = 0, n = strlen(text); i < n; i++)
        {
            // Capital letters
            if (text[i] >= 65 && text[i] <= 90)
            {
                // wraps around if the key is too big
                if (text[i] + key > 90)
                {
                    text[i] -= 26;
                }
                // moves the letter +key values in the aplphabet
                text[i] += key;
            }
            // lower case letters
            else if (text[i] >= 97 && text[i] <= 121)
            {
                // wraps around if the key is too big
                if (text[i] + key > 121)
                {
                    text[i] -= 26;
                }
                // moves the letter +key values in the aplphabet
                text[i] += key;
            }
        }
    }

    // prints out encrypted message
    printf("ciphertext: %s\n", text);
    return 0;
}