#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>


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
int    getresolution(const char *line, t_mapinfo *map);
int    getnotext(const char *str, t_mapinfo *map);
int    getsotext(const char *str, t_mapinfo *map);
int    getwetext(const char *str, t_mapinfo *map);
int    geteatext(const char *str, t_mapinfo *map);
int    getsprite(const char *str, t_mapinfo *map);
int    getfloorcol(const char *str, t_mapinfo *map);
int    getceilingcol(const char *str, t_mapinfo *map);
void    getmap(const char *str, t_mapinfo *map);
int    getinfo(const char *line, t_mapinfo *map);
int		ft_atoi(const char *string);
void    print_mapinfo(t_mapinfo *map);

#endif 