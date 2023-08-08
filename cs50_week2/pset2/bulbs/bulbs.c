#include <cs50.h>
#include <stdio.h>
#include <string.h>

void print_bulb(int bit);
int* get_binary(char input);
const int BITS_IN_BYTE = 8;

int main(void)
{
    string message = get_string("Message: ");

    // get each character from the string
    for (int i = 0; i < strlen(message); i++)
    {
       //print bulbs, based on the array returned from the get_binary().
       for (int j = 0; j < BITS_IN_BYTE; j++)
        {
            print_bulb(get_binary(message[i])[j]);
        }
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
y
int* get_binary(char input)
{
    // if the return is an array (except string), need to assign specific space to remember it.
    // so static command
    // the return value cannot be easily assigned to another array, need to do it element by element.

    static int binary[BITS_IN_BYTE];

    // convert decimal to binary, divided by 2, if remaining is 0, then assign 0 to that position.
    // if remainig is 1, assign 1 to that position.
    for (int i = 0; i < BITS_IN_BYTE; i++)
    {
        if (input % 2 == 0)
        {
            binary[BITS_IN_BYTE - i - 1] = 0;
        }
        else
        {
            binary[BITS_IN_BYTE - i - 1] = 1;
        }
        input /= 2;
    }
    return binary;
}

// initialize an array: Or you can initialize the elements of the array one by one using a loop or individual assignments:
// get_binary function can also return a string. Then when take out each character from a string, need to notice that
// the value is not 0 or 1, it is 48 or 49. Then it is necessary to adjust the print_bulb() function.
// the comparison should be made not to 0 or 1 anymore.
