#include "helpers.h"
#include "math.h"
#include "stdio.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // red=green=blue;
    // average of the original red, green and blue.
    // transform floating number to integer value, round to the nearest integer
    for (int i = 0; i < height; i++)
    {
        for (int j = 0 ; j < width; j++)
        {
            // Need to be 3.0 not 3 here, because the average can be a float value.
            int avg_value = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = avg_value;
            image[i][j].rgbtGreen = avg_value;
            image[i][j].rgbtBlue = avg_value;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // calculate new value using sepia formula
    // maximum value should be 255 for each color;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0 ; j < width; j++)
        {
            int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }

            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
}


// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        // only go through the first half of the columns and swap
        for (int j = 0; j < (width - 1) * 0.5 ; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }

}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //value is equal to the average of the surrounding pixels;
    // define a new image that has one more line and one more column
    RGBTRIPLE image2[height + 2][width + 2]; // name can be anything, RGBTRIPLE only define the structure
    // the added line and column are just black.
    for (int i = 0; i < width + 2; i++)
    {
        image2[0][i].rgbtRed = 0;
        image2[0][i].rgbtGreen = 0;
        image2[0][i].rgbtBlue = 0;
        image2[height + 1][i].rgbtRed = 0;
        image2[height + 1][i].rgbtGreen = 0;
        image2[height + 1][i].rgbtBlue = 0;
    }

    for (int i = 1; i < height + 1; i++)
    {
        image2[i][0].rgbtRed = 0;
        image2[i][0].rgbtGreen = 0;
        image2[i][0].rgbtBlue = 0;
        image2[i][width + 1].rgbtRed = 0;
        image2[i][width + 1].rgbtGreen = 0;
        image2[i][width + 1].rgbtBlue = 0;
    }

    // copy the original image to the inner circle
    for (int i = 1; i < height + 1; i++)
    {
        for (int j = 1; j< width + 1; j++)
        {
            image2[i][j] = image[i - 1][j - 1];
        }
    }

    // define the corner situtaion. Can be simplified?
    int m = 1;
    int n = 1;
    image[m - 1][n - 1].rgbtRed = round(1 / 4.0 * (image2[m - 1][n - 1].rgbtRed + image2[m][n - 1].rgbtRed + image2[m + 1][n - 1].rgbtRed \
    + image2[m - 1][n].rgbtRed + image2[m][n].rgbtRed + image2[m + 1][n].rgbtRed \
    + image2[m - 1][n + 1].rgbtRed + image2[m][n + 1].rgbtRed + image2[m + 1][n + 1].rgbtRed));

    image[m - 1][n - 1].rgbtGreen = round(1 / 4.0 * (image2[m - 1][n - 1].rgbtGreen + image2[m][n - 1].rgbtGreen + image2[m + 1][n - 1].rgbtGreen \
    + image2[m - 1][n].rgbtGreen + image2[m][n].rgbtGreen + image2[m + 1][n].rgbtGreen \
    + image2[m - 1][n + 1].rgbtGreen + image2[m][n + 1].rgbtGreen + image2[m + 1][n + 1].rgbtGreen));

    image[m - 1][n - 1].rgbtBlue = round(1 / 4.0 * (image2[m - 1][n - 1].rgbtBlue + image2[m][n - 1].rgbtBlue + image2[m + 1][n - 1].rgbtBlue \
    + image2[m - 1][n].rgbtBlue + image2[m][n].rgbtBlue + image2[m + 1][n].rgbtBlue \
    + image2[m - 1][n + 1].rgbtBlue + image2[m][n + 1].rgbtBlue + image2[m + 1][n + 1].rgbtBlue));


    m = 1;
    n = width;
    image[m - 1][n - 1].rgbtRed = round(1 / 4.0 * (image2[m - 1][n - 1].rgbtRed + image2[m][n - 1].rgbtRed + image2[m + 1][n - 1].rgbtRed \
    + image2[m - 1][n].rgbtRed + image2[m][n].rgbtRed + image2[m + 1][n].rgbtRed \
    + image2[m - 1][n + 1].rgbtRed + image2[m][n + 1].rgbtRed + image2[m + 1][n + 1].rgbtRed));

    image[m - 1][n - 1].rgbtGreen = round(1 / 4.0 * (image2[m - 1][n - 1].rgbtGreen + image2[m][n - 1].rgbtGreen + image2[m + 1][n - 1].rgbtGreen \
    + image2[m - 1][n].rgbtGreen + image2[m][n].rgbtGreen + image2[m + 1][n].rgbtGreen \
    + image2[m - 1][n + 1].rgbtGreen + image2[m][n + 1].rgbtGreen + image2[m + 1][n + 1].rgbtGreen));

    image[m - 1][n - 1].rgbtBlue = round(1 / 4.0 * (image2[m - 1][n - 1].rgbtBlue + image2[m][n - 1].rgbtBlue + image2[m + 1][n - 1].rgbtBlue \
    + image2[m - 1][n].rgbtBlue + image2[m][n].rgbtBlue + image2[m + 1][n].rgbtBlue \
    + image2[m - 1][n + 1].rgbtBlue + image2[m][n + 1].rgbtBlue + image2[m + 1][n + 1].rgbtBlue));

    m = height;
    n = 1;
    image[m - 1][n - 1].rgbtRed = round(1 / 4.0 * (image2[m - 1][n - 1].rgbtRed + image2[m][n - 1].rgbtRed + image2[m + 1][n - 1].rgbtRed \
    + image2[m - 1][n].rgbtRed + image2[m][n].rgbtRed + image2[m + 1][n].rgbtRed \
    + image2[m - 1][n + 1].rgbtRed + image2[m][n + 1].rgbtRed + image2[m + 1][n + 1].rgbtRed));

    image[m - 1][n - 1].rgbtGreen = round(1 / 4.0 * (image2[m - 1][n - 1].rgbtGreen + image2[m][n - 1].rgbtGreen + image2[m + 1][n - 1].rgbtGreen \
    + image2[m - 1][n].rgbtGreen + image2[m][n].rgbtGreen + image2[m + 1][n].rgbtGreen \
    + image2[m - 1][n + 1].rgbtGreen + image2[m][n + 1].rgbtGreen + image2[m + 1][n + 1].rgbtGreen));

    image[m - 1][n - 1].rgbtBlue = round(1 / 4.0 * (image2[m - 1][n - 1].rgbtBlue + image2[m][n - 1].rgbtBlue + image2[m + 1][n - 1].rgbtBlue \
    + image2[m - 1][n].rgbtBlue + image2[m][n].rgbtBlue + image2[m + 1][n].rgbtBlue \
    + image2[m - 1][n + 1].rgbtBlue + image2[m][n + 1].rgbtBlue + image2[m + 1][n + 1].rgbtBlue));

    m = height;
    n = width;
    image[m - 1][n - 1].rgbtRed = round(1 / 4.0 * (image2[m - 1][n - 1].rgbtRed + image2[m][n - 1].rgbtRed + image2[m + 1][n - 1].rgbtRed \
    + image2[m - 1][n].rgbtRed + image2[m][n].rgbtRed + image2[m + 1][n].rgbtRed \
    + image2[m - 1][n + 1].rgbtRed + image2[m][n + 1].rgbtRed + image2[m + 1][n + 1].rgbtRed));

    image[m - 1][n - 1].rgbtGreen = round(1 / 4.0 * (image2[m - 1][n - 1].rgbtGreen + image2[m][n - 1].rgbtGreen + image2[m + 1][n - 1].rgbtGreen \
    + image2[m - 1][n].rgbtGreen + image2[m][n].rgbtGreen + image2[m + 1][n].rgbtGreen \
    + image2[m - 1][n + 1].rgbtGreen + image2[m][n + 1].rgbtGreen + image2[m + 1][n + 1].rgbtGreen));

    image[m - 1][n - 1].rgbtBlue = round(1 / 4.0 * (image2[m - 1][n - 1].rgbtBlue + image2[m][n - 1].rgbtBlue + image2[m + 1][n - 1].rgbtBlue \
    + image2[m - 1][n].rgbtBlue + image2[m][n].rgbtBlue + image2[m + 1][n].rgbtBlue \
    + image2[m - 1][n + 1].rgbtBlue + image2[m][n + 1].rgbtBlue + image2[m + 1][n + 1].rgbtBlue));



    // define the edges
    for (int i = 1, j = 2; j < width; j++)
    {
        image[i - 1][j - 1].rgbtRed = round(1 / 6.0 * (image2[i - 1][j - 1].rgbtRed + image2[i][j - 1].rgbtRed + image2[i + 1][j - 1].rgbtRed \
        + image2[i - 1][j].rgbtRed + image2[i][j].rgbtRed + image2[i + 1][j].rgbtRed \
        + image2[i - 1][j + 1].rgbtRed + image2[i][j + 1].rgbtRed + image2[i + 1][j + 1].rgbtRed));

        image[i - 1][j - 1].rgbtGreen = round(1 / 6.0 * (image2[i - 1][j - 1].rgbtGreen + image2[i][j - 1].rgbtGreen + image2[i + 1][j - 1].rgbtGreen \
        + image2[i - 1][j].rgbtGreen + image2[i][j].rgbtGreen + image2[i + 1][j].rgbtGreen \
        + image2[i - 1][j + 1].rgbtGreen + image2[i][j + 1].rgbtGreen + image2[i + 1][j + 1].rgbtGreen));

        image[i - 1][j - 1].rgbtBlue = round(1 / 6.0 * (image2[i - 1][j - 1].rgbtBlue + image2[i][j - 1].rgbtBlue + image2[i + 1][j - 1].rgbtBlue \
        + image2[i - 1][j].rgbtBlue + image2[i][j].rgbtBlue + image2[i + 1][j].rgbtBlue \
        + image2[i - 1][j + 1].rgbtBlue + image2[i][j + 1].rgbtBlue + image2[i + 1][j + 1].rgbtBlue));
    }

    for (int i = height, j = 2; j < width; j++)
    {
        image[i - 1][j - 1].rgbtRed = round(1 / 6.0 * (image2[i - 1][j - 1].rgbtRed + image2[i][j - 1].rgbtRed + image2[i + 1][j - 1].rgbtRed \
        + image2[i - 1][j].rgbtRed + image2[i][j].rgbtRed + image2[i + 1][j].rgbtRed \
        + image2[i - 1][j + 1].rgbtRed + image2[i][j + 1].rgbtRed + image2[i + 1][j + 1].rgbtRed));

        image[i - 1][j - 1].rgbtGreen = round(1 / 6.0 * (image2[i - 1][j - 1].rgbtGreen + image2[i][j - 1].rgbtGreen + image2[i + 1][j - 1].rgbtGreen \
        + image2[i - 1][j].rgbtGreen + image2[i][j].rgbtGreen + image2[i + 1][j].rgbtGreen \
        + image2[i - 1][j + 1].rgbtGreen + image2[i][j + 1].rgbtGreen + image2[i + 1][j + 1].rgbtGreen));

        image[i - 1][j - 1].rgbtBlue = round(1 / 6.0 * (image2[i - 1][j - 1].rgbtBlue + image2[i][j - 1].rgbtBlue + image2[i + 1][j - 1].rgbtBlue \
        + image2[i - 1][j].rgbtBlue + image2[i][j].rgbtBlue + image2[i + 1][j].rgbtBlue \
        + image2[i - 1][j + 1].rgbtBlue + image2[i][j + 1].rgbtBlue + image2[i + 1][j + 1].rgbtBlue));
    }


    for (int i = 2, j = 1; i < height; i++)
    {
        image[i - 1][j - 1].rgbtRed = round(1 / 6.0 * (image2[i - 1][j - 1].rgbtRed + image2[i][j - 1].rgbtRed + image2[i + 1][j - 1].rgbtRed \
        + image2[i - 1][j].rgbtRed + image2[i][j].rgbtRed + image2[i + 1][j].rgbtRed \
        + image2[i - 1][j + 1].rgbtRed + image2[i][j + 1].rgbtRed + image2[i + 1][j + 1].rgbtRed));

        image[i - 1][j - 1].rgbtGreen = round(1 / 6.0 * (image2[i - 1][j - 1].rgbtGreen + image2[i][j - 1].rgbtGreen + image2[i + 1][j - 1].rgbtGreen \
        + image2[i - 1][j].rgbtGreen + image2[i][j].rgbtGreen + image2[i + 1][j].rgbtGreen \
        + image2[i - 1][j + 1].rgbtGreen + image2[i][j + 1].rgbtGreen + image2[i + 1][j + 1].rgbtGreen));

        image[i - 1][j - 1].rgbtBlue = round(1 / 6.0 * (image2[i - 1][j - 1].rgbtBlue + image2[i][j - 1].rgbtBlue + image2[i + 1][j - 1].rgbtBlue \
        + image2[i - 1][j].rgbtBlue + image2[i][j].rgbtBlue + image2[i + 1][j].rgbtBlue \
        + image2[i - 1][j + 1].rgbtBlue + image2[i][j + 1].rgbtBlue + image2[i + 1][j + 1].rgbtBlue));
    }



    for (int i = 2, j = width; i < height; i++)
    {
        image[i - 1][j - 1].rgbtRed = round(1 / 6.0 * (image2[i - 1][j - 1].rgbtRed + image2[i][j - 1].rgbtRed + image2[i + 1][j - 1].rgbtRed \
        + image2[i - 1][j].rgbtRed + image2[i][j].rgbtRed + image2[i + 1][j].rgbtRed \
        + image2[i - 1][j + 1].rgbtRed + image2[i][j + 1].rgbtRed + image2[i + 1][j + 1].rgbtRed));

        image[i - 1][j - 1].rgbtGreen = round(1 / 6.0 * (image2[i - 1][j - 1].rgbtGreen + image2[i][j - 1].rgbtGreen + image2[i + 1][j - 1].rgbtGreen \
        + image2[i - 1][j].rgbtGreen + image2[i][j].rgbtGreen + image2[i + 1][j].rgbtGreen \
        + image2[i - 1][j + 1].rgbtGreen + image2[i][j + 1].rgbtGreen + image2[i + 1][j + 1].rgbtGreen));

        image[i - 1][j - 1].rgbtBlue = round(1 / 6.0 * (image2[i - 1][j - 1].rgbtBlue + image2[i][j - 1].rgbtBlue + image2[i + 1][j - 1].rgbtBlue \
        + image2[i - 1][j].rgbtBlue + image2[i][j].rgbtBlue + image2[i + 1][j].rgbtBlue \
        + image2[i - 1][j + 1].rgbtBlue + image2[i][j + 1].rgbtBlue + image2[i + 1][j + 1].rgbtBlue));
    }

    // for inner pixels.
    for (int i = 2; i < height; i++)
    {
        for (int j = 2; j < width; j++)
        {
            image[i - 1][j - 1].rgbtRed = round(1 / 9.0 * (image2[i - 1][j - 1].rgbtRed + image2[i][j - 1].rgbtRed + image2[i + 1][j - 1].rgbtRed \
                                        + image2[i - 1][j].rgbtRed + image2[i][j].rgbtRed + image2[i + 1][j].rgbtRed \
                                        + image2[i - 1][j + 1].rgbtRed + image2[i][j + 1].rgbtRed + image2[i + 1][j + 1].rgbtRed));

            image[i - 1][j - 1].rgbtGreen = round(1 / 9.0 * (image2[i - 1][j - 1].rgbtGreen + image2[i][j - 1].rgbtGreen + image2[i + 1][j - 1].rgbtGreen \
                                        + image2[i - 1][j].rgbtGreen + image2[i][j].rgbtGreen + image2[i + 1][j].rgbtGreen \
                                        + image2[i - 1][j + 1].rgbtGreen + image2[i][j + 1].rgbtGreen + image2[i + 1][j + 1].rgbtGreen));

            image[i - 1][j - 1].rgbtBlue = round(1 / 9.0 * (image2[i - 1][j - 1].rgbtBlue + image2[i][j - 1].rgbtBlue + image2[i + 1][j - 1].rgbtBlue \
                                        + image2[i - 1][j].rgbtBlue + image2[i][j].rgbtBlue + image2[i + 1][j].rgbtBlue \
                                        + image2[i - 1][j + 1].rgbtBlue + image2[i][j + 1].rgbtBlue + image2[i + 1][j + 1].rgbtBlue));
        }
    }
}




