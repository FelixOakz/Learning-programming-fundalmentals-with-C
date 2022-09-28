#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

# - An any text readability rating, based on the Coleman-Liau index formula - 


int main(void)
{
// get string for user input and initializing variants
    string text = get_string("Text: ");

    int letters = 0;
    int sentences = 0;
    int words = 1;

// counting leters, using isalpha function from cs50 manuals
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }

// counting words using number of spaces + 1
        else if (text[i] == ' ')
        {
            words++;
        }

// counting sentences using characters
        else if (text[i] == '!' || text[i] == '.' || text[i] == '?')
        {
            sentences++;
        }
    }

// using given formula and calculating score
    float S = (float) sentences / (float) words * 100;

    float L = (float) letters / (float) words * 100;

    int grade = round(0.0588 * L - 0.296 * S - 15.8);

// printing result according to computed score
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }

    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }

    else
    {
        printf("Grade %i\n", grade);
    }
}
