#include "../includes/cub3d.h"



void get_scale(t_game *g)
{
    int scale;
    int ver;
    int hor;
    
    g->scr = (t_screen *)malloczero(sizeof(t_screen));
    if (g->map->mapx > g->map->mapy)
        scale = g->map->mapx;
    else
        scale = g->map->mapy;
    ver = g->map->rx / scale;
    hor = g->map->ry / scale;
    if (ver > hor)
        ver = hor;
    else 
        hor = ver;
 
    g->scr->scaleX = ver;
    g->scr->scaleY = hor;
    /*printf("X = %d\n", g->scr->scaleX);
    printf("Y = %d\n", g->scr->scaleY);*/
}