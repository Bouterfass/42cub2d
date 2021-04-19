#include "../includes/cub3d.h"



void        draw_rays(t_game *g)
{


    int tmpx = 0;
    int tmpy = 0;
    int dpxf = 0;
    int dpyf = 0;
  
   
    int hit = 0;
    int scalex = g->map->mapx * g->scr->scaleX - 1;
    int scaley = g->map->mapy * g->scr->scaleY - 1;


    int x = 0;
    int y = 0;


   //printf("scaley %d\n", scaley);
   while (x < (100) && y < (100)) 
    {
   
        dpxf = ((int)g->player->x + g->dirx*(x)) / g->scr->scaleX;
        dpyf = ((int)g->player->y + g->diry*(y)) / g->scr->scaleY;

        tmpx = (g->player->x + g->dirx*x);
        tmpy = (g->player->y + g->diry*y);

     
            if (g->map->map[dpxf][dpyf] == '0' && hit != 1)
            {
                
                    g->data[(int)((tmpx) * g->map->rx + (tmpy))] = 0x002ECC71;
    
            }
        else 
            hit = 1;
          
        y++;
        x++;
   

    }

    double angle = -0.8;
    x = 0;
    y = 0;
    double dx = g->dirx;
    double dy = g->diry;
    double olddirx = dx;
    int hitb = 0;

    while (angle < 0.8)
    {
        dx = g->dirx;
        dy = g->diry;
        olddirx = dx;
        dx = cos(angle)*dx - sin(angle)*dy;
        dy = olddirx*sin(angle) + dy*cos(angle);
        
        while (x < (100) && y < (100)) 
        {
   
            dpxf = ((int)g->player->x + dx*(x)) / g->scr->scaleX;
            dpyf = ((int)g->player->y + dy*(y)) / g->scr->scaleY;

            tmpx = (g->player->x + dx*x);
            tmpy = (g->player->y + dy*y);
            
            if (g->map->map[dpxf][dpyf] == '0' || is_nseo(g->map->map[dpxf][dpyf]))
            {
                g->data[(int)((tmpx) * g->map->rx + (tmpy))] = 0x007D3C98;
            } 

            y++;
            x++;
        }
        x = 0;
        y = 0;
        angle += RAD;
    }

}
   