/*
** create_map.c for create_map in /home/Max/Documents/delivery/wolf3d/my_src
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Tue May 16 19:44:22 2017 fourrier maxence
** Last update Fri Jun  2 21:14:18 2017 fourrier maxence
*/

#include "my.h"

int		get_height(char *str)
{
  int		i;
  int		c;

  c = 0;
  i = 0;
  while (str[i])
    {
      if (str[i] == '\n')
	c++;
      i++;
    }
  return (c + 1);
}

int		get_width(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0' && str[i] != '\n')
    i++;
  return (i);
}

int		**cpy_map(int **map, char *str)
{
  int		x;
  int		y;
  int		i;

  x = 0;
  y = 0;
  i = 0;
  while (str[i])
    {
      if (str[i] == '\n')
	{
	  map[y++][x] = -1;
	  x = 0;
	}
      else
	map[y][x++] = str[i] - '0';
      i++;
    }
  map[y][x] = -1;
  map[y + 1] = NULL;
  return (map);
}

int		**create_map(char *str)
{
  char		*buff;
  int		**map;
  int		height;
  int		width;
  int		i;

  if ((buff = get_buff(str)) == NULL)
    return (NULL);
  height = get_height(buff);
  width = get_width(buff);
  i = 0;
  if ((map = malloc(sizeof(int*) * (height + 1))) == NULL)
    return (NULL);
  while (i < height)
    {
      if ((map[i] = malloc(sizeof(int) * (width + 1))) == NULL)
	return (NULL);
      i++;
    }
  map = cpy_map(map, buff);
  return (map);
}
