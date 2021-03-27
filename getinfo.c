#include "getnextline/get_next_line.h"
#include "cub3d.h"

void getinfo(const char *line, t_mapinfo *map)
{
    char *str;

    str = trimstr(line, " ");
    if (str[0] == 'R')
        getresolution(str, map);
    else if (str[0] == 'N' && str[1] == 'O')
        getnotext(str, map);
    else if (str[0] == 'S' && str[1] == 'O')
        getsotext(str, map);
    else if (str[0] == 'W' && str[1] == 'E')
        getwetext(str, map);
    else if (str[0] == 'E' && str[1] == 'A')
        geteatext(str, map);
    else if (str[0] == 'S' && str[1] == ' ')
        getsprite(str, map);
    else if (str[0] == 'F')
        getfloorcol(str, map);
    else if (str[0] == 'C')
        getceilingcol(str, map);
    else if (line[0] == '0' || line[0] == '1' || line[0] == ' ')
        getmap(line, map);
    else 
        printf("Error\nCan't identify this information:\n\"%s\".", line);
}


