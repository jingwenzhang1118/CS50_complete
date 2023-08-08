#include <cs50.h>
#include <stdio.h>


bool prime(int number);

int main(void)
{
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

bool prime(int number)
{
    // TODO
    // 1 is not a prime number
    if (number < 2)
    {
        return false;
    }
    // All even numbers are not prime number
    if (number > 2 & number % 2 == 0)
    {
        return false;
    }
    // Check prime numbers for odd numbers by dividing a series of numbers with an interval of 2
    for (int i = 3; i < number; i += 2)
    {
        if (number % i == 0)
        {
            return false;
        }
    }
    return true;
}
