/*
** raycast_buffer.c for raycast_buffer in /home/Max/Documents/delivery/wolf3d/bonus/my_src
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Tue Jun  6 14:33:31 2017 fourrier maxence
** Last update Sat Jun 10 01:26:12 2017 fourrier maxence
*/

#include "my.h"

double		*malloc_zbuffer()
{
  double	*zbuffer;

  if ((zbuffer = malloc(sizeof(double) * (SCREEN_WIDTH + 1))) == NULL)
    return (NULL);
  return (zbuffer);
}

void		write_zbuffer(t_ray *ray, double *zbuffer, int i)
{
  if (ray->wall_side == 0)
    zbuffer[i] = fabs((ray->map.x - ray->pos.x
		       + (1 - ray->step.x) / 2) / ray->dir.x);
  else
    zbuffer[i] = fabs((ray->map.y - ray->pos.y
		       + (1 - ray->step.y) / 2) / ray->dir.y);
}

int		end_raycast(t_all *all, t_ray *ray, double *zbuffer)
{
  if ((my_draw_enemy(ray, all, zbuffer)) == -1)
    return (-1);
  move_enemy(all);
  free(zbuffer);
  free(ray);
  return (0);
}
