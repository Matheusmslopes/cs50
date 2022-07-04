#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

// index = (0.0588 * L) - (0.296 * S) - 15.8;

//L = numeros de letras por 100 palavras    S = numero de sentencas por 100 palavras

int main(void)
{
    //Especifica os tipos de dados.
    string text;
    float L, S;
    int i, index;
    int letter = 0;
    //Para incluir a primeira palavra, word = 1.
    int word = 1;
    int sentence = 0;
    
    text = get_string("Text: ");
    for (i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letter++;
        }
        else if (text[i] == ' ')
        {
            word++;
        }
        else if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentence++;
        }
        
    }
    L = (float) letter / (float) word * 100;
    S = (float) sentence / (float) word * 100;
    index = round(0.0588 * L - 0.296 * S - 15.8);
    
    //Informa ao usuário o grau de leitura baseado na grade escolar.
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
   
}





