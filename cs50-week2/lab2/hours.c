#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

float calc_hours(int hours[], int weeks, char output);

int main(void)
{
    int weeks = get_int("Number of weeks taking CS50: ");
    int hours[weeks];

    for (int i = 0; i < weeks; i++)
    {
        hours[i] = get_int("Week %i HW Hours: ", i);
    }

    char output;
    do
    {
        output = toupper(get_char("Enter T for total hours, A for average hours per week: "));
    }
    while (output != 'T' && output != 'A');

    printf("%.1f hours\n", calc_hours(hours, weeks, output));
}

// TODO: complete the calc_hours function
float calc_hours(int hours[], int weeks, char output)
{
    // count total hours
    float output_hrs;
    float total_hrs = 0;
    for (int i = 0; i < weeks; i++)
    {
        total_hrs += hours[i];
    }

    // calculate average hours
    float avg_hrs = total_hrs / weeks;

    if (output == 'T')
    {
        output_hrs = total_hrs;
    }
    else // Here if using else if, then need to consider the value of output_hrs when both if conditions fail
    // else, make conditions complete, the conditions are the opposities. 
    {
        output_hrs = avg_hrs;
    }
    return output_hrs;
}