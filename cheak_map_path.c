#include "so_long.h"

int cheak_map_path(char *s)
{
    int i = 0;
    int len = str_len(s) - 4;
    char *the_path = ".ber";
    while(s[len] != '\0')
    {
        if(s[len] != the_path[i])
            return 1;
        len++;
        i++;
    }
    return 0;
    
}