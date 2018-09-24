/*
** sprite_tools.c for sprite_tools in /home/Max/Documents/delivery/wolf3d/bonus/my_src
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Thu Jun  8 22:23:24 2017 fourrier maxence
** Last update Thu Jun  8 22:24:39 2017 fourrier maxence
*/

#include "my.h"

t_tab_sprite		*create_sprite(float x, float y, int color)
{
  t_tab_sprite		*my_sprite;

  if ((my_sprite = malloc(sizeof(t_tab_sprite))) == NULL)
    return (NULL);
  my_sprite->pos.x = x;
  my_sprite->pos.y = y;
  my_sprite->color = color;
  my_sprite->fire = 0;
  return (my_sprite);
}

sfColor			**create_color(char *str)
{
  sfImage		*image;
  sfColor		**color;
  int			y;
  int			x;

  y = 0;
  if ((image = sfImage_createFromFile(str)) == NULL
      || (color = malloc (sizeof(sfColor *) * TEX_HEIGHT)) == NULL)
    return (NULL);
  while (y < TEX_HEIGHT)
    {
      if ((color[y] = malloc(sizeof(sfColor) * TEX_WIDTH)) == NULL)
        return (NULL);
      x = 0;
      while (x < TEX_WIDTH)
        {
          color[y][x] = sfImage_getPixel(image, x, y);
          x++;
        }
      y++;
    }
  sfImage_destroy(image);
  return (color);
}
