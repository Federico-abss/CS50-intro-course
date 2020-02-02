#include <stdio.h>
#include <cs50.h>

// Program asks for user's name and then greets him/her
int main(void)
{
    //get_string allows for user input that gets saved in the var name
    string name = get_string("What is your name?\n");
    //printf just outputs a message to the terminal
    printf("hello, %s\n", name);
}