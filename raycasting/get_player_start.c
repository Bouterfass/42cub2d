#include "../includes/cub3d.h"



void get_direction(t_game *g, char c)
{
    g->dirx = 0;
    g->diry = 0;
    if (c == 'N')
        g->dirx = -1;
    if (c == 'S')
        g->dirx = 1;
    if (c == 'W')
        g->diry = -1;
    if (c == 'E')
        g->diry = 1;
  
}


void get_plan(t_game *g, char c)
{
    if (c == 'N')
        g->plany = 0.66;
    if (c == 'S')
        g->plany = -0.66;
    if (c == 'W')
        g->planx = -0.66;
    if (c == 'E')
        g->planx = 0.66;
}


void get_player_start(t_game *g)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < g->map->mapy)
    {
        while (j < g->map->mapx)
        {
            if (is_nseo(g->map->map[i][j]))
            {
                get_scale(g);

                g->player->x = i * g->scr->scaleX;
                g->player->y = j * g->scr->scaleY;
                get_direction(g, g->map->map[i][j]);
                get_plan(g, g->map->map[i][j]);
            }
            j++;
        }
        i++;
        j = 0;
    }
}

