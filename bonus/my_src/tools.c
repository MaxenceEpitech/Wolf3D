/*
** tools.c for tools in /home/Max/Documents/delivery/wolf3d/my_src
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Tue May 16 10:00:31 2017 fourrier maxence
** Last update Thu Jun 15 15:31:03 2017 fourrier maxence
*/

#include "my.h"

void		clear_ressources(t_all *all)
{
  sfSprite_destroy(all->graph->sprite);
  sfTexture_destroy(all->graph->texture);
  sfRenderWindow_destroy(all->graph->window);
  free(all->color);
  free(all->menu);
  free(all->graph);
  free(all->player);
  my_free_map(all->game->map);
  sfMusic_destroy(all->sound[0]);
  sfMusic_destroy(all->sound[1]);
  sfMusic_destroy(all->sound[2]);
  sfMusic_destroy(all->sound[3]);
  sfMusic_destroy(all->sound[4]);
  sfMusic_destroy(all->sound[5]);
  sfMusic_destroy(all->sound[6]);
  sfMusic_destroy(all->sound[7]);
  sfMusic_destroy(all->sound[8]);
  sfMusic_destroy(all->sound[9]);
  free(all);
}

void		my_free_map(int **map)
{
  int		i;

  i = 0;
  while (map[i] != NULL)
    {
      free(map[i]);
      i++;
    }
  free(map);
}

sfColor		color(int r, int g, int b, int a)
{
  sfColor	color;

  color.r = r;
  color.g = g;
  color.b = b;
  color.a = a;
  return (color);
}

sfVector2i	create_vector_i(int x, int y)
{
  sfVector2i	vec;

  vec.x = x;
  vec.y = y;
  return (vec);
}

sfSprite	*load_picture(char *str)
{
  sfSprite	*sprite;
  sfTexture	*texture;

  if ((texture = sfTexture_createFromFile(str, NULL)) == NULL
      || (sprite = sfSprite_create()) == NULL)
    return (NULL);
  sfSprite_setTexture(sprite, texture, sfTrue);
  return (sprite);
}
