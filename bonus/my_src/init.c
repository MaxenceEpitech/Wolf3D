/*
** init.c for init in /home/Max/Documents/delivery/wolf3d/bonus/my_src
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Sun May 21 14:48:03 2017 fourrier maxence
** Last update Wed Jun  7 19:44:54 2017 fourrier maxence
*/

#include "my.h"

t_all			*init_all(char *str)
{
  t_all			*all;

  if ((all = malloc(sizeof(t_all))) == NULL
      || (all->player =
	  init_player(POS_X, POS_Y, MOVE_SPEED, ROTATE_SPEED)) == NULL
      || (all->graph = init_graph()) == NULL
      || (all->color = init_texture()) == NULL
      || (all->sprite = init_sprite_tab()) == NULL
      || (all->hud = init_hud()) == NULL
      || (all->sound = init_sound()) == NULL
      || (all->game = init_game(str)) == NULL)
    return (NULL);
  all->pos.x = 5;
  all->pos.y = 5;
  return (all);
}

t_map			*init_game(char *str)
{
  t_map			*game;
  int			i;

  if ((game = malloc(sizeof(t_map))) == NULL)
    return (NULL);
  if ((game->map = create_map(str)) == NULL)
    return (NULL);
  i = 0;
  while (game->map[0][i] != -1)
    i++;
  game->width = i;
  i = 0;
  while (game->map[i] != NULL)
    i++;
  game->height = i;
  return (game);
}

t_player		*init_player()
{
  t_player		*player;

  if ((player = malloc(sizeof(t_player))) == NULL)
    return (NULL);
  player->angle = (float)ANGLE;
  player->pos.x = (float)POS_X;
  player->pos.y = (float)POS_Y;
  player->move_speed = (float)MOVE_SPEED;
  player->rotate_speed = (float)ROTATE_SPEED;
  player->vision = VISION;
  player->dir.x = -1;
  player->dir.y = 0;
  player->plane.x = 0;
  player->plane.y = 0.66;
  return (player);
}

t_sprite		*init_spr()
{
  t_sprite		*sprite;

  if ((sprite = malloc(sizeof(t_sprite))) == NULL)
    return (NULL);
  if ((sprite->menu = load_picture("texture/menu.png")) == NULL
      || (sprite->play =
	  load_picture("texture/play_not_clicked.jpg")) == NULL
      || (sprite->quit =
	  load_picture("texture/exit_not_clicked.png")) == NULL)
    return (NULL);
  return (sprite);
}

t_graph			*init_graph()
{
  t_graph		*graph;

  if ((graph = malloc(sizeof(t_graph))) == NULL
      || (graph->window =
	  create_window(SCREEN_NAME, SCREEN_WIDTH, SCREEN_HEIGHT)) == NULL
      || (graph->sprite =
	  sfSprite_create()) == NULL
      || (!graph->window)
      || (graph->texture =
	  sfTexture_create(SCREEN_WIDTH, SCREEN_HEIGHT)) == NULL)
    return (NULL);
  sfSprite_setTexture(graph->sprite, graph->texture, sfTrue);
  if ((graph->framebuffer =
       my_framebuffer_create(SCREEN_WIDTH, SCREEN_HEIGHT)) == NULL)
    return (NULL);
  if ((graph->spr = init_spr()) == NULL)
    return (NULL);
  return (graph);
}
