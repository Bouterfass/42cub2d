#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "raycasting.h"
# include "get_next_line.h"
# include "mlx.h"
# include <math.h>
//# include "mlx_int.h"

# define R_LEFT	        65361
# define R_RIGHT	    65363
# define FORWARD_Z	    122
# define BACK_S		    115
# define RIGHT_D		100
# define LEFT_Q		    113
# define RAD            0.0174532925


# define RED            0x00ff4040
# define WHITE          0x00c6e2ff
# define BLUE           0x000B329F
# define PI             3.141592653589793
# define RSPEED         0.009817477042

typedef struct s_mapinfo
{
    int     rx;
    int     ry;
    char    *notext;
    char    *sotext;
    char    *wetext;
    char    *eatext;
    char    *sprite;
    int     floorcol[3];
    int     ceilingcol[3];   
    char    **map;
    int     mapx;
    int     mapy;
    int     errmap[9];
    char    *file;
    int     fd;
} t_mapinfo;


typedef struct s_game
{
    void		*img_ptr;
	int	        *data; 
	int			size_l;
	int			bpp;
	int			endian;
    void		*img_ptr2;
	int	        *data2; 

    void        *mlx_ptr;
    void        *mlx_win;
    t_player    *player;
    t_mapinfo   *map;
    t_screen    *scr;

    int         forward;
    int         back;
    int         right;
    int         left;
    int         r_right;
    int         r_left;

    double      dirx; 
    double      diry;
    double      planx;
    double      plany;
    double      rayx;
    double      rayy;  

    double a;
    double b;

} t_game;

void    *malloczero(size_t size);
int     ft_strlen(const char *s);
char    *trimstr(const char *line, const char *set);
int     is_digit(char c);
int     get_number(const char *str, int i, int j, t_mapinfo *map);
int     has_spaces(const char *str);
int     white_space(char c);
int     empty_line(const char *str);
void    init_mapinfo(t_mapinfo *map);
char    **ft_split(char const *s, char c);
int     getresolution(const char *line, t_mapinfo *map);
int     getnotext(const char *str, t_mapinfo *map);
int     getsotext(const char *str, t_mapinfo *map);
int     getwetext(const char *str, t_mapinfo *map);
int     geteatext(const char *str, t_mapinfo *map);
int     getsprite(const char *str, t_mapinfo *map);
int     getfloorcol(const char *str, t_mapinfo *map);
int     getceilingcol(const char *str, t_mapinfo *map);
void    getmap(const char *str, t_mapinfo *map);
int     getinfo(const char *line, t_mapinfo *map);
int	    ft_atoi(const char *string);
void    print_mapinfo(t_mapinfo *map);
int     check_map(t_mapinfo *map);
int     isolated_space(t_mapinfo *map, int x, int y);
int     is_nseo(char c);
int     count_nseo(t_mapinfo *map);
int     count_zero(t_mapinfo *map);
void     retrieve_info(int ac, char **av, t_mapinfo *map);
void    init_screen(t_screen *scr);
void    my_mlx_pixel_put(t_game *g, int x, int y, int color);
void    display_map(t_game *g);
void    display_grid(t_game *g);
void    draw_player(int x, int y, int color, t_game *g);
void    malloc_game(t_game *g);
void    get_player_start(t_game *g);
void    get_scale(t_game *g);
void    draw_dir(t_game *g);
void    draw_plan(t_game* g);
void    draw_rays(t_game *g);

#endif 