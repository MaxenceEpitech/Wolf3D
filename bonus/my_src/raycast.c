/*
** raycast.c for raycast in /home/Max/Documents/delivery/wolf3d/bonus/my_src
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Fri May 19 18:53:00 2017 fourrier maxence
** Last update Tue Jun  6 17:54:41 2017 fourrier maxence
*/

#include "my.h"

t_ray		*init_ray(t_player *player, int i)
{
  t_ray		*ray;

  if ((ray = malloc(sizeof(t_ray))) == NULL)
    return (NULL);
  ray->pos.x = player->pos.x;
  ray->pos.y = player->pos.y;
  ray->dir.x = player->dir.x + player->plane.x
    * (2 * i / (double)SCREEN_WIDTH - 1);
  ray->dir.y = player->dir.y + player->plane.y
    * (2 * i / (double)SCREEN_WIDTH - 1);
  ray->map.x = (int)ray->pos.x;
  ray->map.y = (int)ray->pos.y;
  ray->delta.x = sqrt(1 + (ray->dir.y * ray->dir.y)
		       / (ray->dir.x * ray->dir.x));
  ray->delta.y = sqrt(1 + (ray->dir.x * ray->dir.x)
		       / (ray->dir.y * ray->dir.y));
  return (ray);
}

sfVector2i		set_step(t_ray *ray)
{
  sfVector2i	step;

  if (ray->dir.x < 0)
    {
      step.x = -1;
      ray->side.x = (ray->pos.x - ray->map.x) * ray->delta.x;
    }
  else
    {
      step.x = 1;
      ray->side.x = (ray->map.x + 1.0 - ray->pos.x) * ray->delta.x;
    }
  if (ray->dir.y < 0)
    {
      step.y = -1;
      ray->side.y = (ray->pos.y - ray->map.y) * ray->delta.y;
    }
  else
    {
      step.y = 1;
      ray->side.y = (ray->map.y + 1.0 - ray->pos.y) * ray->delta.y;
    }
  return (step);
}

int		get_side(t_ray *ray, sfVector2i step, int **map)
{
  int		hit;
  int		side;

  hit = 0;
  while (hit == 0)
    {
      if (ray->side.x < ray->side.y)
	{
	  ray->side.x += ray->delta.x;
	  ray->map.x += step.x;
	  side = 0;
	}
      else
	{
	  ray->side.y += ray->delta.y;
	  ray->map.y += step.y;
	  side = 1;
	}
      if (!can_move(map[ray->map.x][ray->map.y]))
	hit = 1;
    }
  return (side);
}

int		get_line_height(t_ray *ray, sfVector2i step, int side)
{
  double	dist;

  if (side == 0)
    dist = (ray->map.x - ray->pos.x + (1 - step.x) / 2) / ray->dir.x;
  else
    dist = (ray->map.y - ray->pos.y + (1 - step.y) / 2) / ray->dir.y;
  return ((int)(SCREEN_HEIGHT / dist));
}

int		my_raycast(t_all *all)
{
  t_ray		*ray;
  int		i;
  double	*zbuffer;

  i = 0;
  if ((zbuffer = malloc_zbuffer()) == NULL)
    return (-1);
  while (i < SCREEN_WIDTH)
    {
      if ((ray = init_ray(all->player, i)) == NULL)
	return (-1);
      ray->step = set_step(ray);
      ray->wall_side = get_side(ray, ray->step, all->game->map);
      ray->height = get_line_height(ray, ray->step, ray->wall_side);
      ray->draw = create_draw(ray->height);
      my_draw_wall(ray, all, i);
      write_zbuffer(ray, zbuffer, i);
      my_draw_floor(ray, all, i);
      i++;
    }
  if (end_raycast(all, ray, zbuffer) == -1)
    return (-1);
  return (0);
}
