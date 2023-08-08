#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int key_length = 26;
bool is_alpha_unique(string key);
char rotate(char c_plain, string key);

int main(int argc, string argv[])
{
    // check if there is a single command-line argument and the length of the argument is right
    if (argc == 2 && strlen(argv[1]) == key_length)
    {
        if (is_alpha_unique(argv[1])) // check if the argument is valid
        {

            string plaintext = get_string("Plaintext: "); // ask for user's input
            char ciphertext[strlen(plaintext)];
            strcpy(ciphertext, plaintext); // a copy of the input

            for (int i = 0; i < strlen(plaintext); i++)
            {
                ciphertext[i] = rotate(plaintext[i], argv[1]); // encrypt the input
            }

            printf("plaintext:  %s\n", plaintext);
            printf("ciphertext: %s\n", ciphertext);

        }

        else // if the argument is not valid
        {
            printf("The key must contain 26 unique alphabets.\n");
            return 1;
        }

    }

    else if (argc == 2) // if there is one argument, but the length is not right.
    {
        printf("The key must contain 26 unique alphabets.\n");
        return 1;
    }

    else // when there are no or more than one arguments in the command line.
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
}



// check if the key only has alphabets and no duplicates;
bool is_alpha_unique(string key)
{
    bool is_valid = true;  // this considers both alphabets and duplicates
    bool is_alpha = true;

    // check if only contains alphabets
    for (int i = 0; i < strlen(key); i++)
    {
        if (isalpha(key[i]) == false && is_alpha == true)
        {
            is_alpha = false;
        }
    }

    // check if they are unique
    if (is_alpha)
    {
        for (int j = 0; j < strlen(key); j++)
        {
            for (int k = j + 1; k < strlen(key); k++)
            {
                if (toupper(key[j]) == toupper(key[k]) && is_valid == true)
                // toupper is important here, because a is not equal to A.
                {
                    is_valid = false;
                }
            }
        }
    }

    else
    {
        is_valid = false;
    }
    return is_valid;
}


// encrypt characters in the key
char rotate(char c_plain, string key)
{
    char c_encrypt;

    int pos = toupper(c_plain) - 65; // find the position of the letter in normal alphbetic order.
    // and the char of key at the corresponding position shoudl be used for the encrypted char.
    if (isupper(c_plain))
    {
        c_encrypt = toupper(key[pos]); // message is case sensitive, but the key is not.
    }
    else if (islower(c_plain))
    {
        c_encrypt = tolower(key[pos]);
    }
    else
    {
        c_encrypt = c_plain; // other symbols remain.
    }
    return c_encrypt;
}


//1 check whether there is a single command-line argument
// if it has 0 or more than 1 arguments, print error message, and return 1 in the main.
// "Usage: ./substitution key"
//2. whether argv[1] has 26 alphabetical characters, and no duplicates!
// if wrong, "Wrong key: 26 unique alphabets"; return 1 in the main.
//3. plaintext, get_string
//4. ciphertext, print a new line after outputting the ciphertext, return 0 in main.
