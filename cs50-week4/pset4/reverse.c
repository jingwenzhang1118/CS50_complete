#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 3)
    {
        printf("Usage: input.wav output.wav\n");
        return 1;
    }

    // Open input file for reading
    char *infile = argv[1];
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 1;
    }


    // Read header into an array
    WAVHEADER header;
    fread(&header, sizeof(header), 1, inptr);
    int data_start = ftell(inptr);

    // Use check_format to ensure WAV format
    if (check_format(header) == 1)
    {
        printf("Wrong Format.\n");
        fclose(inptr);
        return 1;
    }

    // Open output file for writing
    char *outfile = argv[2];
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        printf("Could not create %s.\n", outfile);
        fclose(outptr);
        fclose(inptr);
        return 1;
    }


    // Write header to file
    fwrite(&header, sizeof(WAVHEADER), 1, outptr);


    // Use get_block_size to calculate size of block
    int block_size = get_block_size(header);

    // Write reversed audio to file
    //fseek(file*, offset, SEEK_END/SEEK_CUR/SEEK_SET) puts the pointer to a position defined by (SEEK_? + offset value)
    // the offset value should be equal to the -block_size, so the starting point is the last block
    // start copy from the last block, reverse
    fseek(inptr, -block_size, SEEK_END);
    // long int len_infile = ftell(inptr) - data_start;
    // ftell(file*) returns the length (bytes) from the current position to the start of the file.

    WORD buffer[block_size];
    /*    Only colpy the file
    while(fread(&buffer, block_size, 1, inptr)==1)
    {
        fwrite(&buffer, block_size, 1, outptr);
    }
    */

    while (fread(&buffer, block_size, 1, inptr) == 1 && ftell(inptr) >= data_start + block_size)
    {
        fwrite(&buffer, block_size, 1, outptr);
        fseek(inptr, -block_size * 2, SEEK_CUR); // move backward by 2 block_size
    }


    fclose(inptr);
    fclose(outptr);
}



int check_format(WAVHEADER header)
{
    if (header.format[0] == 'W' && header.format[1] == 'A' && header.format[2] == 'V' \
        && header.format[3] == 'E')

    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int get_block_size(WAVHEADER header)
{
    int block_size = header.numChannels * (header.bitsPerSample / 8);
    return block_size;
}