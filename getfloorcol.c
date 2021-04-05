#include "getnextline/get_next_line.h"
#include "cub3d.h"

int     has_spaces(const char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (white_space(str[i]))
            return (1);
        i++;
    }
    return (0);
}

int     get_number(const char *str, int i, int j, t_mapinfo *map)
{
    int neg;

    neg = 0;
    str = str + i;
    map->floorcol[j] = 0;
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
        map->floorcol[j] = map->floorcol[j] * 10 + *str - 48;
        str++;
        i++;
    }
    neg == 1 ? map->floorcol[j] = map->floorcol[j] * -1 : 0;
    return (i);
}

int     getfloorcol(const char *str, t_mapinfo *map)
{
    char *s;
    int i;

    i = 0;
    s = trimstr(str + 1," ");
    if (!is_digit(*s) || !s || has_spaces(s))
        return (3);
    i = get_number(s ,i, 0, map);
    i = get_number(s, i, 1, map);
    i = get_number(s, i, 2, map);
    if ((map->floorcol[0] < 0 || map->floorcol[0] > 255)
        || (map->floorcol[1] < 0 || map->floorcol[1] > 255)
        || (map->floorcol[2] < 0 || map->floorcol[2] > 255))
        return (3);
    return (0);
}