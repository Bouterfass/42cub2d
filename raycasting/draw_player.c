#include "../includes/cub3d.h"

void draw_player(int x, int y, int color, t_game *g)
{
    int i;
    int j;
    int tmpx;
    int tmpy;

    i = 0;
    j = 0;

   
    while (i < g->scr->scaleX / 2)
    {
        while (j < g->scr->scaleY / 2)
        {
            tmpy = (i + g->player->y);
            tmpx = (j + g->player->x);
            g->data[tmpx * g->map->rx + tmpy] = 0x000B329F;
            j++;
        }
        i++;
        j = 0;
    }
}

