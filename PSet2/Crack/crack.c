#define _XOPEN_SOURCE
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>

int main(int argc, string argv[])
{
	//Variables declarations

	void zeroCase(char *generateWrd, string hash, string alphabet);
	void firstCase(char *generateWrd, string hash, string alphabet);
	void secondCase(char *generateWrd, string hash, string alphabet);
	void thirdCase(char *generateWrd, string hash, string alphabet);
	bool isInputCorrect;
	char generateWrd[5] = "\0";
	string hash = "";
	bool isPswFound = false;
	int iterator = 0;
	string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

	//Validate input
	do
	{
		if (argc != 2)
		{
			printf("Wrong input\n");
			return 1;
		}
		else
		{
			isInputCorrect = true;
			hash = argv[1];
		}

	} while (!isInputCorrect);


	while (!isPswFound)
	{
		switch (iterator)
		{
		case 0:
		{
			zeroCase(generateWrd, hash, alphabet);

			if (strcmp(crypt(generateWrd, "50"), hash) == 0)
			{
				isPswFound = true;

			}
		}
		break;
		case 1:
		{
			firstCase(generateWrd, hash, alphabet);

			if (strcmp(crypt(generateWrd, "50"), hash) == 0)
			{
				isPswFound = true;

			}
		}
		break;
		case 2:
		{
			secondCase(generateWrd, hash, alphabet);

			if (strcmp(crypt(generateWrd, "50"), hash) == 0)
			{
				isPswFound = true;

			}
		}
		break;
		case 3:
		{
			thirdCase(generateWrd, hash, alphabet);

			if (strcmp(crypt(generateWrd, "50"), hash) == 0)
			{
				isPswFound = true;
			}
		}
		break;
		}
		iterator++;
	}
	printf("%s\n", generateWrd);
}
void zeroCase(char *generateWrd, string hash, string alphabet)
{

	for (int i = 0; i < 52; i++)
	{
		generateWrd[0] = alphabet[i];

		string comp = crypt(generateWrd, "50");

		if (strcmp(comp, hash) == 0)
		{
			return;
		}
	}

}

void firstCase(char *generateWrd, string hash, string alphabet)
{

	for (int i = 0; i < 52; i++)
	{

		for (int j = 0; j < 52; j++)
		{
			generateWrd[0] = alphabet[i];
			generateWrd[1] = alphabet[j];
			string comp = crypt(generateWrd, "50");

			if (strcmp(comp, hash) == 0)
			{
				return;
			}
		}

	}
}

void secondCase(char *generateWrd, string hash, string alphabet)
{

	for (int i = 0; i < 52; i++)
	{
		generateWrd[0] = alphabet[i];
		string comp = crypt(generateWrd, "50");
		if (strcmp(comp, hash) == 0)
		{
			return;
		}

		for (int j = 0; j < 52; j++)
		{
			generateWrd[1] = alphabet[j];
			comp = crypt(generateWrd, "50");
			if (strcmp(comp, hash) == 0)
			{
				return;
			}
			for (int k = 0; k < 52; k++)
			{

				generateWrd[2] = alphabet[k];
				comp = crypt(generateWrd, "50");

				if (strcmp(comp, hash) == 0)
				{
					return;
				}
			}
		}
	}
}
void thirdCase(char *generateWrd, string hash, string alphabet)
{
	for (int i = 0; i < 52; i++)
	{
		generateWrd[0] = alphabet[i];
		string comp = crypt(generateWrd, "50");
		if (strcmp(comp, hash) == 0)
		{
			return;
		}

		for (int j = 0; j < 52; j++)
		{

			generateWrd[1] = alphabet[j];
			comp = crypt(generateWrd, "50");
			if (strcmp(comp, hash) == 0)
			{
				return;
			}

			for (int k = 0; k < 52; k++)
			{

				generateWrd[2] = alphabet[k];
				comp = crypt(generateWrd, "50");
				if (strcmp(comp, hash) == 0)
				{
					return;
				}
				for (int l = 0; l < 52; l++)
				{
					generateWrd[3] = alphabet[l];
					comp = crypt(generateWrd, "50");

					if (strcmp(comp, hash) == 0)
					{
						return;
					}
				}
			}
		}
	}
}