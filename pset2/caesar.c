#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    //Especifica os tipos de dados.
    int i, j, key;
    string plaintext;
    
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    } 
    
    for (i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1] [i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
        
    key = atoi(argv[1]);
        
    //Pede ao usuário o texto para ser criptografado
    plaintext = get_string("Plaintext:");
    //Output do texto já criptografado
    printf("Ciphertext:");
        
    //Por convenção usei j, mas poderia usar qualaquer outra letra.
    for (j = 0; j < strlen(plaintext); j++)
    {
        if (isupper(plaintext[j]))
        {
            printf("%c", (plaintext[j] - 65 + key) % 26 + 65);
        }
        else if (islower(plaintext[j]))
        {
            printf("%c", (plaintext[j] - 97 + key) % 26 + 97);
        }
        else
        {
            printf("%c", plaintext[j]);
        }
    }
  printf("\n");
}