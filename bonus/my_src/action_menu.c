/*
** action_menu.c for action_menu in /home/Max/Documents/delivery/wolf3d/bonus/my_src
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Thu May 25 12:54:48 2017 fourrier maxence
** Last update Sat May 27 17:11:30 2017 fourrier maxence
*/

#include "my.h"

void		check_where_clicked(sfVector2i vec,
				    t_menu *menu, t_graph *graph)
{
  if (vec.x >= 785 && vec.x <= 975 && vec.y >= 82 && vec.y <= 128)
    menu->play = 1;
  if (vec.x >= 780 && vec.x <= 975 && vec.y >= 140 && vec.y <= 180)
    {
      sfRenderWindow_close(graph->window);
      menu->quit = 1;
    }
}

sfColor         my_color(int x, int y, sfColor **color)
{
  return (color[y][x]);
}
