#include "monty.h"

/**
 * isNumber - checks if a string is a number
 * @str_n: string to check
 *
 * Return: 1 if its a number, 0 otherwise.
 */
int isNumber(char str_n[])
{
        int i = 0;

        if (str_n[0] == '-')
                str_n[0] = '0';
        for (i = 0; str_n[i]; i++)
                if (!isdigit(str_n[i]))
                        return (0);
        return (1);
}
