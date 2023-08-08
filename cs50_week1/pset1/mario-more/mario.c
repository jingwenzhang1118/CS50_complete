#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // get the height from the user
    int n;
    do
    {
        n = get_int("What should be the pyramid's height? ");
    }
    while (n < 1 || n > 8);


    for (int i = 0; i < n; i++)
    {
        // right-aligned bricks
        for (int k = 0; k < n - i - 1; k++)
        {
            printf(" ");
        }
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }

        // spaces in between
        printf("  ");

        // left-aligned bricks
        for (int m = 0; m < i + 1; m++)
        {
            printf("#");
        }

        // change lines
        printf("\n");
    }

}

// always define a variable's data type