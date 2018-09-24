/*
** ammo.c for ammo$ in /home/Max/Documents/delivery/wolf3d/bonus/my_src
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Thu Jun  8 18:39:55 2017 fourrier maxence
** Last update Thu Jun  8 20:47:44 2017 fourrier maxence
*/

#include "my.h"

int		regen_hp(t_all *all)
{
  if (all->hud->hp < 100)
    all->hud->cpt += 1;
  if (all->hud->hp < 100 && all->hud->cpt >= 400)
    {
      all->hud->cpt = 0;
      if (all->hud->hp + REGEN_HP > 100)
	all->hud->hp = 100;
      else
	all->hud->hp += REGEN_HP;
    }
}

void		add_ammo(t_all *all)
{
  sfMusic_play(all->sound[8]);
  all->hud->ammo += AMMO_BOX;
}

int		pos_ammo(t_all *all)
{
  int		i;

  i = 0;
  while (all->sprite[i] != NULL)
    {
      if (all->sprite[i]->color == AMMO_C
	  && all->player->pos.x <= all->sprite[i]->pos.x + 0.7
	  && all->player->pos.x >= all->sprite[i]->pos.x - 0.7
	  && all->player->pos.y <= all->sprite[i]->pos.y + 0.7
	  && all->player->pos.y >= all->sprite[i]->pos.y - 0.7)
	{
	  all->sprite[i]->pos.x = -1;
	  return (1);
	}
      i++;
    }
  return (0);
}
