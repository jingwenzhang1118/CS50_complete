#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing

    // Change all black pixels to a color of your choosing
    // loop throught the pixels
    // adjust the color of the black pixels
    // black pixels have value, all 0
    // change black to orange red, r=255, g=69, b=0.

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (image[i][j].rgbtRed == 0)
            {
                image[i][j].rgbtRed = 255;
                image[i][j].rgbtGreen = 69;
                image[i][j].rgbtBlue = 0;
            }
        }
    }
}

