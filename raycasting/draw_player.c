#include "../includes/cub3d.h"

void draw_player(int x, int y, int color, t_game *g)
{
    int i;
    int j;
    int tmpx;
    int tmpy;

    i = -8;
    j = -8;

   
    while (i < 8)
    {
        while (j < 16)
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

