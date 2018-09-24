/*
** draw.c for draw in /home/Max/Documents/delivery/wolf3d/bonus/my_src
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Fri May 19 13:08:59 2017 fourrier maxence
** Last update Sat Jun 10 01:01:23 2017 fourrier maxence
*/

#include "my.h"

int		draw_wall(t_all *all)
{
  if (my_raycast(all) == -1)
    return (-1);
  return (0);
}

int		draw_minimap(t_map *game, t_graph *graph, t_player *player)
{
  int		x;
  int		y;

  y = 0;
  while (y < game->height - 1)
    {
      x = 0;
      while (x < game->width)
	{
	  if (game->map[y][x] >= 0 && game->map[y][x] <= 9)
	    my_put_pixel(graph->framebuffer, x, y, sfBlue);
	  else
	    my_put_pixel(graph->framebuffer, x, y, sfRed);
	  x++;
	}
      y++;
    }
  my_put_pixel(graph->framebuffer, (int)player->pos.y,
	       (int)player->pos.x, sfWhite);
  return (0);
}

int		draw_hud(t_all *all)
{
  sfVector2f	vec;

  vec.x = 0;
  vec.y = 0;
  if (all->hud->gun)
    draw_gun(all);
  draw_blood(all);
  if (all->hud->helmet)
    draw_helmet(all);
  draw_ammo(all);
  draw_health(all);
  sfRenderWindow_display(all->graph->window);
}

int		draw_all(t_all *all)
{
  if ((draw_wall(all)) == -1
      || (draw_minimap(all->game, all->graph, all->player)) == -1)
    return (-1);
  sfTexture_updateFromPixels(all->graph->texture,
			     all->graph->framebuffer->pixels,
			     SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
  return (0);
}
