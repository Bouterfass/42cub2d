
#include "../includes/cub3d.h"

char    *ea_texture(const char *str, t_mapinfo *map)
{
    int i;

    i = 2;
    while (white_space(str[i]) && str[i])
        i++;
    if (str[i] == '.' && str[i + 1] == '/')
        map->eatext = ft_substr(str, i, ft_strlen(str) - i);

    return (map->eatext);
}




int geteatext(const char *str, t_mapinfo *map)
{

    char *s;
    int i;

    i = 0;
    s = ea_texture(str, map); 
    if (!s)
        return (2);
    while (s[i++])
        if (white_space(s[i]))
            return (2);
    return(0);
}