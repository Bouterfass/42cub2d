#include "../includes/cub3d.h"

void malloc_game(t_game *g)
{
    g = (t_game *)malloczero(sizeof(t_game));
    g->map = (t_mapinfo *)malloczero(sizeof(t_mapinfo));
  
    g->player = (t_player *)malloczero(sizeof(t_player));
    g->scr = (t_screen *)malloczero(sizeof(t_screen));
 
}