#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// This program calculates the difficulty of a body of text by assigning it a grade
int main(void)
{
    // gets user input about the text
    string text = get_string("Text: \n");

    float letters = 0;
    float words = 0;
    float sentence = 0;


    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // counts the letters using ascii code
        if (text[i] >= 65 && text[i] <= 122)
        {
            letters++;
        }
        // counts the words by reading spaces
        else if (text[i] == 32 && (text[i - 1] != 33 && text[i - 1] != 46 && text[i - 1] != 63))
        {
            words++;
        }
        // counts the sentences by finding dots, exclamation marks and interrogatives
        else if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            sentence++;
            words++;
        }
    }

    float L = letters * 100 / words;
    float S = sentence * 100 / words;
    // Coleman-Liau index is computed using the formula
    float index = round(0.0588 * L - 0.296 * S - 15.8);

    // Finally outputs the result to the user
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int) index);
    }
}
