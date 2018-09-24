/*
** wolf3d.c for wolf3d in /home/Max/Documents/delivery/wolf3d/src
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Sat May 13 10:19:37 2017 fourrier maxence
** Last update Thu Jun  8 21:20:29 2017 fourrier maxence
*/

#include "my.h"

int		draw_lost(t_all *all)
{
  sfSprite	*sprite;

  sfMusic_stop(all->sound[6]);
  sfMusic_play(all->sound[3]);
  if ((sprite = load_picture("texture/lost.png")) == NULL)
    return (-1);
  sfRenderWindow_drawSprite(all->graph->window,
                            sprite, NULL);
  sfRenderWindow_display(all->graph->window);
  while (sfKeyboard_isKeyPressed(sfKeyEscape) == 0);
  return (0);
}

int		start_game(t_all *all)
{
  int		my_game;

  if ((my_game = game(all)) == -1)
    return (-1);
  if (my_game == 1)
    {
      if (draw_lost(all) == -1)
	return (-1);
      return (1);
    }
  return (0);
}

int		wolf3d(char *str, char *nb1, char *nb2)
{
  t_all		*all;
  int		my_menu;
  int		my_game;

  if ((all = init_all(str)) == NULL)
    return (-1);
  all->addr.x = my_str_to_int(nb1);
  all->addr.y = my_str_to_int(nb2);
  if ((my_menu = menu(all)) == -1)
    return (-1);
  if (my_menu == 1)
    {
      clear_ressources(all);
      return (0);
    }
  if ((my_game = start_game(all)) != 0)
    {
      clear_ressources(all);
      return (my_game);
    }
  clear_ressources(all);
  return (0);
}
