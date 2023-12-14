#include "main.h"

/**
 * stringtok - a function to divide the command into single strings
 * @str: the command to be divided
 * @del: the delimiter
 */

char *stringtok(char *str, char *del)
{
        static char *last;
        char *tok;

        if (str != NULL)
                last = str;
        else if (last == NULL)
                return (NULL);
        tok = last;
        while (*last != '\0')
        {
                char *d =del;

                while (*d != '\0')
                {
                        if (*last == *d)
                        {
                                last = '\0';
                                last++;
                                if (*tok != '\0')
                                        return (tok);
                                else
                                {
                                        tok = last;
                                        break;
                                }
                        }
                        d++;
                }
                last++;
        }
        if (*tok == '\0')
                return (NULL);
        last = NULL;
        free(last);
        return (tok);
}
