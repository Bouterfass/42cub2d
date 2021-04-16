#include "../includes/cub3d.h"



int check_row(t_mapinfo *map, int x, int y)
{
    int j;
    int left;
    int right;

    j = y;
    left = 0;
    right = 0;
    while (j >= 0)
    {
        if (map->map[x][j] == '1')
            left = 1;
        j--;
    }
    j = y;
    while (j < map->mapx)
    {
        if (map->map[x][j] == '1')
            right = 1;
        j++;
    }
   // printf("\nleft = %d && right = %d\n", left, right);
    return (left && right);
}


int check_col(t_mapinfo *map, int x, int y)
{
    int j;
    int up;
    int down;

    j = x;
    up = 0;
    down = 0;
    while (j >= 0)
    {
        if (map->map[j][y] == '1')
            up = 1;
        j--;
    }
    j = x;
    while (j < map->mapy)
    {
        if (map->map[j][y] == '1')
            down = 1;
        j++;
    }
  //  printf("\nup = %d && down = %d\n", up, down);
    return (up && down);
}


int is_nseo(char c)
{
    if (c == 'N' || c == 'S'
        || c == 'E' || c == 'W')
        return (1);
    return (0);
}

int is_closed(t_mapinfo *map)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < map->mapy)
    {
        while (j < map->mapx)
        {
            if (map->map[i][j] == ' ' && isolated_space(map, i, j))
                map->map[i][j] = '0';
            if (map->map[i][j] == '0' || map->map[i][j] == '2'
                || is_nseo(map->map[i][j])) 
                if (!check_row(map, i, j) || !check_col(map, i, j))
                    return (8);
            j++;
        }
        j = 0;
        i++;
    }
    return (0);
}



int check_map(t_mapinfo *map)
{
    if (is_closed(map) != 0 || (count_zero(map) < 2) 
        || (count_nseo(map) != 1))
        return (8);
    return (0);
}

