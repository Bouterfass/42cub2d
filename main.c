#include "includes/cub3d.h"


/*
int player_move(int key, t_player *p)
{
    if (key == 65)
    {
        p->x += 1;
    }
    return (0);
}


int             main(int ac, char **av)
{
    void    *mlx;
    void    *mlx_win;
    t_mapinfo *m;
    t_data  img;

    m = (t_mapinfo *)malloczero(sizeof(t_mapinfo));
    retrieve_info(ac, av, m);
    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, m->rx, m->ry, "CUB3D");
    img.img = mlx_new_image(mlx, m->rx, m->ry);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                 &img.endian);
    display_grid(m, img);
    mlx_key_hook(mlx_win, player_move, (void *)0);
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);

    return (0);
}

*/

int player_move(int key, void *params)
{
    t_game *game;

    game = (t_game*)params;
  
    if (key == ZZZ)
    {
        game->player->x += 10;
        draw_player(game->player->x, game->player->y, 0x00349721, game);
       
    }
    return (0);
}


int             main(int ac, char **av)
{
    
    t_game *g;

    g = (t_game *)malloczero(sizeof(t_game));
    g->map = (t_mapinfo *)malloczero(sizeof(t_mapinfo));
    retrieve_info(ac, av, g->map);
    g->mlx = mlx_init();
    g->mlx_win = mlx_new_window(g->mlx, g->map->rx, g->map->ry, "CUB3D");
    g->img = mlx_new_image(g->mlx, g->map->rx, g->map->ry);
    g->addr = mlx_get_data_addr(g->img, &(g->bits_per_pixel), &(g->line_length),
                                 &(g->endian));
    display_grid(g);
    mlx_key_hook(g->mlx_win, player_move, g);
    mlx_put_image_to_window(g->mlx, g->mlx_win, (g->img), 0, 0);
    mlx_loop(g->mlx);

    return (0);
}
