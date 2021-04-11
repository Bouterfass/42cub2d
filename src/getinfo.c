
#include "../includes/cub3d.h"


int     is_mapline(const char *str)
{
    int i;

    i = 0;
    if (empty_line(str) == 1 || !str)
        return (0);
    while (str[i] != '\0'){
        if (str[i] != '0' && str[i] != '1' && str[i] != ' '
            && str[i] != '2' && str[i] != 'N'
            && str[i] != 'S' && str[i] != 'E'
            && str[i] != 'W')
            return (0);
        i++;
    }
    return (1);
}


void    malloc_map(int x, int y, t_mapinfo *m)
{
    int i;

    i = 0;
    m->map = malloc((sizeof(char *) * y) + 1);
    while (i < y)
    {
        m->map[i] = malloc((sizeof(char) * x));
        i++;
    }
}

void fill_line(t_mapinfo *map, char *line, int len, int i)
{
    int j; 

    j = 0;
    while (j < map->mapx)
    { 
    if (j < len)
        map->map[i][j] = line[j];
    else
        map->map[i][j] = ' ';
    j++;
    }
}

void    fill_map(int x, int y, t_mapinfo *m)
{
    char *line;
    int i;

    int endl;
    
    endl = 1;
    i = 0;

    line = NULL;
    m->fd = open(m->file, O_RDONLY);
    malloc_map(x, y, m);
    while (endl > 0 || i < y)
    {  
        endl = get_next_line(m->fd, &line);
        if (is_mapline(line))
        {  
            fill_line(m, line, ft_strlen(line), i);
            i++;
        }
        free(line);
        line = NULL;
    }
    close(m->fd);
}

void    getmapsize(const char *l, t_mapinfo *map)
{
    char *line;
    int endl;

    endl = 1;
    line = NULL;
    if (is_mapline(l))
        ft_strlen(l) > map->mapx ? map->mapx = ft_strlen(l) : 0;
    while(endl > 0)
    {
        endl = get_next_line(map->fd, &line);
        if (is_mapline(line))
        {
            ft_strlen(line) > map->mapx ? map->mapx = ft_strlen(line) : 0;
            map->mapy++;
        }
        free(line);
        line = NULL;
    }
    fill_map(map->mapx, map->mapy, map);
}





int getinfo(const char *line, t_mapinfo *map)
{
    char *str;

    str = trimstr(line, " ");
    if (str[0] == 'R')
        map->errmap[0] = getresolution(str, map);
    else if (str[0] == 'N' && str[1] == 'O')
        map->errmap[1] = getnotext(str, map);
    else if (str[0] == 'S' && str[1] == 'O')
        map->errmap[2] = getsotext(str, map);
    else if (str[0] == 'W' && str[1] == 'E')
        map->errmap[3] = getwetext(str, map);
    else if (str[0] == 'E' && str[1] == 'A')
        map->errmap[4] = geteatext(str, map);
    else if (str[0] == 'S' && str[1] == ' ')
        map->errmap[5] = getsprite(str, map);
    else if (str[0] == 'F')
        map->errmap[6] = getfloorcol(str, map);
    else if (str[0] == 'C')
        map->errmap[7] = getceilingcol(str, map);
    else if (is_mapline(line))
    {
        getmapsize(line, map);
        map->errmap[8] = check_map(map);
    }
    return (0);
}


