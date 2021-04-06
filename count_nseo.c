#include "cub3d.h"
#include "getnextline/get_next_line.h"


int count_nseo(t_mapinfo *map)
{
    int i;
    int j;
    int count;

    i = 0;
    j = 0;
    count = 0;
    while (i < map->mapy)
    {
        while (j < map->mapx)
        {
            if (is_nseo(map->map[i][j]))
                count++;
            j++;
        }
        j = 0;
        i++;
    }
    return (count);
}

int count_zero(t_mapinfo *map)
{
    int i;
    int j;
    int count;

    i = 0;
    j = 0;
    count = 0;
    while (i < map->mapy)
    {
        while (j < map->mapx)
        {
            if (map->map[i][j] == '0')
                count++;
            j++;
        }
        j = 0;
        i++;
    }
    return (count);
}
