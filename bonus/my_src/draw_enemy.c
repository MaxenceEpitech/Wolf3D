/*
** draw_enemy.c for draw_enemy in /home/Max/Documents/delivery/wolf3d/bonus/my_src
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Sat May 27 18:04:28 2017 fourrier maxence
** Last update Sat Jun 10 01:23:03 2017 fourrier maxence
*/

#include "my.h"

sfVector2f	init_transform(t_all *all, int nb)
{
  sfVector2f	sprite;
  sfVector2f	transform;
  double	invdet;

  sprite.x = all->sprite[nb]->pos.x - all->player->pos.x;
  sprite.y = all->sprite[nb]->pos.y - all->player->pos.y;
  invdet = 1.0 / (all->player->plane.x * all->player->dir.y
		  - all->player->dir.x * all->player->plane.y);
  transform.x = invdet * (all->player->dir.y * sprite.x
			  - all->player->dir.x * sprite.y);
  transform.y = invdet * (-all->player->plane.y * sprite.x
			  + all->player->plane.x * sprite.y);
  return (transform);
}

sfVector2i	my_get_draw_e(int sheight,
			      int spritescreen, sfVector2f transform)
{
  sfVector2i	drawend;
  int		swidth;

  drawend.y = sheight / 2 + SCREEN_HEIGHT / 2;
  if (drawend.y >= SCREEN_HEIGHT)
    drawend.y = SCREEN_HEIGHT - 1;
  swidth = abs((int)(SCREEN_HEIGHT / (transform.y)));
  drawend.x = swidth / 2 + spritescreen;
  if (drawend.x >= SCREEN_WIDTH)
    drawend.x = SCREEN_WIDTH - 1;
  return (drawend);
}

void		draw_sprite_color(t_all *all, sfVector2i cpt,
				  sfVector2i tex, t_my_sprite *my_s)
{
  int		y;
  sfColor	c;

  y = my_s->drawstart.y;
  while (y < my_s->drawend.y)
    {
      tex.y = (((y * 256 - SCREEN_HEIGHT * 128 + my_s->h * 128)
		* TEX_HEIGHT) / my_s->h) / 256;
      if (tex.y > 64 || tex.y < 0 || tex.x > 64 || tex.x < 0)
	return;
      c = all->color[all->sprite[cpt.y]->color][tex.y][tex.x];
      if (!(c.r == 152 && c.g == 0 && c.b == 136))
	my_put_pixel(all->graph->framebuffer, cpt.x, y, c);
      y++;
    }
}

void		boucle(t_all *all, double *zbuffer,
		       t_my_sprite *my_s, int nb)
{
  sfVector2i	tex;
  int		i;

  i = my_s->drawstart.x;
  while (i < my_s->drawend.x)
    {
      tex.x = (int)(256 * (i - (-my_s->w / 2 + my_s->s)) *
		    TEX_WIDTH / my_s->w) / 256;
      if (my_s->t.y > 0 && i > 0 && i < SCREEN_WIDTH
	  && my_s->t.y < zbuffer[i])
	draw_sprite_color(all, create_vector_i(i, nb), tex, my_s);
      i++;
    }
}

int		my_draw_enemy(t_ray *ray, t_all *all, double *zbuffer)
{
  t_my_sprite	*my_sprite;
  sfVector2f	*sprite_sorted;
  int		i;
  int		total;

  all->sprite[6]->pos.x = all->pos.x;
  all->sprite[6]->pos.y = all->pos.y;
  total = get_nb_sprite(all);
  sprite_sorted = sort_sprite(all, total);
  i = total - 1;
  if ((my_sprite = malloc(sizeof(t_my_sprite))) == NULL)
    return (-1);
  while (i >= 0)
    {
      my_sprite = init_my_sprite(my_sprite, all,
				 (int)sprite_sorted[i].x);
      if (all->sprite[(int)sprite_sorted[i].x]->color >= 41
	  && all->sprite[(int)sprite_sorted[i].x]->color <= 46)
	all->sprite[(int)sprite_sorted[i].x]->color -= 1;
      boucle(all, zbuffer, my_sprite, (int)sprite_sorted[i].x);
      i--;
    }
  free(my_sprite);
  return (0);
}
