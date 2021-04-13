#include "../includes/cub3d.h"



void            my_mlx_pixel_put(t_game *g, int x, int y, int color)
{
    char    *dst;

   // dst = g->addr + (y * g->line_length + x * (g->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}
