#include <stdio.h>
#include <cs50.h>
#include <math.h>

int count_letters(string text); //function prototypes
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string userInput = get_string("Text: ");
    int letters = count_letters(userInput);
    int words = count_words(userInput);
    int sentences = count_sentences(userInput);
    double L = (double) letters / words * 100; //calculate the L for Coleman-Liau index
    double S = (double) sentences / words * 100; //calculate the S for Coleman-Liau index
    int index = round(((0.0588 * L) - (0.296 * S) - 15.8)); //calculate the Coleman-Liau index
    if (index >= 1 && index <= 16)
    {
        printf("Grade %i\n", index);
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade 16+\n");
    }
}

int count_letters(string text)
{
    int chars = 0;
    for (int i = 0 ; text[i] != '\0' ; i++)
    {
        if (((int) text[i] >= 65 && (int) text[i] <= 90) || ((int) text[i] >= 97 && (int) text[i] <= 122)) //check if ASCII value is upper or lower case letters
        {
            chars++;
        }
    }
    return chars;
}

int count_words(string text)
{
    int word = 0;
    for (int i = 0 ; text[i] != '\0' ; i++)
    {
        if ((int) text[i] == 32) //check if ASCII value is of ' '
        {
            word++;
        }
    }
    word++; //to account for the last word in the string or if there is only 1 word in the string
    return word;
}

int count_sentences(string text)
{
    int sent = 0;
    for (int i = 0 ; text[i] != '\0' ; i++)
    {
        if ((int) text[i] == 33 || (int) text[i] == 46 || (int) text[i] == 63) // check if character is '!', '?' or '.'
        {
            sent++;
        }
    }
    return sent;
}
@priyanka-kris
 
Add heading textAdd bold text, <Ctrl+b>Add italic text, <Ctrl+i>
Add a quote, <Ctrl+Shift+.>