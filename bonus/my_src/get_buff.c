/*
** get_buff.c for get_buff in /home/Max/Documents/delivery/wolf3d/my_src
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Tue May 16 19:51:32 2017 fourrier maxence
** Last update Mon Jul 24 10:56:43 2017 fourrier maxence
*/

#include <fcntl.h>

#include "my.h"

int		get_size_file(char *str)
{
  int		file;
  int		i;
  char		c;

  i = 0;
  if ((file = open(str, O_RDONLY)) == -1)
    return (-1);
  while (read(file, &c, 1) > 0)
    i++;
  return (i);
}

char		*get_buff(char *str)
{
  char		*buff;
  int		taille;
  int		file;
  int		pos;

  if ((taille = get_size_file(str)) == -1)
    return (NULL);
  if ((buff = malloc(sizeof(char) * (taille + 1))) == NULL)
    return (NULL);
  if ((file = open(str, O_RDONLY)) == -1)
    return (NULL);
  if ((pos = read(file, buff, taille)) == -1)
    return (NULL);
  buff[taille] = '\0';
  if (close(file) == -1)
    return (NULL);
  return (buff);
}
