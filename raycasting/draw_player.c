#include "../includes/cub3d.h"

void draw_player(int x, int y, int color, t_game *g)
{
    int i;
    int j;
    int tmpx;
    int tmpy;

    i = 0;
    j = 0;
    g->player = (t_player*)malloczero(sizeof(t_player));

    g->player->x = x;
    g->player->y = y;
    printf("pllllx %d\n", g->player->x);
    while (i < g->scr->scaleX / 2)
    {
        while (j < g->scr->scaleY / 2)
        {
            tmpy = (i + g->player->y);
            tmpx = (j + g->player->x);
            my_mlx_pixel_put(g, tmpy, tmpx, color);
            j++;
        }
        i++;
        j = 0;
    }
}

