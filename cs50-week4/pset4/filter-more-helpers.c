#include "helpers.h"
#include <math.h>

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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
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

    int gx_red, gx_green, gx_blue, gy_red, gy_green, gy_blue;
    int new_red, new_green, new_blue;
    for (int i = 1; i < height + 1; i++)
    {
        for (int j = 1; j < width + 1; j++)
        {
            gx_red = (-1) * image2[i - 1][j - 1].rgbtRed + (-2) * image2[i][j - 1].rgbtRed + (-1) * image2[i + 1][j - 1].rgbtRed \
                    + image2[i - 1][j + 1].rgbtRed + 2 * image2[i][j + 1].rgbtRed + image2[i + 1][j + 1].rgbtRed;
            gy_red = (-1) * image2[i - 1][j - 1].rgbtRed + image2[i + 1][j - 1].rgbtRed + (-2) * image2[i - 1][j].rgbtRed + 2 * image2[i + 1][j].rgbtRed \
                                        + (-1) * image2[i - 1][j + 1].rgbtRed + image2[i + 1][j + 1].rgbtRed;
            new_red = round(sqrt(pow(gx_red, 2) + pow(gy_red, 2)));

            if (new_red > 255)
            {
                image[i - 1][j - 1].rgbtRed = 255;
            }
            else
            {
                image[i - 1][j - 1].rgbtRed = new_red;
            }

            gx_green = (-1) * image2[i - 1][j - 1].rgbtGreen + (-2) * image2[i][j - 1].rgbtGreen + (-1) * image2[i + 1][j - 1].rgbtGreen \
                    + image2[i - 1][j + 1].rgbtGreen + 2 * image2[i][j + 1].rgbtGreen + image2[i + 1][j + 1].rgbtGreen;
            gy_green = (-1) * image2[i - 1][j - 1].rgbtGreen + image2[i + 1][j - 1].rgbtGreen + (-2) * image2[i - 1][j].rgbtGreen + 2 * image2[i + 1][j].rgbtGreen \
                                        + (-1) * image2[i - 1][j + 1].rgbtGreen + image2[i + 1][j + 1].rgbtGreen;
            new_green = round(sqrt(pow(gx_green, 2) + pow(gy_green, 2)));

            if (new_green > 255)
            {
                image[i - 1][j - 1].rgbtGreen = 255;
            }
            else
            {
                image[i - 1][j - 1].rgbtGreen = new_green;
            }

            gx_blue = (-1) * image2[i - 1][j - 1].rgbtBlue + (-2) * image2[i][j - 1].rgbtBlue + (-1) * image2[i + 1][j - 1].rgbtBlue \
                    + image2[i - 1][j + 1].rgbtBlue + 2 * image2[i][j + 1].rgbtBlue + image2[i + 1][j + 1].rgbtBlue;
            gy_blue = (-1) * image2[i - 1][j - 1].rgbtBlue + image2[i + 1][j - 1].rgbtBlue + (-2) * image2[i - 1][j].rgbtBlue + 2 * image2[i + 1][j].rgbtBlue \
                                        + (-1) * image2[i - 1][j + 1].rgbtBlue + image2[i + 1][j + 1].rgbtBlue;
            new_blue = round(sqrt(pow(gx_blue, 2) + pow(gy_blue, 2)));

            if (new_blue > 255)
            {
                image[i - 1][j - 1].rgbtBlue = 255;
            }
            else
            {
                image[i - 1][j - 1].rgbtBlue = new_blue;
            }

        }
    }



}
