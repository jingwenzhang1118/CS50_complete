#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Check for command line args
    if (argc != 2)
    {
        printf("Usage: ./read infile\n");
        return 1;
    }

    // Create buffer to read into
    char buffer[7];

    // Create array to store plate numbers
    char *plates[8];

    FILE *infile = fopen(argv[1], "r");

    int idx = 0;

    while (fread(buffer, 1, 7, infile) == 7)
    {
        // Replace '\n' with '\0'
        buffer[6] = '\0';

        // Save plate number in array
        plates[idx] = malloc(strlen(buffer)); // dynamically assign pointer to the string
        strcpy(plates[idx], buffer);

        /*for (int i = 0; i < strlen(buffer); i++)
        {
            plates[idx][i] = buffer[i];
        }*/
        // plates[idx] = buffer;  This command only copies the address but not the value.
        // When the value of buffer changes, the value of plates also changes, because they
        // share the value at the same address.
        idx++;
    }

    for (int i = 0; i < 8; i++)
    {
        printf("%s\n", plates[i]);
        free(plates[i]); // need to free the memory used for the string
    }

    fclose(infile); // when using fopen, fclose should be paired as well to prevent leak memory.
}
