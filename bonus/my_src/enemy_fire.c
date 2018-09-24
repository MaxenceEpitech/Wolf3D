/*
** enemy_fire.c for enemy_fire in /home/Max/Documents/delivery/wolf3d/bonus/my_src
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Tue Jun  6 23:06:53 2017 fourrier maxence
** Last update Thu Jun  8 18:35:53 2017 fourrier maxence
*/

#include "my.h"

void		enemy_color(t_all *all, int i)
{
  if (all->sprite[i]->fire >= 40 && all->sprite[i]->color != DEAD_SOLIDER_C)
    all->sprite[i]->color = SOLIDER_F_C;
  else if (all->sprite[i]->color != DEAD_SOLIDER_C)
    all->sprite[i]->color = SOLIDER_C;
}

void		enemy_can_fire(t_all *all, int i)
{
  int		touch;

  enemy_color(all, i);
  if (all->sprite[i]->fire >= 45)
    {
      sfMusic_play(all->sound[2]);
      touch = rand() % 100;
      if (touch >= 40)
	{
	  sfMusic_play(all->sound[1]);
	  if (all->hud->helmet == 1)
	    all->hud->hp -= (touch / 5) / 2;
	  else
	    all->hud->hp -= (touch / 5);
	}
      else
	sfMusic_play(all->sound[4]);
      all->sprite[i]->fire = 20;
    }
  else
    all->sprite[i]->fire += 1;
}
