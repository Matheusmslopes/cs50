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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int i = 0;
    int j = 0;
    
    //create a copy of the image
    RGBTRIPLE tmp[height][width];
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            tmp[i][j]  = image[i][j];
        }
    }
    
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    
    //loop through each column and row
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            int redX = 0;
            int redY = 0;
            int greenX = 0;
            int greenY = 0;
            int blueX = 0;
            int blueY = 0;
            
            //loop through each pixel for neighbouring pixels
            for (int x = 0; x < 3; x++)
            {
                for (int y = 0; y < 3; y++)
                {
                    //check for valid pixel
                    if (i - 1 + x < 0 || i - 1 + x > height - 1 ||  j - 1 + y < 0 || j - 1 + y > width - 1)
                    {
                        continue;
                    }
                    //calculate Gx for each color
                    redX = redX + (image[i - 1 + x][j - 1 + y].rgbtRed * Gx[x][y]);
                    greenX = greenX + (image[i - 1 + x][j - 1 + y].rgbtGreen * Gx[x][y]);
                    blueX = blueX + (image[i - 1 + x][j - 1 + y].rgbtBlue * Gx[x][y]);
                    
                    //calculate Gy for each color
                    redY = redY + (image[i - 1 + x][j - 1 + y].rgbtRed * Gy[x][y]);
                    greenY = greenY + (image[i - 1 + x][j - 1 + y].rgbtGreen * Gy[x][y]);
                    blueY = blueY + (image[i - 1 + x][j - 1 + y].rgbtBlue * Gy[x][y]);
                }
            }
            //calculate the Gx^2 and Gy^2
            int red = round(sqrt((redX * redX) + (redY * redY)));
            int green = round(sqrt((greenX * greenX) + (greenY * greenY)));
            int blue = round(sqrt((blueX * blueX) + (blueY * blueY)));
            
            //max value have to be 255
            if (red > 255)
            {
                red = 255;
            }
            if (green > 255)
            {
                green = 255;
            }
            if (blue > 255)
            {
                blue = 255;
            }
            
            //copy values to the tmp image
            tmp[i][j].rgbtRed = red;       
            tmp[i][j].rgbtGreen = green;    
            tmp[i][j].rgbtBlue = blue;     
        }
    }
    //copy new pixels to the original image
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
