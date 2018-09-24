/*
** main.c for main in /home/Max/Documents
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Tue Apr 25 13:13:22 2017 fourrier maxence
** Last update Tue Jun  6 18:00:39 2017 fourrier maxence
*/

#include "my.h"

int		main(int ac, char **av)
{
  if (ac != 4 || av[1] == NULL || av[2] == NULL || av[3] == NULL)
    return (RETURN_USAGE);
  if (wolf3d(av[1], av[2], av[3]) == -1)
    return (RETURN_ERROR);
  return (RETURN_SUCCESS);
}
