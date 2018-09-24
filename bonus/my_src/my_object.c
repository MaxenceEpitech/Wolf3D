/*
** my_object.c for my_object in /home/Max/Documents/delivery/wolf3d/bonus/my_src
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Sat May 27 21:48:55 2017 fourrier maxence
** Last update Sat May 27 22:08:26 2017 fourrier maxence
*/

#include "my.h"

int		get_nb(int *y, char *str)
{
  int		i;
  char		nb[20];

  i = 0;
  while (str[*y + i] && str[*y + i] != '\n' && i == 0)
    {
      while (str[*y + i] >= '0' && str[*y + i] <= '9'
	     && str[*y + i] && str[*y + i] != '\n')
	{
	  nb[i] = str[*y + i];
	  i++;
	}
      *y = *y + 1;
    }
  nb[i] = '\0';
  *y = *y + i;
  return (my_str_to_int(nb));
}
