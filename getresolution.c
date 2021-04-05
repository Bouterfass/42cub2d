#include "getnextline/get_next_line.h"
#include "cub3d.h"


int is_digit(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}


int getresolution_x(const char *str, t_mapinfo *map)
{
    str++;
    while (white_space(*str))
        str++;
    while (*str != ' ' && *str)
    {
        if (is_digit(*str))
        {
            map->rx = map->rx * 10 + *str - 48;
            str++;
        }
    else 
        return (1);
    }
    return (0);
}


int getresolution_y(const char *str, t_mapinfo *map)
{
    str++;
    while (white_space(*str) && *str)
        str++;
    if (is_digit(*str))
        while (is_digit(*str) && *str)
            str++;
    while (white_space(*str) && *str)
        str++;
    if (is_digit(*str) && *str)
    {
        while (is_digit(*str) && *str)
        {
            map->ry = map->ry * 10 + *str - 48;
            str++;
        }
    }
    else 
        return (1);
    return (0);
}

int getresolution(const char *str, t_mapinfo *map)
{
    int rx; 
    int ry;

    rx = getresolution_x(str, map);
    ry = getresolution_y(str, map);

    if (map->rx == 0 || map->ry == 0)
        return (1);
    return (rx || ry);
}