#include "../includes/cub3d.h"



void    draw_plan(t_game* g)
{
    int tmpx = 0;
    int tmpy = 0;
    //printf("\nabs = %f && ord = %f\n", g->dirx*10, g->diry*10);
    //printf("\nabs +300 = %f && ord +300 = %f\n", g->dirx*10 + 300, g->diry*10 + 300);
    for (int i = -3; i < 3 ; i++)
    {
        for (int j = -3; j < 3; j++)
        {
            tmpx = (g->player->x + g->dirx*60 + g->planx*100);
            tmpy = (g->player->y + g->diry*60 + g->plany*100);
            g->data[(int)((tmpx + i) * g->map->rx
                            + (tmpy + j))] = 0x00406663;
        }
    }

    for (int i = -3; i < 3 ; i++)
    {
        for (int j = -3; j < 3; j++)
        {
            tmpx = (g->player->x + g->dirx*60 - g->planx*100);
            tmpy = (g->player->y + g->diry*60 - g->plany*100);
            g->data[(int)((tmpx + i) * g->map->rx
                            + (tmpy + j))] = 0x00406663;
        }
    }
}