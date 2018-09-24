/*
** mouse.c for mouse in /home/Max/Documents/delivery/wolf3d/bonus/my_src
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Tue Jun  6 00:26:00 2017 fourrier maxence
** Last update Thu Jun  8 13:12:01 2017 fourrier maxence
*/

#include "my.h"

int		check_mouse(t_all *all)
{
  sfVector2i	pos;
  int		x;

  pos = sfMouse_getPositionRenderWindow(all->graph->window);
  x = pos.x - 900;
  if (x < 0)
    all->player = rotate_left(all->player, -x / 10);
  else if (x != 0)
    all->player = rotate_right(all->player, x / 10);
  if (x != 0)
    {
      pos.x = 900;
      pos.y = 500;
      sfMouse_setPositionRenderWindow(pos, all->graph->window);
    }
}
