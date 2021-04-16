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
            g->data[tmpx * g->map->rx + tmpy] = color;
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
                g->data[j * g->map->rx + i] = 0x00FFFFFF;
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
                g->data[j * g->map->rx + i] = 0x00FFFFFF;
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
            if (g->map->map[i][j] == '0' || is_nseo(g->map->map[i][j]))
                draw_wall(i * g->scr->scaleX, j * g->scr->scaleY, 0x00c6e2ff, g);
           /* if (g->map->map[i][j] == 'N')
            {
                g->player = (t_player*)malloczero(sizeof(t_player));
                g->player->x = i * g->scr->scaleX;
                g->player->y = j * g->scr->scaleY;
                draw_wall(i * g->scr->scaleX, j * g->scr->scaleY, 0x00c6e2ff, g);
                draw_player(g->player->x, g->player->y, 0x00349721, g);
            }*/
            j++;
        }
        i++;
        j = 0;
    }
}

void            display_grid(t_game *g)
{
    get_scale(g);

    display_map(g);

    display_grid_hor(g->scr->scaleY, g);

    display_grid_ver(g->scr->scaleX, g);
 
}


