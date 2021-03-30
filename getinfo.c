#include "getnextline/get_next_line.h"
#include "cub3d.h"


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
   // m->map[y] = '\0';
}


void    fill_map(int x, int y, t_mapinfo *m)
{
    char *line;
    int i;
    int j;
    int endl = 1;
    i = 0;
    j = 0;
    line = NULL;
    m->fd = open(m->file, O_RDONLY);
    malloc_map(x, y, m);
    printf("\nmap\n");
    while (endl > 0 || i < y)
    {  
        endl = get_next_line(m->fd, &line);
        if (is_mapline(line))
        {  
            while (j < ft_strlen(line))
            {
                m->map[i][j] = line[j];
                printf("%c ", m->map[i][j]);
                j++;
            }
            printf("\n");
            //m->map[i][j] = '\0';
            i++;
            j = 0;
        }
        free(line);
        line = NULL;
    }
    close(m->fd);
}

void    getmapsize(const char *l, t_mapinfo *map)
{
    int x;
    int y;
    char *line;
    int endl;

    x = 0;
    y = 1;
    endl = 1;
    line = NULL;
    if (is_mapline(l))
        ft_strlen(l) > x ? x = ft_strlen(l) : 0;
    while(endl > 0)
    {
        endl = get_next_line(map->fd, &line);
        if (is_mapline(line))
        {
            ft_strlen(line) > x ? x = ft_strlen(line) : 0;
            y++;
        }
        free(line);
        line = NULL;
    }
    fill_map(x, y, map);
}





void getinfo(const char *line, t_mapinfo *map)
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
        getmapsize(line, map);
    else 
        printf("\nError. Can't identify this information:\n\"%s\".", line);
}


