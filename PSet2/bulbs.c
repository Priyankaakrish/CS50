#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
        string message = get_string("Message: ");
    int message_length = strlen(message);
    int message_binary[BITS_IN_BYTE][message_length];

    for (int i = 0; i < message_length; i++)
    {
        int decimal = message[i];
        for (int j = 0; j < BITS_IN_BYTE; j++)
        {
            message_binary[i][j] = decimal % 2;
            decimal = decimal / 2;
            print_bulb(message_binary[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < message_length; i++)
    {
        for (int j = BITS_IN_BYTE - 1; j >= 0; j--)
        {
            print_bulb(message_binary[i][j]);
        }
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
