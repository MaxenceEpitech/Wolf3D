/*
** gun.c for gun in /home/Max/Documents/delivery/wolf3d/bonus/my_src
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Fri Jun  2 09:51:23 2017 fourrier maxence
** Last update Sat Jun 10 01:21:47 2017 fourrier maxence
*/

#include "my.h"

int		pos_gun(t_all *all)
{
  if (all->player->pos.x <= GUN_X + 0.7
      && all->player->pos.x >= GUN_X - 0.7
      && all->player->pos.y <= GUN_Y + 0.7
      && all->player->pos.y >= GUN_Y - 0.7
      && all->hud->gun == 0)
    return (1);
  return (0);
}

void		put_gun(t_all *all)
{
  sfVector2f	pos;
  int		i;

  pos.x = SCREEN_WIDTH - 322;
  pos.y = SCREEN_HEIGHT;
  all->hud->gun = 1;
  i = 0;
  while (i < 20)
    {
      sfSprite_setPosition(all->hud->sprite[GUN_ID], pos);
      all->sprite[G_ID]->pos.x = -1;
      draw_all(all);
      sfRenderWindow_drawSprite(all->graph->window, all->graph->sprite, NULL);
      sfRenderWindow_drawSprite(all->graph->window,
                                all->hud->sprite[GUN_ID], NULL);
      draw_blood(all);
      if (all->hud->helmet == 1)
	draw_helmet(all);
      sfRenderWindow_display(all->graph->window);
      usleep(10000);
      pos.y -= 10;
      i++;
    }
}
