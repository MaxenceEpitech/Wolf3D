/*
** helmet.c for helmet in /home/Max/Documents/delivery/wolf3d/bonus/my_src
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Thu Jun  1 00:06:39 2017 fourrier maxence
** Last update Thu Jun  8 18:39:39 2017 fourrier maxence
*/

#include <time.h>

#include "my.h"

int		pos_helmet(t_all *all)
{
  if (all->player->pos.x <= HELMET_X + 0.7
      && all->player->pos.x >= HELMET_X - 0.7
      && all->player->pos.y <= HELMET_Y + 0.7
      && all->player->pos.y >= HELMET_Y - 0.7
      && all->hud->helmet == 0)
    return (1);
  return (0);
}

void		put_helmet(t_all *all)
{
  sfVector2f	pos;
  int		i;

  pos.x = -50;
  pos.y = -450;
  all->hud->helmet = 1;
  i = 1;
  while (i < 9)
    {
      sfSprite_setPosition(all->hud->sprite[i], pos);
      all->sprite[H_ID]->pos.x = -1;
      draw_all(all);
      sfRenderWindow_drawSprite(all->graph->window, all->graph->sprite, NULL);
      draw_blood(all);
      sfRenderWindow_drawSprite(all->graph->window,
				all->hud->sprite[i], NULL);
      sfRenderWindow_display(all->graph->window);
      usleep(200000);
      i++;
    }
}
