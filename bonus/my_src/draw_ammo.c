/*
** draw_ammo.c for draw_ammo in /home/Max/Documents/delivery/wolf3d/bonus/my_src
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Fri Jun  2 22:26:01 2017 fourrier maxence
** Last update Tue Jun  6 14:28:11 2017 fourrier maxence
*/

#include "my.h"

int		draw_100(t_all *all, int nb)
{
  sfVector2f	vec;
  int		rest;

  rest = nb / 100;
  vec.x = SCREEN_WIDTH - 120;
  vec.y = SCREEN_HEIGHT - 60;
  sfSprite_setPosition(all->hud->number[rest], vec);
  sfRenderWindow_drawSprite(all->graph->window,
			    all->hud->number[rest],
			    NULL);
  return (nb - (rest * 100));
}

int		draw_10(t_all *all, int nb)
{
  sfVector2f	vec;
  int		rest;

  rest = nb / 10;
  if (nb < 10)
    rest = 0;
  vec.x = SCREEN_WIDTH - 80;
  vec.y = SCREEN_HEIGHT - 60;
  sfSprite_setPosition(all->hud->number[rest], vec);
  sfRenderWindow_drawSprite(all->graph->window,
			    all->hud->number[rest],
			    NULL);
  if (nb < 10)
    return (nb);
  return (nb - (rest * 10));
}

int		draw_0(t_all *all, int nb)
{
  sfVector2f	vec;

  vec.x = SCREEN_WIDTH - 40;
  vec.y = SCREEN_HEIGHT - 60;
  sfSprite_setPosition(all->hud->number[nb], vec);
  sfRenderWindow_drawSprite(all->graph->window,
			    all->hud->number[nb],
			    NULL);
  return (0);
}
