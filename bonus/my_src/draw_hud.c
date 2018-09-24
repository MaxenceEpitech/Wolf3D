/*
** draw_hud.c for draw_hud in /home/Max/Documents/delivery/wolf3d/bonus/my_src
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Thu Jun  1 19:16:48 2017 fourrier maxence
** Last update Sat Jun 10 01:13:05 2017 fourrier maxence
*/

#include "my.h"

void		draw_helmet(t_all *all)
{
  sfVector2f	vec;

  vec.x = 0;
  vec.y = 0;
  sfSprite_setPosition(all->hud->sprite[0], vec);
  sfRenderWindow_drawSprite(all->graph->window,
			    all->hud->sprite[0], NULL);
}

void		draw_gun(t_all *all)
{
  sfVector2f	vec;

  vec.x = SCREEN_WIDTH - 252 - 70;
  vec.y = SCREEN_HEIGHT - 271 + 60;
  sfSprite_setPosition(all->hud->sprite[10], vec);
  sfRenderWindow_drawSprite(all->graph->window,
			    all->hud->sprite[10], NULL);
}

void		draw_ammo(t_all *all)
{
  int		nb;

  nb = all->hud->ammo;
  if (all->hud->ammo >= 100)
    {
      nb = draw_100(all, nb);
      nb = draw_10(all, nb);
      nb = draw_0(all, nb);
    }
  else if (all->hud->ammo < 100
	   && all->hud->ammo >= 10)
    {
      nb = draw_10(all, nb);
      nb = draw_0(all, nb);
    }
  else if (all->hud->ammo < 10 && all->hud->ammo >= 0)
    draw_0(all, nb);
}

void		draw_health(t_all *all)
{
  int		nb;

  nb = all->hud->hp;
  if (all->hud->hp >= 100)
    {
      nb = draw_100_(all, nb);
      nb = draw_10_(all, nb);
      nb = draw_0_(all, nb);
    }
  else if (all->hud->hp < 100
           && all->hud->hp >= 10)
    {
      nb = draw_10_(all, nb);
      nb = draw_0_(all, nb);
    }
  else if (all->hud->hp < 10 && all->hud->hp >= 0)
    draw_0_(all, nb);
}

void		draw_blood(t_all *all)
{
  if (all->hud->hp / 5 >= 0 && all->hud->hp / 5 <= 20)
    sfRenderWindow_drawSprite(all->graph->window,
			      all->hud->blood[all->hud->hp / 5], NULL);
}
