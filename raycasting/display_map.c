#include "../includes/cub3d.h"

void        draw_wall(int x, int y, int color, t_game *g)
{
    int i;
    int j;
    int tmpx;
    int tmpy;


    i = 0;
    j = 0;
    while (i < g->scr->scaleX)
    {
        while (j < g->scr->scaleY)
        {
            tmpy = (i + y);
            tmpx = (j + x);
            my_mlx_pixel_put(g, tmpy, tmpx, color);
            j++;
        }
        i++;
        j = 0;
    }
}


void             display_grid_ver(int ver, t_game *g)
{
    int i; 
    int j;

    i = ver;
    j = 0;
    if (ver > 1)
    {
        while (i < g->map->rx)
        {
            
            while (j < g->map->ry)
            {
                my_mlx_pixel_put(g, i, j, 0x00FFFFFF);
                j++;
            }
        j = 0;
        i += ver;
        }
    }
}

void             display_grid_hor(int hor, t_game *g)
{
    int i; 
    int j;

    i = 0;
    j = hor;
    if (hor > 1)
    {
        while (j < g->map->ry)
        {
            while (i < g->map->rx)
            {
                my_mlx_pixel_put(g, i, j, 0x00FFFFFF);
                i++;
            }
        j += hor;
        i = 0;
        }
    }
}


void        display_map(t_game *g)
{
    int i;
    int j;

    i = 0;
    j = 0;

    while (i < g->map->mapy)
    {
        while (j < g->map->mapx)
        {
            if (g->map->map[i][j] == '1')
                draw_wall(i * g->scr->scaleX, j * g->scr->scaleY, 0x00ff4040, g);
            if (g->map->map[i][j] == '0')
                draw_wall(i * g->scr->scaleX, j * g->scr->scaleY, 0x00c6e2ff, g);
            if (g->map->map[i][j] == 'N')
            {
                draw_wall(i * g->scr->scaleX, j * g->scr->scaleY, 0x00c6e2ff, g);
                draw_player(i * g->scr->scaleX, j * g->scr->scaleY, 0x00349721, g);
            }
            j++;
        }
        i++;
        j = 0;
    }
}

void            display_grid(t_game *g)
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
    

    printf("scale = %d\n", scale);
    display_map(g);
    display_grid_hor(hor, g);
    display_grid_ver(ver, g);
}


