#include <stdio.h>
#include <cs50.h>

//Prototype
int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    //Ask how many cents the user owed (line 38)
    int cents = get_cents();
    
    //Calculate the number of quarters(25) to give(line 49)
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;
    
    //Calculate the number of dimes(10) to give(line 60)
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;
    
    //Calculate the number of nickels(5) to give(line 71)
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;
    
    //Calculate the number of pennies(1) to give(line 82)
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;
    
    //sum the total of coins
    int coins = quarters + dimes + nickels + pennies;
    
    printf("%i\n", coins);
}

int get_cents(void)
{
    int cents;
    do
    {
        cents = get_int("Cents owed:");
    }
    while (cents < 0);
    return cents;
}

int calculate_quarters(int cents)
{
    int quarters = 0;
    while (cents >= 25)
    {
        cents = cents - 25;
        quarters++;
    }
    return quarters;
}

int calculate_dimes(int cents)
{
    int dimes = 0;
    while (cents >= 10)
    {
        cents = cents - 10;
        dimes++;
    }
    return dimes;
}

int calculate_nickels(int cents)
{
    int nickels = 0;
    while (cents >= 5)
    {
        cents = cents - 5;
        nickels++;
    }
    return nickels;
}

int calculate_pennies(int cents)
{
    int pennies = 0;
    while (cents >= 1)
    {
        cents = cents - 1;
        pennies++;
    }
    return pennies;
}
