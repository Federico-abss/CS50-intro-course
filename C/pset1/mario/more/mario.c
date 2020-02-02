#include <cs50.h>
#include <stdio.h>

void pyramid(int n);

// asks for pyramid height, checks the input and then executes the function
int main(void)
{
    int height = 0;
    // asks for height until it is an int comprised between 1 and 8
    do
    {
        height = get_int("Height: ");
    }
    while (!(height >= 1 && height <= 8));
    
    pyramid(height);
}

// prints empty spaces
void space(int l)
{
    for (int k = 0; k < l; k++)
    {
        printf(" ");
    }    
}

// generates a pyramid of hashes n tall and twice as large as the line number (i)
void pyramid(int n)
{
    for (int i = 0; i < n; i++)
    { 
        space(n - i - 1);
        // prints the actual ramp
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        } 
        
        space(2);
        // prints the actual ramp
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        } 
        
        // moves one line down
        printf("\n");
    }
}