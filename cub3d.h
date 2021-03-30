#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>


typedef struct s_mapinfo
{
    int rx;
    int ry;
    char *notext;
    char *sotext;
    char *wetext;
    char *eatext;
    char *sprite;
    int  floorcol[3];
    int  ceilingcol[3];   
    char **map;

    char *file;

} t_mapinfo;


void    *malloczero(size_t size);
int     ft_strlen(const char *s);
char    *trimstr(const char *line, const char *set);
int     white_space(char c);
int     empty_line(const char *str);
void    init_mapinfo(t_mapinfo *map);
void    getresolution(const char *line, t_mapinfo *map);
void    getnotext(const char *str, t_mapinfo *map);
void    getsotext(const char *str, t_mapinfo *map);
void    getwetext(const char *str, t_mapinfo *map);
void    geteatext(const char *str, t_mapinfo *map);
void    getsprite(const char *str, t_mapinfo *map);
void    getfloorcol(const char *str, t_mapinfo *map);
void    getceilingcol(const char *str, t_mapinfo *map);
void    getmap(const char *str, t_mapinfo *map);
void    getinfo(int fd, const char *line, t_mapinfo *map);

void    print_map(const char **map);

#endif 