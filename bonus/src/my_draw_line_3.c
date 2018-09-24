/*
** my_draw_line_3.c for my_draw_line_3 in /home/Max/Documents/delivery/wireframe/lib/my
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Sat Apr 15 00:12:45 2017 fourrier maxence
** Last update Sun May 21 15:53:22 2017 fourrier maxence
*/

#include "my.h"

int		line_is_vertical(t_my_framebuffer *framebuffer,
				 sfVector2i from, sfVector2i to, sfColor color)
{
  if ((to.y - from.y) == 0 && (to.x - from.x) < 0)
    {
      while (from.x != to.x)
	{
	  my_put_pixel(framebuffer, from.x, from.y, color);
	  from.x--;
	}
      return (1);
    }
  if ((to.y - from.y) == 0 && (to.x - from.x) > 0)
    {
      while (from.x != to.x)
	{
	  my_put_pixel(framebuffer, from.x, from.y, color);
	  from.x++;
	}
      return (1);
    }
  return (0);
}

int		line_is_horizontal(t_my_framebuffer *framebuffer,
				   sfVector2i from, sfVector2i to, sfColor color)
{  
  if ((to.x - from.x) == 0 && (to.y - from.y) > 0)
    {
      while (from.y != to.y)
	{
	  my_put_pixel(framebuffer, from.x, from.y, color);
	  from.y++;
	}
      return (1);
    }
  if ((to.x - from.x) == 0 && (to.y - from.y) < 0)
    {
      while (from.y != to.y)
	{
	  my_put_pixel(framebuffer, from.x, from.y, color);
	  from.y--;
	}
      return (1);
    }
  return (0);
}
