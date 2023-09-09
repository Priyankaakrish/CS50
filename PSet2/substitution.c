#include <cs50.h>
#include <stdio.h>
#include <string.h>

void encode(string key, string pt);
bool checkKey(string key);

int main(int argc, string argv[])
{
    bool isval = false;
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else
    {
        isval = checkKey(argv[1]);
        if (isval == false)
        {
            printf("Key does not contain each character exactly once\n");
            return 1;
        }
    }

    string key1 = argv[1]; //make a backup of user input

    for (int i = 0 ; i < 26 ; i++) //convert key's characters to uppercase
    {
        if ((int) key1[i] > 90)
        {
            key1[i] = (char)((int)(key1[i]) - 32);
        }
    }
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");
    encode(key1, plaintext);
    printf("\n");
}

bool checkKey(string key) //check if the key is valid, assuming it is 26 characters long
{
    int test[26];

    for (int i = 0 ; i < 26 ; i++) //create an array to store all uppercase letters "ABCD...Z"
    {
        test[i] = (i + 65);
    }

    int counter[26]; //use this array to store the number of times a letter at index i occurs
    for (int i = 0 ; i < 26 ; i++) //initialise counter
    {
        counter[i] = 0;
    }
    for (int i = 0 ; i < 26 ; i++) //count # of times each character i occurs
    {
        for (int j = 0 ; j < 26 ; j++)
        {
            if (test[i] == key[j] || test[i] == (key[j] - 32)) //cycles through the key to find a, b and so on
            {
                counter[i]++; //increments location 1, 2, etc. everytime a, b, etc. is found
                break; //escape from loop and move on to next character
            }
        }
        if (counter[i] != 1) //if a character was not found or found more than once
        {
            return false;
        }
    }
    return true; //flow of control comes here only if each letter occurs once
}

void encode(string key, string pt)
{
    char cipher[strlen(pt)]; //character array to store the ciphertext

    for (int i = 0 ; i < strlen(pt) ; i++) //initialise the array
    {
        cipher[i] = ' ';
    }
    int pos = 0;

    for (int i = 0 ; i < strlen(pt) ; i++) //go 1 character at a time through the plaintext string and assign a corresponding character to the ciphertext
    {
        if (pt[i] >= 65 && pt[i] <= 90) //if it's uppercase
        {
            pos = (int)(pt[i] - 65); //find the substituted character at that index location in the key
            cipher[i] = key[pos];
        }
        else if (pt[i] >= 97 && pt[i] <= 122) //if it's lowercase
        {
            pos = (int)(pt[i] - 97); //find the substituted character at that index location in the key
            cipher[i] = key[pos] + 32;
        }
        else //any other character remains as is
        {
            cipher[i] = pt[i];
        }
    }

    for (int i = 0 ; i < strlen(pt) ; i++) //go 1 character at a time and print the ciphertext
    {
        printf("%c", cipher[i]);
    }
}
