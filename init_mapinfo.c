#include "getnextline/get_next_line.h"
#include "cub3d.h"


void    init_mapinfo(t_mapinfo *map)
{
    map->rx = 0;
    map->ry = 0;
    map->notext = NULL;
    map->sotext = NULL;
    map->wetext = NULL;
    map->eatext = NULL;
    map->sprite = NULL;
    map->floorcol[0] = -1;
    map->floorcol[1] = -1;
    map->floorcol[2] = -1;
    map->ceilingcol[0] = -1;
    map->ceilingcol[1] = -1;
    map->ceilingcol[2] = -1;
    map->map = NULL;

    map->file = NULL;
}