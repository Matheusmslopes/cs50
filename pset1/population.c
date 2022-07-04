#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Ask the user the start number of population
    int start;
    do
    {
        start = get_int("Starting population: ");
    }
    while(start < 9);
    
    //Ask the user the end number of population
    int end;
    do
    {
        end = get_int("Endind population: ");
    }
    while(start > end);
    
    int year = 0;
    while (start < end)
    {
        start = start + (start / 3) - (start / 4);    
        year++;
    }
    
    printf("Years: %i\n", year);
}