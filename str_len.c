#include "so_long.h"

int str_len(char *str)
{
    int i = 0;
    while(str[i] != '\0')
        i++;
    return i;
}