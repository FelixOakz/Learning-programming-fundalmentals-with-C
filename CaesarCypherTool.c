#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// - A 'cryptosystem' to encript any message, based on caesar cypher -

// cypher text to plaintext using a key
// key - prompt user - plaintext - output

int main(int argc, string argv[])
{
    // condition and loop to correct users input to parameters
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    int k = atoi(argv[1]);

    // user input for text
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");

    //loop to run every character and convert it to cypher
    // plaintext + key + loop over alphabet again
    for (int j = 0; j < strlen(plaintext); j++)
    {
        if (isupper(plaintext[j]))
        {
            printf("%c", (plaintext[j] - 65 + k) % 26 + 65);
        }
        else if (islower(plaintext[j]))
        {
            printf("%c", (plaintext[j] - 97 + k) % 26 + 97);
        }
        else
        {
            printf("%c", plaintext[j]);
        }
    }
    printf("\n");
}
