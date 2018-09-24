/*
** utils.c for utils in /home/Max/Documents/delivery/wolf3d/bonus/my_src
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Tue May 30 19:38:36 2017 fourrier maxence
** Last update Thu Jun  8 09:35:23 2017 fourrier maxence
*/

#include "my.h"

int		can_move(int nb)
{
  if (nb == 0 || !(nb > 0 && nb <= 9))
    return (1);
  return (0);
}
