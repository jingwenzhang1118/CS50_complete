#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // prompt for the user to input height
    int n;
    do
    {
        n = get_int("What should be the pyramid's height? ");
    }
    while (n < 1 || n > 8);


    // left-aligned bricks, more than one loops can be nested in a bigger loop
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < n - i - 1; k++)
        {
            //print spaces before the hashtag
            printf(" ");
        }
        for (int j = 0; j < i + 1; j++)
        {
            //print hashtags
            printf("#");
        }
        printf("\n");
    }


}