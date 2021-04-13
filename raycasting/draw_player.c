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
            g->data[tmpy * g->map->rx + tmpx] = 0x00FF0000;
            j++;
        }
        i++;
        j = 0;
    }
}

