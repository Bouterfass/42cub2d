#include "includes/cub3d.h"

int     main(void)
{
    void    *mlx_ptr;
    void    *win_ptr;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 1920, 700, "Hello world!");
    mlx_loop(mlx_ptr);
}       
/*


int main (int ac, char **av)
{
    t_mapinfo *m;
    
    m = (t_mapinfo *)malloczero(sizeof(t_mapinfo));
    retrieve_info(ac, av, m);
    return (0);
}
*/