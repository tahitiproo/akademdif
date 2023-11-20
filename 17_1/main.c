#include <stdio.h>

int main()
{
    char string[101] = "";
    scanf("%100[^\n]", string);

    spaces(string);

    printf("^%s^\n", string);

    return 0;
}

void spaces(char* string)
{
    char* read = string, * write = string;
    do
    {
        if (*read == ' ')
        {
            if (!(write == string))
            {
                if (*read)
                {
                    if (!(*(read + 1) == ' ' || !*(read + 1)))
                        *write++ = *read;
                }
            }
        }
        else
            *write++ = *read;
    } 
    while (*read++);
}