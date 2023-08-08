#include <cs50.h>
#include <stdio.h>
#include <math.h>


long get_number(void);
int get_length(long card_number);
int get_sum(long card_number);
bool card_check(int sum);

int main(void)
{
    long card_number = get_number();
    int card_length = get_length(card_number);
    int checksum = get_sum(card_number);
    bool check = card_check(checksum);
    int start_2digits = card_number / (long) pow(10, card_length - 2);
    int start_1digit = card_number / (long) pow(10, card_length - 1);
    printf("No.: %li\n", card_number);
    printf("Card length: %i\n", card_length);
    printf("Sum: %i\n", checksum);
    printf("digits: %i %i \n", start_2digits, start_1digit);

    if (check)
    {
        if (card_length == 15 && (start_2digits == 34 || start_2digits == 37))
        {
            printf("AMEX\n");
        }
        if (card_length == 16 && (start_2digits >= 51 && start_2digits <= 55))
        {
            printf("MASTERCARD\n");
        }
        if ((card_length == 16 || card_length == 13) && start_1digit == 4)
        {
            printf("VISA\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

}

// prompt for input

long get_number(void)
{
    long num;
    do
    {
        num = get_long("Credit card no.: ");
    }
    while (num < 1);
    return num;
}


// check card length
int get_length(long card_number)
{
    int length=0;
    while (card_number != 0)
    {
        // /= means card_number/10
        card_number /= 10;
        length++;
    }
    return length;
}

// get digits and take the sum based on the law

int get_sum(long card_number)
{
    int sum=0;
    int m, n;
    int i=0;
    while (card_number != 0)
    {
        n = card_number % 10; // variable card_number changes after each iteration
        m = n * 2;
        card_number /= 10;
        i++; // count the number of iterations
        if (i % 2 != 0) // situations for odd positions
        {
            sum += n;
        }
        else // situations for even positions
        {
            if (m < 10)
            {
                sum += m;
            }
            else
            {
                sum += m % 10 + m / 10;
            }
        }
    }
    return sum;
}


// check whether the card is valid or not
bool card_check(int sum)
{
    if (sum % 10 != 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}