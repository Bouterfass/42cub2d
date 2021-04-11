#include "../includes/cub3d.h"



int isolated_space(t_mapinfo *map, int x, int y)
{
    int j;
    int left;
    int right;

    j = y;
    left = 0;
    right = 0;
    while (j >= 0)
    {
        if (map->map[x][j] == '1' || map->map[x][j] == '0')
            left = 1;
        j--;
    }
    j = y;
    while (j < map->mapx)
    {
        if (map->map[x][j] == '1' || map->map[x][j] == '0')
            right = 1;
        j++;
    }
   // printf("\nleft = %d && right = %d\n", left, right);
    return (left && right);
}
