#include "cub3d.h"
#include "getnextline/get_next_line.h"


void print_map(char **str)
{
   /* int i = 0;
    int j = 0;

    while (i++ < 5)
    {           
        while (j++ < ft_strlen(str[i]) + 1) 
             printf("%c", str[i][j]);
        printf("\n");
        j = 0;
    }*/
    printf("\n");
    for(int i = 0; i < 5 ; i++)
    {
        for (int j = 0; j < 25; j++)
            printf("%c", str[i][j]);
        printf("\n");
    }
}