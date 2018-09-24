/*
** move_joff.c for move_joff in /home/Max/Documents/delivery/wolf3d/bonus/my_src
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Thu Jun 15 14:08:35 2017 fourrier maxence
** Last update Thu Jun 15 15:30:19 2017 fourrier maxence
*/

#include "my.h"

void		move_joff(t_all *all)
{
  double	dist;
  sfVector2f	dir;
  sfVector2f	delta;

  delta.x = all->player->pos.x - all->sprite[JOFF_C]->pos.x;
  delta.y = all->player->pos.y - all->sprite[JOFF_C]->pos.y;
  dist = sqrt((delta.x * delta.x) + (delta.y * delta.y));
  dir.x = delta.x / dist;
  dir.y = delta.y / dist;
  if (dist > 1.3 && no_wall_enemy(all, dir, delta, JOFF_C))
    {
      all->sprite[JOFF_C]->pos.x += JOFF_SPEED * dir.x;
      all->sprite[JOFF_C]->pos.y += JOFF_SPEED * dir.y;
    }
}

void		draw_victory(t_all *all)
{
  sfSprite	*sprite;
  sfVector2f	vec;

  vec.x = 0;
  vec.y = 150;
  sfMusic_stop(all->sound[6]);
  sfMusic_play(all->sound[9]);
  if ((sprite = load_picture("texture/victory.png")) == NULL)
    return;
  sfSprite_setPosition(sprite, vec);
  sfRenderWindow_drawSprite(all->graph->window,
                            sprite, NULL);
  sfRenderWindow_display(all->graph->window);
  while (sfKeyboard_isKeyPressed(sfKeyEscape) == 0);
  clear_ressources(all);
  my_putstr("01110110 01101001 01100011 01110100 01101111 01110010 01111001");
  exit(0);
}

int		has_won(t_all *all)
{
  if (all->sprite[JOFF_C]->pos.x >= 3.5 - 4
      && all->sprite[JOFF_C]->pos.x <= 3.5 + 4
      && all->sprite[JOFF_C]->pos.y >= 58.9 - 4
      && all->sprite[JOFF_C]->pos.y <= 59.9 + 4
      && all->player->pos.x >= 3.5 - 2
      && all->player->pos.x <= 3.5 + 2
      && all->player->pos.y >= 58.9 - 2
      && all->player->pos.y <= 58.9 + 2)
    {
      draw_victory(all);
      return (1);
    }
  return (0);
}
