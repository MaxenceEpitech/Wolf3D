/*
** check_fire.c for check_fire in /home/Max/Documents/delivery/wolf3d/bonus/my_src
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Fri Jun  2 14:01:18 2017 fourrier maxence
** Last update Sat Jun 10 01:00:55 2017 fourrier maxence
*/

#include "my.h"

int		sprite_touch(t_all *all, sfVector2f map)
{
  int		i;

  i = 0;
  while (all->sprite[i] != NULL)
    {
      if (all->sprite[i]->pos.x >= map.x - 0.3
	  && all->sprite[i]->pos.x <= map.x + 0.3
	  && all->sprite[i]->pos.y >= map.y - 0.3
	  && all->sprite[i]->pos.y <= map.y + 0.3
	  && all->sprite[i]->color == SOLIDER_C)
	{
	  sfMusic_play(all->sound[5]);
	  all->sprite[i]->color = DEAD_S_C_0 + 1;
	  return (1);
	}
      i++;
    }
  return (0);
}

int		check_dir_fire(t_all *all)
{
  sfVector2f	pos;
  int		hit;

  hit = 0;
  pos.x = all->player->pos.x;
  pos.y = all->player->pos.y;
  sfMusic_play(all->sound[0]);
  while (hit == 0)
    {
      pos.x += all->player->dir.x * 0.1;
      pos.y += all->player->dir.y * 0.1;
      if (!can_move(all->game->map[(int)pos.x][(int)pos.y]))
	{
	  hit = 1;
	}
      if (sprite_touch(all, pos))
	{
	  hit = 1;
	}
    }
}
