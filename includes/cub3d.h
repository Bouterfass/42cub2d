#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "raycasting.h"
# include "get_next_line.h"
# include "mlx.h"
# include "mlx_int.h"

# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define ZZZ 122
# define SSS 115
# define QQQ 113
# define DDD 100
# define ESC 65307


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
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;

    void        *mlx;
    void        *mlx_win;
    t_player    *player;
    t_mapinfo   *map;
    t_screen    *scr;

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

#endif 