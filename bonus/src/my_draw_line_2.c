/*
** my_draw_line_2.c for my_draw_line_2 in /home/Max/Documents/delivery/wireframe/lib/my
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Fri Apr 14 23:53:58 2017 fourrier maxence
** Last update Sun May 21 17:13:49 2017 fourrier maxence
*/

#include "my.h"

int		draw_line_5(t_my_framebuffer *framebuffer, sfVector2i from,
			    sfVector2i to, sfColor color)
{
  int		dx;
  int		dy;
  int		v;

  dx = to.x - from.x;
  dy = to.y - from.y;
  v = dx;
  if (dx < 0 && dy > 0 && -dx >= dy)
    {
      dx *= 2;
      dy *= 2;
      while (from.x != to.x)
        {
          my_put_pixel(framebuffer, from.x, from.y, color);
          v +=dy;
          if (v >= 0)
            {
              v += dx;
              from.y++;
            }
          from.x--;
        }
      return (1);
    }
  return (0);
}

int		draw_line_6(t_my_framebuffer *framebuffer, sfVector2i from,
			    sfVector2i to, sfColor color)
{
  int		dx;
  int		dy;
  int		v;

  dx = to.x - from.x;
  dy = to.y - from.y;
  v = dy;
  if (dx < 0 && dy > 0 && -dx < dy)
    {
      dx *= 2;
      dy *= 2;
      while (from.y != to.y)
        {
          my_put_pixel(framebuffer, from.x, from.y, color);
          v += dx;
          if (v <= 0)
            {
              v += dy;
              from.x--;
            }
          from.y++;
        }
      return (1);
    }
  return (0);
}

int		draw_line_7(t_my_framebuffer *framebuffer, sfVector2i from,
			    sfVector2i to, sfColor color)
{
  int		dx;
  int		dy;
  int		v;

  dx = to.x - from.x;
  dy = to.y - from.y;
  v = dx;
  if (dx < 0 && dy < 0 && dx <= dy)
    {
      dx *= 2;
      dy *= 2;
      while (from.x != to.x)
        {
          my_put_pixel(framebuffer, from.x, from.y, color);
          v -= dy;
          if (v >= 0)
            {
              v += dx;
              from.y--;
            }
          from.x--;
        }
      return (1);
    }
  return (0);
}

int		draw_line_8(t_my_framebuffer *framebuffer, sfVector2i from,
			    sfVector2i to, sfColor color)
{
  int		dx;
  int		dy;
  int		v;

  dx = to.x - from.x;
  dy = to.y - from.y;
  v = dy;
  if (dx < 0 && dy < 0 && dx > dy)
    {
      dx *= 2;
      dy *= 2;
      while (from.y != to.y)
        {
          my_put_pixel(framebuffer, from.x, from.y, color);
          v -= dx;
          if (v >= 0)
            {
              v += dy;
              from.x--;
            }
          from.y--;
        }
      return (1);
    }
  return (0);
}
