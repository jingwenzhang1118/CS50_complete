// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>


bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    // set boollean variables to false at the beginning
    bool lowercase = false;
    bool uppercase = false;
    bool number = false;
    bool symbol = false;

    for (int i = 0; i < strlen(password); i++)
    {
        // at least one symbol
        if (symbol == false)
        {
            if ((password[i] >= 32 && password[i] <= 47) || \
            (password[i] >= 58 && password[i] <= 64) || \
            (password[i] >= 91 && password[i] <= 96) || \
            (password[i] >= 123 && password[i] <= 126))
            {
                symbol = true;
            }
        }

        // at least one upper case
        if (uppercase == false)
        {
            if (password[i] >= 65 && password[i] <= 90)
            {
                uppercase = true;
            }
        }

        // at least one lower case
        if (lowercase == false)
        {
            if (password[i] >= 97 && password[i] <= 122)
            {
                lowercase = true;
            }
        }

        // at least one number
        if (number == false)
        {
            if (password[i] >= 48 && password[i] <= 57)
            {
                number = true;
            }
        }
    }

    // check whether all conditions are met
    if (lowercase && uppercase && number && symbol)
    {
        return true;
    }
    else
    {
        return false;
    }
}






