#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long card;
    do
    {
        card = get_long("Card number: ");
    }
    //card number have to be greater than 0
    while (card < 0);
    
    //digits that have to be multiolied by 2
    int card1, card3, card5, card7, card9, card11, card13, card15;
    int sum1;
    
    card1 = ((card % 100) / 10) * 2;
    card3 = ((card % 10000) / 1000 * 2);
    card5 = ((card % 1000000) / 100000 * 2);
    card7 = ((card % 100000000) / 10000000 * 2);
    card9 = ((card % 10000000000) / 1000000000 * 2);
    card11 = ((card % 1000000000000) / 100000000000 * 2);
    card13 = ((card % 100000000000000) / 10000000000000 * 2);
    card15 = ((card % 10000000000000000) / 1000000000000000 * 2);
    
    card1 = (card1 % 100 / 10) + (card1 % 10);
    card3 = (card3 % 100 / 10) + (card3 % 10);
    card5 = (card5 % 100 / 10) + (card5 % 10);
    card7 = (card7 % 100 / 10) + (card7 % 10);
    card9 = (card9 % 100 / 10) + (card9 % 10);
    card11 = (card11 % 100 / 10) + (card11 % 10);
    card13 = (card13 % 100 / 10) + (card13 % 10);
    card15 = (card15 % 100 / 10) + (card15 % 10);
    
    //sum of the numbers that were multiplied by 2
    sum1 = card1 + card3 + card5 + card7 + card9 + card11 + card13 + card15;
    
    //digits that were not multiplied by 2
    int card0, card2, card4, card6, card8, card10, card12, card14;
    int sum2;
    
    card0 = (card % 10);
    card2 = ((card % 1000) / 100);
    card4 = ((card % 100000) / 10000);
    card6 = ((card % 10000000) / 1000000);
    card8 = ((card % 1000000000) / 100000000);
    card10 = ((card % 100000000000) / 10000000000);
    card12 = ((card % 10000000000000) / 1000000000000);
    card14 = ((card % 1000000000000000) / 100000000000000);
    
    //sum od the numbers that weren't multiplied by 2
    sum2 = card0 + card2 + card4 + card6 + card8 + card10 + card12 + card14;
    
    int sum3;
    
    sum3 = sum1 + sum2;
    
    int length_card = 0;
    long visa = card;
    long amex = card;
    long master = card;
    
    //check if the last number of sum3 is 0
    if ((sum3 % 10) != 0)
    {
        printf("%s\n", "INVALID");
        return 0;
    }
    
    //this is to differentiate between Amex, Mastercard and Visa
    while (card > 0)
    {
        card = card / 10;
        length_card++;
    }
    
    //Check if it's Visa
    while (visa >= 10)
    {
        visa /= 10;
    }
    if (visa == 4 && (length_card == 13 || length_card == 16))
    {
        printf("%s\n", "VISA");
        return 0;
    }
    
    //check if it's Amex
    while (amex >= 100000000000000)
    {
        amex /= 10000000000000;
    }
    if (length_card == 15 && (amex == 34 || amex == 37))
    {
        printf("%s\n", "AMEX");
        return 0;
    }
    
    //check if it's Mastercard
    while (master >= 100000000000000)
    {
        master /= 100000000000000;
    }
    if (length_card == 16 && (master == 51 || master == 52 || master == 53 || master == 54 || master == 55))
    {
        printf("%s\n", "MASTERCARD");
        return 0;
    }
    else
    {
        printf("%s\n", "INVALID");
        return 0;
    }
}