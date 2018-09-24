/*
** fire.c for fire in /home/Max/Documents/delivery/wolf3d/bonus/my_src
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Thu Jun  1 16:50:39 2017 fourrier maxence
** Last update Tue Jun  6 14:29:49 2017 fourrier maxence
*/

#include <time.h>

#include "my.h"

int			check_fire(t_all *all)
{
  if (all->hud->gun == 1 && all->hud->ammo >= 1)
    return (1);
  return (0);
}

void			draw_fire(t_all *all)
{
  sfVector2f		pos;

  pos.x = SCREEN_WIDTH - 370;
  pos.y = SCREEN_HEIGHT - 300;
  sfSprite_setPosition(all->hud->sprite[SHOOT_ID], pos);
  if (all->hud->helmet == 0)
    {
      sfRenderWindow_drawSprite(all->graph->window,
				all->hud->sprite[SHOOT_ID], NULL);
      draw_hud(all);
    }
  else
    {
      sfRenderWindow_drawSprite(all->graph->window,
				all->hud->sprite[H_SHOOT_ID], NULL);
    }
  sfRenderWindow_display(all->graph->window);
}

int			can_fire_again(t_all *all, long nb)
{
  if (all->hud->time + TIME_FIRE < nb)
    return (1);
  return (0);
}

int			fire(t_all *all)
{
  sfVector2f		pos;
  struct timespec	ts;
  long			nb;

  timespec_get(&ts, TIME_UTC);
  nb = (long)(ts.tv_sec * 1000000000L + ts.tv_nsec) / 10000000;
  if (can_fire_again(all, nb) == 0)
    return (0);
  all->hud->time = nb;
  all->hud->ammo = all->hud->ammo - 1;
  draw_fire(all);
  if ((check_dir_fire(all)) == -1)
    return (-1);
  return (0);
}
