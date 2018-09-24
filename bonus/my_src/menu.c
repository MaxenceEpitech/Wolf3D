/*
** menu.c for menu in /home/Max/Documents/delivery/wolf3d/bonus/my_src
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Wed May 24 14:44:59 2017 fourrier maxence
** Last update Thu Jun  8 18:09:31 2017 fourrier maxence
*/

#include "my.h"

int		init_menu(t_all *all)
{
  t_menu	*menu;

  if ((menu = malloc(sizeof(t_menu))) == NULL)
    return (-1);
  menu->play = 0;
  menu->option = 0;
  menu->quit = 0;
  all->menu = menu;
  return (0);
}

int		draw_menu(t_graph *graph, t_menu *menu)
{
  sfVector2f	vec;

  vec.x = 0;
  vec.y = 0;
  sfSprite_setPosition(graph->spr->menu, vec);
  sfRenderWindow_drawSprite(graph->window, graph->spr->menu, NULL);
  vec.x = 780;
  vec.y = 80;
  sfSprite_setPosition(graph->spr->play, vec);
  sfRenderWindow_drawSprite(graph->window, graph->spr->play, NULL);
  vec.x = 780;
  vec.y = 140;
  sfSprite_setPosition(graph->spr->quit, vec);
  sfRenderWindow_drawSprite(graph->window, graph->spr->quit, NULL);
  sfTexture_updateFromPixels(graph->texture,
                             graph->framebuffer->pixels,
                             SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
}

int		menu_event(t_graph *graph, t_menu *menu)
{
  while (sfRenderWindow_pollEvent(graph->window, &(graph->event)))
    {
      if (graph->event.type == sfEvtClosed)
	{
	  sfRenderWindow_close(graph->window);
	  menu->quit = 1;
	}
      if (sfMouse_isButtonPressed(sfMouseLeft))
	check_where_clicked(sfMouse_getPositionRenderWindow
			    (graph->window), menu, graph);
    }
  return (0);
}

int		menu(t_all *all)
{
  if (init_menu(all) == -1
      || draw_menu(all->graph, all->menu) == -1)
    return (-1);
  sfMusic_play(all->sound[6]);
  sfRenderWindow_display(all->graph->window);
  while (all->menu->play == 0)
    {
      if (menu_event(all->graph, all->menu) == -1)
        return (-1);
      if (all->menu->quit == 1)
	{
	  sfMusic_play(all->sound[7]);
	  return (1);
	}
    }
  sfMusic_play(all->sound[7]);
  return (0);
}
