
/*
** draw_health.c for draw_health in /home/Max/Documents/delivery/wolf3d/bonus/my_src
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Tue Jun  6 23:58:41 2017 fourrier maxence
** Last update Tue Jul 18 19:53:07 2017 fourrier maxence
*/

#include "my.h"

int		draw_100_(t_all *all, int nb)
{
  sfVector2f	vec;
  int		rest;

  rest = nb / 100;
  vec.x = 40;
  vec.y = SCREEN_HEIGHT - 60;
  sfSprite_setPosition(all->hud->heal[rest], vec);
  sfRenderWindow_drawSprite(all->graph->window,
                            all->hud->heal[rest],
                            NULL);
  return (nb - (rest * 100));
}

int		draw_10_(t_all *all, int nb)
{
  sfVector2f	vec;
  int		rest;

  rest = nb / 10;
  if (nb < 10)
    rest = 0;
  vec.x = 80;
  vec.y = SCREEN_HEIGHT - 60;
  sfSprite_setPosition(all->hud->heal[rest], vec);
  sfRenderWindow_drawSprite(all->graph->window,
                            all->hud->heal[rest],
                            NULL);
  if (nb < 10)
    return (nb);
  return (nb - (rest * 10));
}

int		draw_0_(t_all *all, int nb)
{
  sfVector2f	vec;

  vec.x = 120;
  vec.y = SCREEN_HEIGHT - 60;
  sfSprite_setPosition(all->hud->heal[nb], vec);
  sfRenderWindow_drawSprite(all->graph->window,
                            all->hud->heal[nb],
                            NULL);
  return (0);
}
