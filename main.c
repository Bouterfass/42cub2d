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


int key_press(int key, t_game *g)
{
    if (key == FORWARD_Z)
        g->forward = 1;
    if (key == BACK_S)
        g->back = 1;
    if (key == RIGHT_D)
        g->right = 1;
    if (key == LEFT_Q)
        g->left = 1;
    if (key == R_RIGHT)
        g->r_right = 1;
    if (key == R_LEFT)
        g->r_left = 1;
    
    return (1);
}

int key_release(int key, t_game *g)
{
    printf("key %d\n", key);
    if (key == FORWARD_Z)
        g->forward = 0;
    if (key == BACK_S)
        g->back = 0;
    if (key == RIGHT_D)
        g->right = 0;
    if (key == LEFT_Q)
        g->left = 0;
    if (key == R_RIGHT)
        g->r_right = 0;
    if (key == R_LEFT)
        g->r_left = 0;
    
    return (1);
}

void ft_forward_back(t_game *g)
{
   // printf("g->map->map[%d][%d] = %c\n",g->player->x  / g->scr->scaleX, g->player->y / g->scr->scaleY, g->map->map[g->player->x / g->scr->scaleX][g->player->y / g->scr->scaleY]);
    int dpxf = ((int)g->player->x + g->dirx*10) / g->scr->scaleX;
    int dpyf = ((int)g->player->y + g->diry*10) / g->scr->scaleY;
    int dpxb = ((int)g->player->x - g->dirx*10) / g->scr->scaleX;
    int dpyb = ((int)g->player->y - g->diry*10) / g->scr->scaleY;
    if (g->forward == 1 && (g->map->map[dpxf][dpyf] == '0' || is_nseo(g->map->map[dpxf][dpyf])))
    {
        g->player->x += g->dirx*2;
        g->player->y += g->diry*2;
    }
    if (g->back == 1 && (g->map->map[dpxb][dpyb] == '0' || is_nseo(g->map->map[dpxb][dpyb])))
    {
        g->player->x -= g->dirx*2;
        g->player->y -= g->diry*2;
    }
}

void ft_right_left(t_game *g)
{
   double olddirx = g->dirx;
    double oldplanx = g->planx;
   if (g->right == 1)
   {   
        g->dirx = cos(-PI/32)*g->dirx - sin(-PI/32)*g->diry;
        g->diry = olddirx * sin(-PI/32) + g->diry*cos(-PI/32);
        g->planx = cos(-PI/32)*g->planx - sin(-PI/32)*g->plany;
        g->plany = oldplanx * sin(-PI/32) + g->plany*cos(-PI/32);
      
   }

    if (g->left == 1)
   {   
        g->dirx = cos(PI/32)*g->dirx - sin(PI/32)*g->diry;
        g->diry = olddirx * sin(PI/32) + g->diry*cos(PI/32);
        g->planx = cos(PI/32)*g->planx - sin(PI/32)*g->plany;
        g->plany = oldplanx * sin(PI/32) + g->plany*cos(PI/32);
      
   }
   /*if (g->left == 1)
   {
       g->dirx = (cos((-0.033*1.8)/2)*olddirx) - (sin((-0.033*1.8)/2)*);
       g->diry = (sin((-0.033*1.8)/2)*olddirx) + (cos((-0.033*1.8)/2)*);
   }*/
}



int ft_raycasting(t_game *g)
{
    display_grid(g);
    draw_player(g->player->x, g->player->y, 0x00349721, g);
     //printf("blabla");
    draw_dir(g);
    draw_plan(g);
    draw_rays(g);
    mlx_put_image_to_window(g->mlx_ptr, g->mlx_win,
			g->img_ptr, 0, 0);
    ft_forward_back(g);
    ft_right_left(g);
}




int main(int ac, char **av)
{
    t_game *g;

   
    g = (t_game *)malloczero(sizeof(t_game));
    g->map = (t_mapinfo *)malloczero(sizeof(t_mapinfo));
    g->player = (t_player*)malloczero(sizeof(t_player));
    retrieve_info(ac, av, g->map);
    get_player_start(g);
    g->mlx_ptr = mlx_init();

    g->mlx_win = mlx_new_window(g->mlx_ptr, g->map->rx, g->map->ry, "CUB3D");
    g->img_ptr = mlx_new_image(g->mlx_ptr, g->map->rx, g->map->ry);

    g->data = mlx_get_data_addr(g->img_ptr, &(g->bpp), &(g->size_l),
		&(g->endian));
 
    //display_grid(g);
    mlx_hook(g->mlx_win, 2, 1L << 0, key_press, g);
    mlx_loop_hook(g->mlx_ptr, ft_raycasting, g);
    mlx_hook(g->mlx_win, 3, 1L << 1, key_release, g);
    //mlx_put_image_to_window(g->mlx_ptr, g->mlx_win, g->img_ptr, 0, 0);
    mlx_loop(g->mlx_ptr);
    return (0);
}