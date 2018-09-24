/*
** move_enemy.c for move_enemy in /home/Max/Documents/delivery/wolf3d/bonus/my_src
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Sun May 28 18:59:28 2017 fourrier maxence
** Last update Fri Jun  9 11:01:29 2017 fourrier maxence
*/

#include "my.h"

int		no_wall_enemy(t_all *all, sfVector2f dir,
			      sfVector2f delta, int i)
{
  double	dist;
  sfVector2f	pos;

  dist = sqrt((delta.x * delta.x) + (delta.y * delta.y));
  pos.x = all->sprite[i]->pos.x;
  pos.y = all->sprite[i]->pos.y;
  while (dist >= 1)
    {
      delta.x = all->player->pos.x - pos.x;
      delta.y = all->player->pos.y - pos.y;
      dist = sqrt((delta.x * delta.x) + (delta.y * delta.y));
      if (!can_move(all->game->map[(int)pos.x][(int)pos.y]))
	return (0);
      pos.x += dir.x * 0.1;
      pos.y += dir.y * 0.1;
    }
  return (1);
}

int		check_move_enemy(t_all *all, int i)
{
  if (all->sprite[i]->color == SOLIDER_C
      && (i != 6 || all->addr.x == 0 || all->addr.y == 0)
      || all->sprite[i]->color == SOLIDER_F_C)
    return (1);
  return (0);
}

void		walk_enemy(t_all *all, float dist,
			   sfVector2f delta, int i)
{
  sfVector2f	dir;

  dir.x = delta.x / dist;
  dir.y = delta.y / dist;
  if (no_wall_enemy(all, dir, delta, i))
    {
      if (dist >= 7)
	{
	  all->sprite[i]->pos.x += MONSTER_SPEED * dir.x;
	  all->sprite[i]->pos.y += MONSTER_SPEED * dir.y;
	}
      else
	enemy_can_fire(all, i);
    }
}

void		move_enemy(t_all *all)
{
  sfVector2f	delta;
  double	dist;
  int		i;

  i = 0;
  while (all->sprite[i] != NULL)
    {
      if (check_move_enemy(all, i))
	{
	  delta.x = all->player->pos.x - all->sprite[i]->pos.x;
	  delta.y = all->player->pos.y - all->sprite[i]->pos.y;
	  dist = sqrt((delta.x * delta.x) + (delta.y * delta.y));
	  walk_enemy(all, dist, delta, i);
	}
      i++;
    }
}
