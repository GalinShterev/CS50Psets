#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char encrypt(char token, int key);


int main(int argc, string argv[])
{
    int modified;
    if(argc != 2)
    {
        printf("Wrong input");
        return 1;
    }
    int argslen = strlen(argv[1]);
    char k[argslen];
    strcpy(k,argv[1]);
    int iterator = 0;
    string plaintext = get_string("Enter message to encrypt here: ");
    int len = strlen(plaintext);
    for(int i = 0; i < len;i++)
    {
        modified = toupper(k[iterator%argslen]) - 65;
        if(isalpha(plaintext[i]))
        {
            printf("%c", encrypt(plaintext[i],modified));
            iterator++;
        }
        else
        {
            printf("%c",plaintext[i]);
        }
    }
    printf("\n");
    return 0;
}

char encrypt(char token, int key)
{
    if(islower(token))
    {
        return ((((token - 97)+key)%26)+97);
    }
    else
    {
        return ((((token - 65)  +key)%26)+65);
    }
}