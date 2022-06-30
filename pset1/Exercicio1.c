#include <cs50.h>
#include <stdio.h>

int main(void)
{
   // Especifica os Tipos dos dados.
   int column, height, row, space;
   do
   {
      // Pede a altura da pirâmide que o usuáriocquer.
      height = get_int("Height: ");
   }
   while (height < 1 || height > 8);
   
       for(row = 0; row < height; row++)
   {
         for(space = 0; space < height - row - 1; space++)
       {
            printf(" ");
       }
            for(column = 0; column <= row; column++)
       {
           printf("#");
       }
        printf("\n");
   }
   
}


