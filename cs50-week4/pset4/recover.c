#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

const int BLOCK_SIZE = 512;
const int FILENAME_LEN = 8;

int main(int argc, char *argv[])
{

    // check argument
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    char *infile = argv[1];

    // open the file
    FILE *inptr = fopen(infile, "r"); // assign a pointer for the input file
    if (inptr == NULL)
    {
        printf("Invalid file\n");
        return 1;
    }


    BYTE buffer[BLOCK_SIZE];
    int idx = 0; // count the number of images
    char filename[FILENAME_LEN]; //file name "###.jpg", 8 characters
    FILE *outptr = NULL; // assign a pointer to the output file

    // read by blocks into a buffer, fread starts from where it lefts.
    while (fread(buffer, sizeof(BYTE), BLOCK_SIZE, inptr) == BLOCK_SIZE)
    {
        // if start of a new jpeg file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff & (buffer[3] & 0xf0) == 0xe0)
        {
            // if previous jpeg is found, it should be closed.
            if (idx != 0) //if there is ongoing writing jpeg, close it first.
            {
                fclose(outptr);
            }
            sprintf(filename, "%03i.jpg", idx); // name the file.
            outptr = fopen(filename, "w"); // open the output file.
            idx++;
        }
        if (idx != 0) // this cannot be "else", because the memory (card.raw) may have other data
        // before a jpeg is found. Then, this code will be activated when idx==0, but no file has been opened.
        {
            fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, outptr); // write the file
        }
    }

    fclose(inptr);
    fclose(outptr);
    return 0;
}