#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    // replace the last char of the string, and covert it to a number
    int num = 0;
    while (strlen(input) > 0)
    {
        // convert the last charater to number
        num = input[strlen(input)-1] - 48;
        // remove the last char of the string
        input[strlen(input) - 1] = '\0';
        // value is the current value plus 10 times the integer value of the new shortened string
        num = num + 10 * convert(input);
    }
    return num;

}