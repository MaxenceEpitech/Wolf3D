/*
** draw_line.c for draw_line in /home/Max/Documents/delivery/wireframe/lib/my
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Fri Apr 14 23:44:35 2017 fourrier maxence
** Last update Sun May 21 17:32:41 2017 fourrier maxence
*/

#include "my.h"

void		my_draw_line(t_my_framebuffer *framebuffer,
                             sfVector2i from, sfVector2i to, sfColor color)
{
  my_put_pixel(framebuffer, from.x, from.y, color);
  my_put_pixel(framebuffer, to.x, to.y, color);
  if (line_is_horizontal(framebuffer, from, to, color))
    return;
  if (line_is_vertical(framebuffer, from, to, color))
    return;
  if (draw_line_1(framebuffer, from, to, color))
    return;
  if (draw_line_2(framebuffer, from, to, color))
    return;
  if (draw_line_3(framebuffer, from, to, color))
    return;
  if (draw_line_4(framebuffer, from, to, color))
    return;
  if (draw_line_5(framebuffer, from, to, color))
    return;
  if (draw_line_6(framebuffer, from, to, color))
    return;
  if (draw_line_7(framebuffer, from, to, color))
    return;
  if (draw_line_8(framebuffer, from, to, color))
    return;
}

int		draw_line_1(t_my_framebuffer *framebuffer, sfVector2i from,
			    sfVector2i to, sfColor color)
{
  int		dx;
  int		dy;
  int		v;

  dx = to.x - from.x;
  dy = to.y - from.y;
  v = dx;
  if (dx > 0 && dy > 0 && dx >= dy)
    {
      dx *= 2;
      dy *= 2;
      while (from.x != to.x)
	{
          my_put_pixel(framebuffer, from.x, from.y, color);
          v = v - dy;
          if (v < 0)
            {
              v += dx;
       	      from.y++;
	    }
          from.x++;
        }
      return (1);
    }
  return (0);
}

int		draw_line_2(t_my_framebuffer *framebuffer, sfVector2i from,
			    sfVector2i to, sfColor color)
{
  int		dx;
  int		dy;
  int		v;

  dx = to.x - from.x;
  dy = to.y - from.y;
  v = dy;
  if (dx > 0 && dy > 0 && dx < dy)
    {
      dx *= 2;
      dy *= 2;
      while (from.y != to.y)
        {
          my_put_pixel(framebuffer, from.x, from.y, color);
          v -= dx;
          if (v < 0)
            {
              v += dy;
              from.x++;
            }
          from.y++;
        }
      return (1);
    }
  return (0);
}

int		draw_line_3(t_my_framebuffer *framebuffer, sfVector2i from,
			    sfVector2i to, sfColor color)
{
  int		dx;
  int		dy;
  int		v;

  dx = to.x - from.x;
  dy = to.y - from.y;
  v = dx;
  if (dx > 0 && dy < 0 && dx >= -dy)
    {
      dx *= 2;
      dy *= 2;
      while (from.x != to.x)
        {
          my_put_pixel(framebuffer, from.x, from.y, color);
          v += dy;
          if (v < 0)
            {
              v += dx;
              from.y--;
            }
          from.x++;
        }
      return (1);
    }
  return (0);
}

int		draw_line_4(t_my_framebuffer *framebuffer, sfVector2i from,
			    sfVector2i to, sfColor color)
{
  int		dx;
  int		dy;
  int		v;

  dx = to.x - from.x;
  dy = to.y - from.y;
  v = dy;
  if (dx > 0 && dy < 0 && dx < -dy)
    {
      dx *= 2;
      dy *= 2;
      while (from.y != to.y)
        {
          my_put_pixel(framebuffer, from.x, from.y, color);
          v += dx;
          if (v > 0)
            {
              v += dy;
              from.x++;
            }
          from.y--;
        }
      return (1);
    }
  return (0);
}
