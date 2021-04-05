#include "getnextline/get_next_line.h"
#include "cub3d.h"



char    *no_texture(const char *str, t_mapinfo *map)
{
    int i;

    i = 2;
    while (white_space(str[i]) && str[i])
        i++;
    if (str[i] == '.' && str[i + 1] == '/')
        map->notext = ft_substr(str, i, ft_strlen(str) - i);

    return (map->notext);
}

int getnotext(const char *str, t_mapinfo *map)
{

    char *s;
    int i;

    i = 0;
    s = no_texture(str, map); 
    
    if (!s)
        return (2);
    while (s[i])
    {
        if (white_space(s[i]))
            return (2);
        i++;
    }
    return(0);
}