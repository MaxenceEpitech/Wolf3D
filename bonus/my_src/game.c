/*
** game.c for game in /home/Max/Documents/delivery/wolf3d/my_src
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Wed May 17 13:08:31 2017 fourrier maxence
** Last update Thu Jun 15 14:45:35 2017 fourrier maxence
*/

#include "my.h"

int		button_pressed(t_all *all)
{
  if (sfKeyboard_isKeyPressed(sfKeyQ))
    all->player = move_left(all->player, all->game);
  if (sfKeyboard_isKeyPressed(sfKeyS))
    all->player = move_back(all->player, all->game);
  if (sfKeyboard_isKeyPressed(sfKeyD))
    all->player = move_right(all->player, all->game);
  if (sfKeyboard_isKeyPressed(sfKeyZ))
    all->player = move_front(all->player, all->game, 0);
  if (sfKeyboard_isKeyPressed(sfKeyTab))
    all->player = move_front(all->player, all->game, 0.2);
  if (sfKeyboard_isKeyPressed(sfKeyE) && pos_helmet(all))
    put_helmet(all);
  if (sfKeyboard_isKeyPressed(sfKeyE) && pos_gun(all))
    put_gun(all);
  if (sfMouse_isButtonPressed(sfMouseLeft) && check_fire(all))
    fire(all);
  if (sfKeyboard_isKeyPressed(sfKeyE) && pos_ammo(all))
    add_ammo(all);
  if (sfKeyboard_isKeyPressed(sfKeySpace) && has_won(all))
    draw_victory(all);
}

int		my_event(t_all *all)
{
  if (sfKeyboard_isKeyPressed(sfKeyEscape))
    {
      sfRenderWindow_close(all->graph->window);
      return (1);
    }
  if (button_pressed(all) == -1
      || check_mouse(all) == -1)
    return (-1);
  return (0);
}

int		game(t_all *all)
{
  int		event;

  if (init_thread(all) == -1)
    return (-1);
  while (1)
    {
      regen_hp(all);
      if ((event = my_event(all)) == -1
	  || event == 1)
	return (event);
      if ((draw_all(all)) == -1)
	return (-1);
      sfRenderWindow_drawSprite(all->graph->window, all->graph->sprite, NULL);
      draw_hud(all);
      sfRenderWindow_display(all->graph->window);
      if (all->hud->hp <= 0)
	return (1);
      move_joff(all);
    }
  return (0);
}
