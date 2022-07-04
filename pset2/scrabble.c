#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

//Specify the data type
int i, score, score1, score2;
string word1, word2;


// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

//Prototype
int compute_score(string word);

int main(void)
{
    // Get input words from both players
    word1 = get_string("Player 1: ");
    word2 = get_string("Player 2: ");

    // Score both words
    score1 = compute_score(word1);
    score2 = compute_score(word2);

    // Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // Compute and return score for string
    
    score = 0;
    
    for (i = 0; i < strlen(word); i++)
    {
      if (isupper(word[i]))
      {
        score = score  + POINTS[word[i] - 65];
      }
      else if (islower(word[i]))
      {
        score = score  + POINTS[word[i] - 97];
      }
    }
    return score;
}
