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
/*
int player_move(int key, void *params)
{
    t_game *game;

    game = (t_game*)params;
  
    if (key == ZZZ)
    {
        //game->player->x += 10;
        my_mlx_pixel_put(game, 100, 100, 0x00349721);
       
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
*/

/*
int	main(void)
{
	t_game	*game; //Here I first create my struct that will contains all the "MLX stuff"
	int		count_w;
	int		count_h;

    game = (t_game *)malloczero(sizeof(t_game));
    game->map = (t_mapinfo *)malloczero(sizeof(t_mapinfo));
    game->img = (t_img *)malloczero(sizeof(t_img));
    game->player = (t_player *)malloczero(sizeof(t_player));
	count_h = -1;
	//First you need to call mlx_init and store its return value.
	game->mlx_ptr = mlx_init();
	//Now do the same with mlx_new_window
	game->mlx_win = mlx_new_window(game->mlx_ptr, 800, 600, "A simple example");
	//One more time with mlx_new_image
	game->img->img_ptr = mlx_new_image(game->mlx_ptr, 800, 600);
	
	game->img->data = (int *)mlx_get_data_addr(game->img->img_ptr, &(game->img->bpp), &(game->img->size_l),
		&(game->img->endian));
	
	while (++count_h < 600)
	{
		count_w = -1;
		while (++count_w < 800)
		{
			if (count_w % 2)
			{
                mlx_pixel_put(game->mlx_ptr, game->mlx_win, count_w, count_h,0xFFFFFF);
				game->img->data[count_h * 800 + count_w] = 0xFFFFFF;
            }
			else
            {
                mlx_pixel_put(game->mlx_ptr, game->mlx_win, count_w, count_h,0);
				game->img->data[count_h * 800 + count_w] = 0;
            }
		}
	}
	//Now you just have to print the image using mlx_put_image_to_window !
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img->img_ptr, 0, 0);
	mlx_loop(game->mlx_ptr);
	return (0);
}
*/
int main(int ac, char **av)
{
    t_game *g;

   
    g = (t_game *)malloczero(sizeof(t_game));
    g->map = (t_mapinfo *)malloczero(sizeof(t_mapinfo));

    retrieve_info(ac, av, g->map);
    g->mlx_ptr = mlx_init();

    g->mlx_win = mlx_new_window(g->mlx_ptr, g->map->rx, g->map->ry, "CUB3D");
    g->img_ptr = mlx_new_image(g->mlx_ptr, g->map->rx, g->map->ry);

    g->data = mlx_get_data_addr(g->img_ptr, &(g->bpp), &(g->size_l),
		&(g->endian));
 

    display_grid(g);
    mlx_put_image_to_window(g->mlx_ptr, g->mlx_win, g->img_ptr, 0, 0);
    mlx_loop(g->mlx_ptr);
    return (0);
}