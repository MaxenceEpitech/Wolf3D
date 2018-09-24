/*
** raycast.c for raycast in /home/Max/Documents/delivery/wolf3d/src
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Tue May 23 10:29:17 2017 fourrier maxence
** Last update Fri Jun  9 13:10:06 2017 fourrier maxence
*/

#include "my.h"

sfVector2i	get_step(sfVector2f dir)
{
  sfVector2i	step;

  if (dir.x < 0)
    step.x = -1;
  else
    step.x = 1;
  if (dir.y < 0)
    step.y = -1;
  else
    step.y = 1;
  return (step);
}

sfVector2f	get_side(sfVector2f dir, sfVector2f pos, sfVector2f delta)
{
  sfVector2f	side;

  if (dir.x < 0)
    side.x = (pos.x - ((int)pos.x)) * delta.x;
  else
    side.x = (((int)pos.x) + 1.0 - pos.x) * delta.x;
  if (dir.y < 0)
    side.y = (pos.y - ((int)pos.y)) * delta.y;
  else
    side.y = (((int)pos.y) + 1.0 - pos.y) * delta.y;
  return (side);
}

void		get_all(sfVector2f *side, sfVector2i *pos_map,
			sfVector2f delta, sfVector2i step)
{
  if ((*side).x < (*side).y)
    {
      (*side).x = (*side).x + delta.x;
      (*pos_map).x = (*pos_map).x + step.x;
    }
  else
    {
      (*side).y = (*side).y + delta.y;
      (*pos_map).y += (*pos_map).y + step.y;
    }
}

sfVector2f	init_all(sfVector2i *pos_map, sfVector2f pos,
			 sfVector2f *dir, float direction)
{
  sfVector2f	delta;

  (*pos_map).x = (int)pos.x;
  (*pos_map).y = (int)pos.y;
  (*dir).x = cos(M_PI * direction / 180);
  (*dir).y = sin(M_PI * direction / 180);
  delta.x = sqrt(1 + ((*dir).y * (*dir).y) / ((*dir).x * (*dir).x));
  delta.y = sqrt(1 + ((*dir).x * (*dir).x) / ((*dir).y * (*dir).y));
  return (delta);
}

float		raycast(sfVector2f pos, float direction,
			int **map, sfVector2i mapsize)
{
  sfVector2i	pos_map;
  sfVector2f	dir;
  sfVector2f	delta;
  sfVector2f	side;
  sfVector2i	step;
  int		hit;

  delta = init_all(&pos_map, pos, &dir, direction);
  side = get_side(dir, pos, delta);
  step = get_step(dir);
  hit = 0;
  while (hit == 0)
    {
      get_all(&side, &pos_map, delta, step);
      if (map[pos_map.x][pos_map.y] != 0)
        hit = 1;
      if (pos_map.x >= mapsize.x || pos_map.x < 0
          || pos_map.y >= mapsize.y || pos_map.y < 0)
        return (0);
    }
  if (side.x < side.y)
    return ((pos_map.x - pos.x + (1 - step.x) / 2) / dir.x);
  else
    return ((pos_map.y - pos.y + (1 - step.y) / 2) / dir.y);
}
