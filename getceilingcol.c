#include "getnextline/get_next_line.h"
#include "cub3d.h"

int     get_cnumber(const char *str, int i, int j, t_mapinfo *map)
{
    int neg; 

    neg = 0;
    str = str + i;
    map->ceilingcol[j] = 0;
    if (*str == ',' || *str == ' ')
    {
        str++;
        i++;
    }
    if (*str == '-')
    {
        neg = 1;
        str++;
        i++;
    }
    while (is_digit(*str))
    {
        map->ceilingcol[j] = map->ceilingcol[j] * 10 + *str - 48;
        str++;
        i++;
    }
    neg == 1 ? map->ceilingcol[j] = map->ceilingcol[j] * -1 : 0;
    return (i);
}

int     getceilingcol(const char *str, t_mapinfo *map)
{
    char *s;
    int i;

    i = 0;
    s = trimstr(str + 1," ");
    if (!is_digit(*s) || !s || has_spaces(s))
        return (3);

    i = get_cnumber(s ,i, 0, map);
    i = get_cnumber(s, i, 1, map);
    i = get_cnumber(s, i, 2, map);
    if ((map->ceilingcol[0] < 0 || map->ceilingcol[0] > 255)
        || (map->ceilingcol[1] < 0 || map->ceilingcol[1] > 255)
        || (map->ceilingcol[2] < 0 || map->ceilingcol[2] > 255))
        return (3);
    return (0);
}