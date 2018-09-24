/*
** audio.c for audio in /home/Max/Documents/delivery/wolf3d/bonus/my_src
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Thu Jun  8 09:35:38 2017 fourrier maxence
** Last update Thu Jun 15 15:23:14 2017 fourrier maxence
*/

#include "my.h"

sfMusic		*init_music(char *str)
{
  sfMusic	*sound;

  if ((sound = sfMusic_createFromFile(str)) == NULL)
    return (NULL);
  return (sound);
}

sfMusic		**init_sound()
{
  sfMusic	**music;

  if ((music = malloc(sizeof(sfMusic*) * 10)) == NULL)
    return (NULL);
  if ((music[0] = init_music("sound/shoot.ogg")) == NULL
      || (music[1] = init_music("sound/hurt.ogg")) == NULL
      || (music[2] = init_music("sound/enemy_shot.ogg")) == NULL
      || (music[3] = init_music("sound/game_over.ogg")) == NULL
      || (music[4] = init_music("sound/hit_wall.ogg")) == NULL
      || (music[5] = init_music("sound/dead_enemy.ogg")) == NULL
      || (music[6] = init_music("sound/song.ogg")) == NULL
      || (music[7] = init_music("sound/button.ogg")) == NULL
      || (music[8] = init_music("sound/loading.ogg")) == NULL
      || (music[9] = init_music("sound/victory.ogg")) == NULL)
    return (NULL);
  sfMusic_setLoop(music[6], sfTrue);
  return (music);
}
