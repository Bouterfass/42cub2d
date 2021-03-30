#include "getnextline/get_next_line.h"
#include "cub3d.h"


int     is_mapline(const char *str)
{
    int i;

    i = 0;

    if (empty_line(str) == 1)
        return (0);
    while (str[i]){
        if (str[i] != '0' && str[i] != '1' && str[i] != ' '
            && str[i] != '2' && str[i] != 'N'
            && str[i] != 'S' && str[i] != 'E'
            && str[i] != 'W')
            return (0);
        i++;
    }
    return (1);
}

void    fill_map(char **map, int fd, int x, int y)
{
    char *line;
    int i;
    int j;

    i = 0;
    j = 0;
    line = NULL;

    while (get_next_line(fd, &line))
    {
        while (is_mapline(line))
        {
            while (i < y)
            {
                while (j < x)
                {
                    map[i][j] = line[j];
                    j++;
                //   fill_line(map[i], ft_strlen(*map[i], j));
                }
                map[i][j] = '\0';
                i++;
                j = 0;
            }
        }
    }
}

void    malloc_map(char **map, int x, int y, int fd)
{
    int i;

    i = 0;
    map = (char **)malloc((sizeof(char *) * y) + 1);
    while (i++ < y)
        map[i] = (char *)malloc((sizeof(char *) * x) + 1);
    fill_map(map, fd, x, y);

}


void    getmapsize(int fd, const char *l, t_mapinfo *map)
{
    int x;
    int y;
    char *line;

    x = 0;
    y = 0;
    line = NULL;
    if (is_mapline(l))
    {
        ft_strlen(l) > x ? x = ft_strlen(l) : 0;
        y++;
    }
    while(get_next_line(fd, &line) > 0)
    {
        if (is_mapline(line))
        {
            ft_strlen(line) > x ? x = ft_strlen(line) : 0;
            y++;
        }
        free(line);
        line = NULL;
    }
    close(fd);
    printf("\n[%d, %d]\n", x , y);
    malloc_map(map->map, x, y, fd);
}





void getinfo(int fd, const char *line, t_mapinfo *map)
{
   /* char *str;

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
    else */
    
    if (is_mapline(line))
        getmapsize(fd, line, map);
    else 
        printf("\nError\nCan't identify this information:\n\"%s\".", line);
}


