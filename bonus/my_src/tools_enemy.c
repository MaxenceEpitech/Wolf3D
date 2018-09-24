/*
** tools_enemy.c for tools_enemy in /home/Max/Documents/delivery/wolf3d/bonus/my_src
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Tue May 30 17:30:41 2017 fourrier maxence
** Last update Tue Jun  6 18:07:09 2017 fourrier maxence
*/

#include "my.h"

sfVector2f		*sort_sprite(t_all *all, int total)
{
  sfVector2f		*s_sprite;
  int			i;

  if ((s_sprite = malloc(sizeof(sfVector2f) * total)) == NULL)
    return (NULL);
  i = 0;
  while (i < total)
    {
      s_sprite[i].x = i;
      s_sprite[i].y
	= ((all->player->pos.x - all->sprite[i]->pos.x)
	   * (all->player->pos.x - all->sprite[i]->pos.x))
	+ ((all->player->pos.y - all->sprite[i]->pos.y)
	   * (all->player->pos.y - all->sprite[i]->pos.y));
      i++;
    }
  s_sprite = algo_sort(s_sprite, total);
  return (s_sprite);
}

sfVector2f		*algo_sort(sfVector2f *sprite, int total)
{
  sfVector2f		tmp;
  int			i;
  int			j;

  i = 0;
  while (i < total)
    {
      j = i;
      while (j < total)
        {
          if (sprite[j].y < sprite[i].y)
            {
              tmp = sprite[i];
              sprite[i] = sprite[j];
              sprite[j] = tmp;
            }
	  j++;
        }
      i++;
    }
  return (sprite);
}

int			get_nb_sprite(t_all *all)
{
  int			i;

  i = 0;
  while (all->sprite[i] != NULL)
    i++;
  return (i);
}

t_my_sprite		*init_my_sprite(t_my_sprite *my_sprite,
					t_all *all, int nb)
{
  my_sprite->t = init_transform(all, nb);
  my_sprite->h =
    abs((int)(SCREEN_HEIGHT / (my_sprite->t.y)));
  my_sprite->s =
    (int)((SCREEN_WIDTH / 2) *
          (1 + my_sprite->t.x / my_sprite->t.y));
  my_sprite->drawstart = my_get_draw_s(my_sprite->h,
                                       my_sprite->s,
                                       my_sprite->t);
  my_sprite->drawend = my_get_draw_e(my_sprite->h,
                                     my_sprite->s,
                                     my_sprite->t);
  my_sprite->w = abs((int)(SCREEN_HEIGHT / (my_sprite->t.y)));
  return (my_sprite);
}

sfVector2i		my_get_draw_s(int sheight,
				      int spritescreen, sfVector2f transform)
{
  sfVector2i		drawstart;
  int			swidth;

  drawstart.y = -sheight / 2 + SCREEN_HEIGHT / 2;
  if (drawstart.y < 0)
    drawstart.y = 0;
  swidth = abs((int)(SCREEN_HEIGHT / (transform.y)));
  drawstart.x = -swidth / 2 + spritescreen;
  if (drawstart.x < 0)
    drawstart.x = 0;
  return (drawstart);
}
