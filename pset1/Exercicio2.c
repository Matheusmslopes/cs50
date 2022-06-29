#include <cs50.h>
#include <stdio.h>

int main(void)
{
   // Tipo dos dados
   int height, row, column, space;
   do
   {
      // Pede a altura da pirâmide para o usuário
      height = get_int("Height: ");
   }
   while (height < 1 || height > 8);
   //Pirâmide alinhada e direita
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
        printf("  ");
        // Pirâmide alinhada a esquerda
          for(column = 0; column <= row; column++)
        {
            printf("#");
        }
        printf("\n");
   }
   
}
