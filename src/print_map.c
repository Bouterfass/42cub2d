#include "../includes/cub3d.h"


void print_map(char **str, t_mapinfo *map)
{
    printf("\n");
    for(int i = 0; i < map->mapy ; i++)
    {
        for (int j = 0; j < map->mapx; j++)
            printf("%c", str[i][j]);
        printf("\n");
    }
}



void print_mapinfo(t_mapinfo *m)
{
    int i;

    i = 0;
    printf("resolution x = %d\n", m->rx);
    printf("resolution y = %d\n", m->ry);
    printf("notext = %s\n", m->notext);
    printf("sotext = %s\n", m->sotext);
    printf("wetext = %s\n", m->wetext);
    printf("eatext = %s\n", m->eatext);
    printf("sprite = %s\n", m->sprite);
    printf("floor colors = [%d, %d, %d]\n", m->floorcol[0], m->floorcol[1], m->floorcol[2]);
    printf("ceiling colors = [%d, %d, %d]\n", m->ceilingcol[0], m->ceilingcol[1], m->ceilingcol[2]);
    printf("errors = ");
    while (i < 9)
    {
        printf(" %d", m->errmap[i]);
        i++;
    }
    print_map(m->map, m);
}