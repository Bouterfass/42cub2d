#include "../includes/cub3d.h"

void draw_player(int x, int y, int color, t_game *g)
{
    int i;
    int j;
    int tmpx;
    int tmpy;

    i = -g->scr->scaleX/4;
    j = -g->scr->scaleX/2;

   
    while (i < g->scr->scaleX/4)
    {
        while (j < g->scr->scaleX/2)
        {
            tmpy = (g->player->y);
            tmpx =  (g->player->x);
    
            g->data[(tmpx + i) * g->map->rx + (tmpy + j)] = 0x000B329F;
            j++;
        }
        i++;
        j = 0;
    }

    
}

