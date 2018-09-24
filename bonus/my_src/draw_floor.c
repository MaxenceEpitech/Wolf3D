/*
** draw_floor.c for draw_floor in /home/Max/Documents/delivery/wolf3d/bonus/my_src
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Sat May 27 14:22:06 2017 fourrier maxence
** Last update Sat Jun 10 01:12:34 2017 fourrier maxence
*/

#include "my.h"

sfVector2f	get_floor(t_ray *ray)
{
  sfVector2f	floor;

  if (ray->wall_side == 0 && ray->dir.x > 0)
    {
      floor.x = ray->map.x;
      floor.y = ray->map.y + ray->wallx;
    }
  else if (ray->wall_side == 0 && ray->dir.x < 0)
    {
      floor.x = ray->map.x + 1.0;
      floor.y = ray->map.y + ray->wallx;
    }
  else if (ray->wall_side == 1 && ray->dir.y > 0)
    {
      floor.x = ray->map.x + ray->wallx;
      floor.y = ray->map.y;
    }
  else
    {
      floor.x = ray->map.x + ray->wallx;
      floor.y = ray->map.y + 1.0;
    }
  return (floor);
}

double		get_weight(t_ray *ray, double cdist)
{
  double	weight;
  double	distwall;

  if (ray->wall_side == 0)
    distwall = (ray->map.x - ray->pos.x + (1 - ray->step.x) / 2) / ray->dir.x;
  else
    distwall = (ray->map.y - ray->pos.y + (1 - ray->step.y) / 2) / ray->dir.y;
  weight = cdist / distwall;
  return (weight);
}

void		my_draw_wall(t_ray *ray, t_all *all, int i)
{
  sfVector2i	tex;
  int		y;

  tex = get_tex_x(ray, ray->wall_side, ray->height, ray->step);
  y = ray->draw.x;
  while (y < ray->draw.y)
    {
      tex = get_tex_y(ray, ray->height, tex, y);
      draw_line(my_color((int)tex.x, (int)tex.y, get_color(all, ray)),
		create_vector_i(y, i), ray->wall_side, all);
      y++;
    }
}

void		draw_floor(t_all *all, sfVector2i pos,
			   sfVector2i tfloor, int x)
{
  int		y;

  y = 17;
  my_put_pixel(all->graph->framebuffer, pos.x, pos.y,
	       all->color[x][tfloor.x][tfloor.y]);
  if (x == 17)
    y = 27;
  if (x == 18)
    y = 28;
  my_put_pixel(all->graph->framebuffer, pos.x, SCREEN_HEIGHT - pos.y,
	       all->color[y][tfloor.x][tfloor.y]);
}

void		my_draw_floor(t_ray *ray, t_all *all, int i)
{
  sfVector2f	floor;
  sfVector2f	cfloor;
  double	distWall;
  double	currentDist;
  double	weight;
  int		y;

  floor = get_floor(ray);
  if (ray->draw.y < 0)
    ray->draw.y = SCREEN_HEIGHT;
  y = ray->draw.y + 1;
  while (y < SCREEN_HEIGHT)
    {
      currentDist = SCREEN_HEIGHT / (2.0 * y - SCREEN_HEIGHT);
      weight = get_weight(ray, currentDist);
      cfloor.x = weight * floor.x + (1.0 - weight) * ray->pos.x;
      cfloor.y = weight * floor.y + (1.0 - weight) * ray->pos.y;
      draw_floor(all, create_vector_i(i, y),
                 create_vector_i((int)(cfloor.x * TEX_WIDTH) % TEX_WIDTH,
                                 (int)(cfloor.y * TEX_HEIGHT) % TEX_HEIGHT),
		 all->game->map[(int)cfloor.x][(int)cfloor.y]);
      y++;
    }
}
