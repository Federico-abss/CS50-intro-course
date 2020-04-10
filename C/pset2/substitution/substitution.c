#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

// This program hides a message received from the user using an alternative alphabet
// It takes a 26 digits string of unique letters and reassigns the alphabet using it as a key
int main(int argc, string argv[])
{
    // validates user input, it must exist and be a single string of 26 letters
    if (argc != 2 || strlen(argv[1]) != 26)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    char newAlphabet[26];
    char key[26];

    // assigns the new values to the array newAlphabet and validates the key
    for (int i = 0; i < 26; i++)
    {
        key[i] = toupper(argv[1][i]);
        if (key[i] >= 65 && key[i] <= 90)
        {
            newAlphabet[i] = 65 + i - key[i];
        }
        // Returns an error if the key has non alphabetical characters
        else
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }

        // This loop checks if the current letter of the key is a duplicate
        for (int j = 0; j < i; j++)
        {
            if (key[i] == key[j])
            {
                printf("Usage: ./substitution key\n");
                return 1;
            }
        }
    }

    string text = get_string("plaintext: ");

    // converts the message using the new alphabet
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] >= 65 && text[i] <= 90)
        {
            text[i] = text[i] - newAlphabet[text[i] - 65];
        }
        else if (text[i] >= 97 && text[i] <= 122)
        {
            text[i] = text[i] - newAlphabet[text[i] - 97];
        }
    }

    // prints out encrypted message
    printf("ciphertext: %s\n", text);
    return 0;
}
