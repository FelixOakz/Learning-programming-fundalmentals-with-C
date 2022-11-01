// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;
//  ---------------  use variable anytime you need to reference number of bytes inside header of a wav file
// typedef for everytime we say byte, i will tell us is an 8bit
typedef uint8_t BYTE;
typedef int16_t SAMPLE_AUDIO;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n"); // input validation
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]); // ------------------------------------------------

// TODO: Copy header from input file to output file, using learned tools, wirte exact same header to the output file
// repeat on each sample, multiply it by volume factor,
// create an array of bytes with 44 bytes (size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);)
    BYTE headerBuffer[HEADER_SIZE]; // initialing array

    fread(headerBuffer, sizeof(BYTE), HEADER_SIZE, input);
    fwrite(headerBuffer, sizeof(BYTE), HEADER_SIZE, output);

    SAMPLE_AUDIO buffer;
// TODO: Read samples from input file and write updated data to output file. loop thru til the end.
// MALLOC???
// ampersand for the variable of the adress of the first slot of the array
    while (fread(&buffer, sizeof(SAMPLE_AUDIO), 1, input) == 1)
    {
        buffer = buffer * factor;
        fwrite(&buffer, sizeof(SAMPLE_AUDIO), 1, output);
    }


    // Close files
    fclose(input);
    fclose(output);
}