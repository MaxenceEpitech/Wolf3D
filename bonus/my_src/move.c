/*
** move.c for move in /home/Max/Documents/delivery/wolf3d/bonus/my_src
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Fri May 19 09:56:39 2017 fourrier maxence
** Last update Fri Jun  9 10:01:26 2017 fourrier maxence
*/

#include "my.h"

t_player	*move_back(t_player *player, t_map *game)
{
  if (can_move(game->map[(int)(player->pos.x - player->dir.x
			       * player->move_speed)][(int)player->pos.y]))
    player->pos.x -= player->dir.x * player->move_speed;
  if (can_move(game->map[(int)player->pos.x][(int)(player->pos.y
						   - player->dir.y
					       * player->move_speed)]))
    player->pos.y -= player->dir.y * player->move_speed;
  return (player);
}

t_player	*move_front(t_player *player, t_map *game, int nb)
{
  if (can_move(game->map[(int)(player->pos.x + player->dir.x
			       * (player->move_speed + nb))]
	       [(int)(player->pos.y)]))
    player->pos.x += player->dir.x * (player->move_speed + nb);
  if (can_move(game->map[(int)player->pos.x]
	       [(int)(player->pos.y + player->dir.y
		      * (player->move_speed + nb))]))
    player->pos.y += player->dir.y * (player->move_speed + nb);
  return (player);
}

t_player	*move_right(t_player *player, t_map *game)
{
  int		angle;
  sfVector2f	dir;

  angle = atan2(player->dir.y, player->dir.x) * 180 / M_PI;
  angle -= 90;
  dir.x = cos(M_PI * angle / 180);
  dir.y = sin(M_PI * angle / 180);
  if (can_move(game->map[(int)(player->pos.x + dir.x
			       * player->move_speed)][(int)(player->pos.y)]))
    player->pos.x += dir.x * (player->move_speed / 2);
  if (can_move(game->map[(int)player->pos.x][(int)(player->pos.y + dir.y
					       * player->move_speed)]))
    player->pos.y += dir.y * (player->move_speed / 2);
  return (player);
}

t_player	*move_left(t_player *player, t_map *game)
{
  int		angle;
  sfVector2f	dir;

  angle = atan2(player->dir.y, player->dir.x) * 180 / M_PI;
  angle += 90;
  dir.x = cos(M_PI * angle / 180);
  dir.y = sin(M_PI * angle / 180);
  if (can_move(game->map[(int)(player->pos.x + dir.x
			       * player->move_speed)][(int)(player->pos.y)]))
    player->pos.x += dir.x * (player->move_speed / 2);
  if (can_move(game->map[(int)player->pos.x][(int)(player->pos.y + dir.y
					       * player->move_speed)]))
    player->pos.y += dir.y * (player->move_speed / 2);
  return (player);
}
