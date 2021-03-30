#include "cub3d.h"
#include "getnextline/get_next_line.h"


void print_map(const char **str)
{
    int i = 0;
    int j = 0;

    while (i++ < 50)
    {           
        while (j++ < 50) 
             printf("M[%d][%d] = %c\n", i, j, str[i][j]);
        j = 0;
    }
}