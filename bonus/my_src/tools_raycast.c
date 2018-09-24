/*
** tools_raycast.c for tools_raycast in /home/Max/Documents/delivery/wolf3d/bonus/my_src
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Wed May 24 21:37:50 2017 fourrier maxence
** Last update Tue Jun  6 14:31:51 2017 fourrier maxence
*/

#include "my.h"

sfVector2i	create_draw(int height)
{
  sfVector2i	vec;

  vec.x = -height / 2 + SCREEN_HEIGHT / 2;
  vec.y = height / 2 + SCREEN_HEIGHT / 2;
  if (vec.x < 0)
    vec.x = 0;
  if (vec.y >= SCREEN_HEIGHT)
    vec.y = SCREEN_HEIGHT - 1;
  return (vec);
}

sfVector2i	get_tex_x(t_ray *ray, int side, int height, sfVector2i step)
{
  sfVector2i	tex;
  double	dist;
  double	wallx;

  if (side == 0)
    dist = (ray->map.x - ray->pos.x + (1 - step.x) / 2) / ray->dir.x;
  else
    dist = (ray->map.y - ray->pos.y + (1 - step.y) / 2) / ray->dir.y;
  if (side == 0)
    wallx = ray->pos.y + dist * ray->dir.y;
  else
    wallx = ray->pos.x + dist * ray->dir.x;
  wallx -= floor((wallx));
  tex.x = (int)(wallx * (double)(TEX_WIDTH));
  if (side == 0 && ray->dir.x > 0)
    tex.x = TEX_WIDTH - tex.x - 1;
  if (side == 1 && ray->dir.y < 0)
    tex.x = TEX_WIDTH - tex.x - 1;
  ray->wallx = wallx;
  return (tex);
}

sfVector2i	get_tex_y(t_ray *ray, int height, sfVector2i tex, int c)
{
  tex.y = (2 * c - SCREEN_HEIGHT + height) * (TEX_HEIGHT / 2) / height;
  return (tex);
}

void		draw_line(sfColor color, sfVector2i x,
			  int side, t_all *all)
{
  sfUint32	_int;

  my_put_pixel(all->graph->framebuffer, (int)x.y, (int)x.x, color);
}

sfColor		**get_color(t_all *all, t_ray *ray)
{
  return (all->color[all->game->map[ray->map.x][ray->map.y]]);
}
