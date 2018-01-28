#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    int k;
    if(argc != 2 || argv[1] <= 0)
    {
        printf("Wrong input");
        return 1;
    }

    k = atoi(argv[1]);

    string text = get_string("Enter message to encrpyt: ");

    for(int i = 0; i < strlen(text);i++)
    {
        if(isalpha(text[i]))
        {

            if(isupper(text[i]))
            {
                text[i] = ((text[i] - 65) + k) % 26 + 65;
                printf("%c",text[i]);
            }
            else
            {
                text[i] = ((text[i] - 97) + k) % 26 + 97;
                printf("%c",text[i]);
            }
        }
        else
        {
            printf("%c",text[i]);
        }
    }
}
