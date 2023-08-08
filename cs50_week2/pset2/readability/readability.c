#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// function's prototype
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

// get the string from the user
int main(void)
{

    string input = get_string("Text: ");

    int num_letters = count_letters(input);
    int num_words = count_words(input);
    int num_sentences = count_sentences(input);

// Division only returns an integer if both variables are integers.
// Need to change variables to float variables first.

    int index = round(0.0588 * (float)num_letters / num_words * 100 \
    - 0.296 * (float)num_sentences / num_words * 100 - 15.8);

// print output "Grade X", rounded to the nearest integer, using the formula
// index = 0.0588 * L - 0.296 * S - 15.8
// if index >= 16, print Grade 16+
// if index < 1, print Before Grade 1.
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 1 && index < 16)
    {
        printf("Grade %i\n", index);
    }
    else
    {
        printf("Grade 16+\n");
    }
}

// count the number of letters of the text

int count_letters(string text)
{
    int num_letters = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (islower(text[i]))
        {
            num_letters++;
        }
        else if (isupper(text[i]))
        {
            num_letters++;
        }
    }
    return num_letters;
}



/* Alternative command, without using ctype.h
int count_letters(string text)
{
    int num_letters = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] >= 'A' && text[i] <= 'Z')
        {
            num_letters++;
        }
        else if (text[i] >= 'a' && text[i] <= 'z')
        {
            num_letters++;
        }
    }
    return num_letters;
}
*/

// count the number of words, separated by space? Count the number of spaces, plus 1
// Note that, need to use ' ' for char, "" for strings.

int count_words(string text)
{
    int num_words = 1; // This starts from 1 because the last word is not separated by space, so 2 spaces mean three words.
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == ' ')
        {
            num_words++;
        }
    }
    return num_words;
}

// count the number of sentences, separated by ./!/?

int count_sentences(string text)
{
    int num_sentences = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            num_sentences++;
        }
    }
    return num_sentences;
}









