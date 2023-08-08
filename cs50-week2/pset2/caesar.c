#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string key);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    // check whether the command-line argument and the key are both correct
    if (argc == 2 && only_digits(argv[1]))
    {
        // convert string to integer
        int key = atoi(argv[1]);
        string plaintext = get_string("plaintext: ");

        // create a new string that is the same as the plaintext.
        // I need to use strcpy, if I only control the length of the string, ciphertext can be lonter than plaintext.
        // To copy a string, I can't use new_string = old_string
        // In C, strings are implemented as arrays of characters.
        // there is no built-in way to determine the length of a string.
        // This means that when you want to copy a string, you have to manually copy each character one by one.
        // you have to ensure that you don't copy too many characters (which could lead to a buffer overflow).

        char ciphertext[strlen(plaintext)];
        strcpy(ciphertext, plaintext);

        for (int i = 0; i < strlen(plaintext); i++)
        {
            ciphertext[i] = rotate(plaintext[i], key);
        }

        printf("plaintext:  %s\n", plaintext);
        printf("ciphertext: %s\n", ciphertext);
        return 0;
    }

    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

// check whether the key only has digits
bool only_digits(string key)
{
    bool is_valid = true;
    for (int i = 0; i < strlen(key); i++)
    {
        if (isdigit(key[i]) == false && is_valid == true)
        {
            is_valid = false;
        }
    }
    return is_valid;
}



char rotate(char c_plain, int key)
{
    char c_encrypted;

    if (isupper(c_plain)) // if char is uppercase
    {
        // this calculates among capital letters, the new position of the encrypted charater
        // needs to add 65 back as well, so it starts from A again.
        c_encrypted = (c_plain - 65 + key) % 26 + 65;
    }
    else if (islower(c_plain)) // if char is lowercase
        // it is necessary to use else if here, otherwise this condition will be executed as well
    {
        c_encrypted = (c_plain - 97 + key) % 26 + 97;
    }
    else // remain the same for other cases
    {
        c_encrypted = c_plain;
    }

    return c_encrypted;
}



// command-line argument: the key, key should be a positive integer, [0,2^31-26]
// key indicates the distance betweent the cipher and the text. distance = k % 26
// If the key is empty or more arguments
// print "Usage: ./caesar key". and return value 1 immediately
// if any character of the commond-line argument is not a decimal digit,
// print "Usage: ./caesar key". and return value 1 immediately
// output, "plaintext:  ", original message, prompt for plaintext (string)
// output, "ciphertext: ", encryped message
// only rotate alphabetic characters, but not non-alphabetic chars.
// do not change uppercase or lowercase from input to output.
// after outputting the ciphertext, print a new line, and return 0 from main.


//Pseudocode
//1. get the key
//   check whether the command-line argument is valid, continue if valid, give error message if not.
     // if there is only one argument
     // if each char of argv[1] (the key) is a decimal digit, 0-9
     //

//3. input, plaintext. prompt "plaintext: "
//4. get output, ciphertext, print both plaintext and ciphertext
