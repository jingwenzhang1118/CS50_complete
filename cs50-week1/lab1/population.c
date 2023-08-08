#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int startsize;
    do
    {
        startsize = get_int("Start size: ");
    }
    while (startsize < 9);



    // TODO: Prompt for end size
    int endsize;
    do
    {
        endsize = get_int("End size: ");
    }
    while (endsize < startsize);

    // TODO: Calculate number of years until we reach threshold
    int t;
    for (t = 0; startsize < endsize; t++)
    {
        startsize = startsize + (int)startsize / 3 - (int)startsize / 4;
    }
    // TODO: Print number of years
    printf("Years: %i\n", t);

}


// new values can be assigned to the same variable n = n + 1

