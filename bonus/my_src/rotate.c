/*
** rotate.c for rotate in /home/Max/Documents/delivery/wolf3d/bonus/my_src
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Tue Jun  6 14:07:07 2017 fourrier maxence
** Last update Sat Jun 10 01:22:32 2017 fourrier maxence
*/

#include "my.h"

t_player	*rotate_left(t_player *player, int power)
{
  double	oldplanex;
  double	olddirx;

  olddirx = player->dir.x;
  player->dir.x = player->dir.x * cos(player->rotate_speed * power)
    - player->dir.y * sin(player->rotate_speed * power);
  player->dir.y = olddirx * sin(player->rotate_speed * power)
    + player->dir.y * cos(player->rotate_speed * power);
  oldplanex = player->plane.x;
  player->plane.x = player->plane.x * cos(player->rotate_speed * power)
    - player->plane.y * sin(player->rotate_speed * power);
  player->plane.y = oldplanex * sin(player->rotate_speed * power)
    + player->plane.y * cos(player->rotate_speed * power);
}

t_player	*rotate_right(t_player *player, int power)
{
  double	oldplanex;
  double	olddirx;

  olddirx = player->dir.x;
  player->dir.x = player->dir.x * cos(-player->rotate_speed * power)
    - player->dir.y * sin(-player->rotate_speed * power);
  player->dir.y = olddirx * sin(-player->rotate_speed * power)
    + player->dir.y * cos(-player->rotate_speed * power);
  oldplanex = player->plane.x;
  player->plane.x = player->plane.x * cos(-player->rotate_speed * power)
    - player->plane.y * sin(-player->rotate_speed * power);
  player->plane.y = oldplanex * sin(-player->rotate_speed * power)
    + player->plane.y * cos(-player->rotate_speed * power);
}
