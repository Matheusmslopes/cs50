#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;
 
int main(int argc, char *argv[])
{
//check for correct input from the user
    if (argc != 2)
    {
        printf("Correct use: ./recover filename\n");
        return 1;
    }
    
    //open file for reading
    FILE *input_file = fopen(argv[1], "r");
    
    //check if it's valid
    if (input_file == NULL)
    {
        printf("Could not open.\n");
        return 1;
    }
    
    //store the block of 512bytes in an array.
    unsigned char buffer[512];
    
    //count the number of images generated
    int count_image = 0;
    
    //file pointer for the recovered images
    FILE *output_file = NULL;
    
    char *filename = malloc(8 * sizeof(char));
    
    //read the blocks of 512 bytes
    while (fread(buffer, sizeof(char), 512, input_file))
    {
        //check if the bytes indicate a start of JPEG's file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //write the output name of the JPEG file
            sprintf(filename, "%03i.jpg", count_image);
            
            //open the output_file for writing
            output_file = fopen(filename, "w");
            
            //count the number of image
            count_image++;
        }
        //check the output
        if (output_file != NULL)
        {
            fwrite(buffer, sizeof(char), 512, output_file);
        }
    }
    //free the memory we get with malloc
    free(filename);
    
    fclose(output_file);
    fclose(input_file);
    
    return 0;
}