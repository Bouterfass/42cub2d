#include "../includes/cub3d.h"



void        draw_rays(t_game *g)
{
    int tmpx = 0;
    int tmpy = 0;
    for (int i = 0; i < g->planx * 50 ; i++)
    {
        for (int j = 0; j < g->plany * 50 ; j++)
        {
            tmpx = (g->player->x  + i);
            tmpy = (g->player->y  + i);
              g->data[(int)((tmpx) * g->map->rx
                        + (tmpy))] = 0x00000000;
        }
          
    }   
}

   