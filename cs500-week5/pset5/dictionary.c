// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;
void unloader(node *hashtable);

// TODO: Choose number of buckets in hash table
const unsigned int N = 676;

// Hash table
node *table[N];

// Number of loaded words from the dictionary;
int dictionary_count = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // hash word to obtain a hash value;
    // access linked list at that index in the hash table;
    // check the list, looking for the word;
    int index = hash(word);
    if (table[index] == NULL)
    {
        return false;
    }

    else
    {
        for (node *cursor = table[index]; cursor != NULL; cursor = cursor->next)
        {
            if (strcasecmp(cursor->word, word) == 0)
            {
                return true;
            }
        }
        return false;
    }
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // relying on the first two letters
    if (strlen(word) == 1)
    {
        return (toupper(word[0]) - 'A') * 26;
    }

    else if (isalpha(word[0]) && isalpha(word[1]))
    {
        return (toupper(word[0]) - 'A') * 26 + toupper(word[1]) - 'A';
    }

    else if (isalpha(word[0]) && word[1] == '\'')
    {
        return (toupper(word[0]) - 'A') * 26 + toupper(word[2]) - 'A';
    }

    else if (word[0] == '\'' && isalpha(word[1]))
    {
        return (toupper(word[1]) - 'A') * 26 + toupper(word[2]) - 'A';
    }

    else
    {
        return N;
    }
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // open the dictionary file
    // read strings from the file;
    // create a new node for the word;
    // hash word to obtain a hash value
    // insert node into hash table at that location
    FILE *infile = fopen(dictionary, "r");
    if (!infile)
    {
        printf("Error opening file!\n");
        return false;
    }

    char word[LENGTH]; // need to set the name of the strings before reading the file;
    while (fscanf(infile, "%s", word) == 1) // fscanf() returns 1 if it reads successfully.
    {
        node *new = malloc(sizeof(node));
        if (new == NULL)
        {
            printf("Fail reading words.\n");
            fclose(infile);
            return false;
        }
        strcpy(new->word, word);
        dictionary_count++;
        int index = hash(word);
        new->next = table[index];
        table[index] = new; // add the words to the front of that hash table.
    }
    fclose(infile);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return dictionary_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        unloader(table[i]);
    }
    return true;
}



void unloader(node *hashtable)
{
    node *ptr = hashtable;
    while (ptr != NULL)
    {
        node *tmp = ptr->next;
        free(ptr);
        ptr = tmp;
    }
}