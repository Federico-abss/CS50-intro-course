#include <cs50.h>
#include <stdio.h>
#include <math.h>

// asks for card number, checks validity and says the brand
int main(void)
{
    // List of possible cards first digits for Mastercard, Visa and American Express, used later for validation
    int AE1 = 34;  
    int AE2 = 37;  
    int MC1 = 51;  
    int MC2 = 52;  
    int MC3 = 53;  
    int MC4 = 54;  
    int MC5 = 55;  
    int Visa = 4;
    int count;
    long card = 0;
    int brand = 0; 
   
    // asks for the card number and memorizes input
    card = get_long("Card n*: ");
    long temp = card;
    count = 0;
    // counts number of digits
    while (temp > 0)
    {
        count++;
        temp /= 10;
    }
    // if number of digits is appropriate it saves validation
    // different validation for every brand
    if (count == 13)
    {
        int temp13 = card / 1000000000000;          
        if (temp13 == Visa)
        {
            brand = 1;
        }
    }
    else if (count == 15)
    {
        int temp15 = card / 10000000000000;
        if (temp15 == AE1 || temp15 == AE2)
        {
            brand = 2;
        }
    }
    else if (count == 16)
    {
        int temp16MC = card / 100000000000000;
        int temp16V = card / 1000000000000000;
        if (temp16MC == MC1 || temp16MC == MC2 || temp16MC == MC3 || temp16MC == MC4 || temp16MC == MC5)
        {
            brand = 3;
        }
        else if (temp16V == Visa)
        {
            brand = 1;
        }
    }
    
    // if the number of digits is correct it now checks that luhn's Algorithm is respected, otherwise returns INVALID
    if (brand != 0)
    {
        int tempx;
        int last = 0;
        int secToLast = 0;
        
        // it picks odd and even numbers starting from the end and sums them 
        while (card > 0)
        {
            last += card % 10;
            
            // eliminates last digit so we can access the first even number from the end
            card /= 10;
            
            // as for the algorithm we take the even number * 2
            tempx = (card % 10) * 2;
            
            // if the even number * 2 is 10 or bigger it takes the single digits and adds them the rest of the odds
            if (tempx > 9)
            {
                secToLast += tempx % 10 + tempx / 10;
            }
            // if the even number * 2 is 9 or less it just adds it to the others
            else
            {
                secToLast += tempx;
            }
            
            // eliminates last digit again to go back to odd numbers
            card /= 10;
        }
        // validates the Algorithm and then prints the brand
        if ((last + secToLast) % 10 == 0)
        {
            if (brand == 1)
            {        
                printf("VISA\n");
            }
            if (brand == 2)
            {        
                printf("AMEX\n");
            }
            if (brand == 3)
            {        
                printf("MASTERCARD\n");
            }
        }
        // if it is not validate it prints invalid
        else 
        {
            printf("INVALID\n");
        }
    }
    // again it prints invalid if the digits number was not correct in the first place
    else
    {
        printf("INVALID\n");
    }
}