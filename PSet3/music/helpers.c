// Helper functions for music

#include <cs50.h>
#include <math.h>
#include <string.h>

#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int x = fraction[0] - '0';
    int y = fraction[2] - '0';

    if(x == 1)
    {
        switch(y)
        {
            case 8: return 1;break;
            case 4: return 2;break;
            case 2: return 4;break;
        }
    }
    else if(x == 3)
    {
        return 3;
    }
    return 0;


}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    int initial_freq = 440;
    int octave = 0;
    char letter;
    int main_operator = 0;
    int result_freq = 0;
    bool isAddition = false;
    bool isSharp = false;
    bool isFlat = false;

    if(strlen(note) == 2)
    {
        letter = (note[0]);
        octave = note[1] - '0';
    }
    else if(strlen(note) == 3)
    {
        letter = note[0];
        octave = note[2] - '0';
        char addition = note[1];
        isAddition = true;
        if(addition == '#')
        {
            isSharp = true;
        }
        else
        {
            isFlat = true;
        }
    }

    if(octave < 4)
    {
        int differance = 4 - octave;
        for(int i = 0; i < differance; i++)
        {
            initial_freq /= 2;
        }
    }
    else if(octave >= 4)
    {
        int differance = octave - 4;
        for(int i = 0; i < differance; i++)
        {
            initial_freq *= 2;
        }
    }

    switch(letter)
        {
            case 'G':
            {
                main_operator = 2;
                if(isAddition)
                {
                    if(isSharp)
                    {
                        main_operator = 1;
                    }
                    else if(isFlat)
                    {
                        main_operator = 3;
                    }
                }
            }
            break;

            case 'F':
            {
                main_operator = 4;
                if(isAddition)
                {
                    if(isSharp)
                    {
                        main_operator = 3;
                    }
                    else if(isFlat)
                    {
                        main_operator = 5;
                    }
                }
            }
            break;
            case 'E': main_operator = 5;break;
            case 'D':
            main_operator = 7;
                if(isAddition)
                {
                    if(isSharp)
                    {
                        main_operator = 6;
                    }
                    else if(isFlat)
                    {
                        main_operator = 8;
                    }
                }
            break;
            case 'C':
            main_operator = 9;
                if(isAddition)
                {
                    if(isSharp)
                    {
                        main_operator = 8;
                    }
                }
            break;
            case 'A':
            main_operator = 12;
                if(isAddition)
                {
                    if(isSharp)
                    {
                        main_operator = 1;
                    }
                    else if(isFlat)
                    {
                        main_operator = 1;
                    }
                }
            break;
            case 'B':
            {
                main_operator = 2;
                if(isFlat)
                {
                    main_operator = 1;
                }
            }
            break;
        }

        if(letter != 'B' && letter != 'A')
        {
            return result_freq = initial_freq / pow(2.0, main_operator/12.0);
        }
        else
        {
           if(letter == 'A' && !isAddition)
           {
               return result_freq = initial_freq;
           }
           return result_freq = initial_freq * pow(2.0, main_operator/12.0);
        }

}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if(strcmp(s,"") == 0)
    {
        return true;
    }
    return false;
}
