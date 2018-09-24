/*
** move_forward.c for move_forard in /home/Max/Documents/delivery/wolf3d/src
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Tue May 16 14:27:15 2017 fourrier maxence
** Last update Mon May 29 09:50:04 2017 fourrier maxence
*/

#include "my.h"

sfVector2f	move_forward(sfVector2f pos, float direction, float distance)
{
  sfVector2f	vect;

  direction *= M_PI / 180;
  vect.x = (distance * cos(direction)) + pos.x;
  vect.y = (distance * sin(direction)) + pos.y;
  return (vect);
}
