#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // check if the namefile was specified
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }

    // check if memory card is successfully opened
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Could not open file %s.\n", argv[1]);
        return 1;
    }

    //create vars that we gonna use and allocate memory for them
    FILE *img;
    char filename[7];
    unsigned char *bf = malloc(512);
    int end = 1000;
    int counter = 0;

    while (fread(bf, 512, 1, file))
    {
        // new jpg file found
        if (bf[0] == 0xff && bf[1] == 0xd8 && bf[2] == 0xff && (bf[3] & 0xf0) == 0xe0)
        {
            // close previous jpg file if it exists
            if (counter > 0)
            {
                fclose(img);
            }

            // create filename
            sprintf(filename, "%03d.jpg", counter);
            // open new image file
            img = fopen(filename, "w");

            // check if jpg file is successfully created
            if (img == NULL)
            {
                fclose(file);
                free(bf);
                fprintf(stderr, "Could not create output JPG %s", filename);
                return 3;
            }

            counter++;
        }

        //if any jpg file exists writes on the file currently opened
        if (counter > 0)
        {
            fwrite(bf, 512, 1, img);
        }
    }

    //frees memory and closes files
    fclose(img);
    fclose(file);
    free(bf);
    return 0;
}
