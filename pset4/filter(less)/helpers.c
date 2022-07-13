#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
  int i = 0;
  int j = 0;

   //look through each row
   for (i = 0; i < height; i++)
   {
       //look through each column
       for (j = 0; j < width; j++)
       {
           //convert pixel to float
           float Red = image[i][j].rgbtRed;
           float Green = image[i][j].rgbtGreen;
           float Blue = image[i][j].rgbtBlue;

           //find the AVG of the RGB combined
            int average = round((Red + Green + Blue) / 3);

            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = average;
        }
   }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
   int i = 0;
   int j = 0;
   
   //look through each row
   for (i = 0; i < height; i++)
   {
       //look through each column
       for (j = 0; j < width; j++)
       {
           //convert pixel to float
           float originalRed = image[i][j].rgbtRed;
           float originalGreen = image[i][j].rgbtGreen;
           float originalBlue = image[i][j].rgbtBlue;
           
           //find the updated value of the pixel
           int sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
           int sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
           int sepiaBlue = round(0.272 * originalRed + 0.534 * originalGreen + 0.131 * originalBlue);
           
           //if the value exceeds 255, set back to 255
           if (sepiaRed > 255)
           {
               sepiaRed = 255;
           }
           if (sepiaGreen > 255)
           {
               sepiaGreen = 255;
           }
           if (sepiaBlue > 255)
           {
               sepiaBlue = 255;
           }
           
           //update final value of pixels
           image[i][j].rgbtRed = sepiaRed;
           image[i][j].rgbtGreen = sepiaGreen;
           image[i][j].rgbtBlue = sepiaBlue;
       }
   }
    
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int i = 0;
    int j = 0;

    //look through each row
    for (i = 0; i < height; i++)
    {
        //look through each column
        for (j = 0; j < width / 2; j++)
        {
            RGBTRIPLE tmp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = tmp;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int i = 0;
    int j = 0;

    //creates a copy of the image
    RGBTRIPLE tmp[height][width];
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            tmp[i][j]  = image[i][j];
        }
    }

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            int totalRed, totalGreen, totalBlue;

            totalRed = totalGreen = totalBlue = 0;

            float counter = 0.00;

            //getting neighbouring pixel
            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    int currentX = i + x;
                    int currentY = j + y;

                    //check if the neighbouring pixels are valid
                    if (currentX < 0 || currentX > (height - 1) || currentY < 0 || currentY > (width - 1))
                    {
                        continue;
                    }

                    // get image value
                    totalRed += image[currentX][currentY].rgbtRed;
                    totalGreen += image[currentX][currentY].rgbtGreen;
                    totalBlue += image[currentX][currentY].rgbtBlue;

                    counter++;
                }
                //calculate the AVG of neighbouring pixels
                tmp[i][j].rgbtRed = round(totalRed / counter);
                tmp[i][j].rgbtGreen = round(totalGreen / counter);
                tmp[i][j].rgbtBlue = round(totalBlue / counter);
            }
        }
        
    } 
    // copy new pixels into the original image
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = tmp[i][j].rgbtRed;
            image[i][j].rgbtGreen = tmp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = tmp[i][j].rgbtBlue;
        }
        
    }
   return;
}
