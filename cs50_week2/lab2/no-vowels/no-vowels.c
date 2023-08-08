// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

string replace(string text);

int main(int argc, string argv[])
{
    // switch(expression) is an alternative to if statements, expression is evaluated once
    // It is then compared to the value of each case.
    switch (argc)
    {
        // print the converted word if there is one command-line arguments
        case 2: // it has two arguments, the first is the name of the program, the 2nd is the string
            printf("%s\n", replace(argv[1]));
            break;

        // print error if the program has no command-line arguments or more than one command-line argument
        // print an error message + return from main a value of 1 immediately;
        default:
            printf("Check command-line argument\n");
            return 1;
    }
}


string replace(string text)
{
    for (int i = 0; i < strlen(text); i++)
    {
        switch (tolower(text[i]))
        {
            case 'a':
                text[i] = '6'; // the single-quote is needed to assign this to a string.
                break;

            case 'e':
                text[i] = '3';
                break;

            case 'i':
                text[i] = '1';
                break;

            case 'o':
                text[i] = '0';
                break;
        }
    }
    return text;
}