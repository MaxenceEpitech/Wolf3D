/*
** hud.c for hud in /home/Max/Documents/delivery/wolf3d/bonus/my_src
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Thu Jun  1 19:17:03 2017 fourrier maxence
** Last update Sat Jun 10 01:16:17 2017 fourrier maxence
*/

#include <time.h>

#include "my.h"

int			create_hud_number(t_hud *hud)
{
  if ((hud->number[NUMBER_0] = load_picture(NUMBER_0_PATH)) == NULL
      || (hud->number[NUMBER_1] = load_picture(NUMBER_1_PATH)) == NULL
      || (hud->number[NUMBER_2] = load_picture(NUMBER_2_PATH)) == NULL
      || (hud->number[NUMBER_3] = load_picture(NUMBER_3_PATH)) == NULL
      || (hud->number[NUMBER_4] = load_picture(NUMBER_4_PATH)) == NULL
      || (hud->number[NUMBER_5] = load_picture(NUMBER_5_PATH)) == NULL
      || (hud->number[NUMBER_6] = load_picture(NUMBER_6_PATH)) == NULL
      || (hud->number[NUMBER_7] = load_picture(NUMBER_7_PATH)) == NULL
      || (hud->number[NUMBER_8] = load_picture(NUMBER_8_PATH)) == NULL
      || (hud->number[NUMBER_9] = load_picture(NUMBER_9_PATH)) == NULL)
    return (-1);
  return (0);
}

int			create_hud_heal(t_hud *hud)
{
  if ((hud->heal[NUMBER_0] = load_picture(HEAL_0_PATH)) == NULL
      || (hud->heal[NUMBER_1] = load_picture(HEAL_1_PATH)) == NULL
      || (hud->heal[NUMBER_2] = load_picture(HEAL_2_PATH)) == NULL
      || (hud->heal[NUMBER_3] = load_picture(HEAL_3_PATH)) == NULL
      || (hud->heal[NUMBER_4] = load_picture(HEAL_4_PATH)) == NULL
      || (hud->heal[NUMBER_5] = load_picture(HEAL_5_PATH)) == NULL
      || (hud->heal[NUMBER_6] = load_picture(HEAL_6_PATH)) == NULL
      || (hud->heal[NUMBER_7] = load_picture(HEAL_7_PATH)) == NULL
      || (hud->heal[NUMBER_8] = load_picture(HEAL_8_PATH)) == NULL
      || (hud->heal[NUMBER_9] = load_picture(HEAL_9_PATH)) == NULL)
    return (-1);
  return (0);
}

t_hud			*init_hud()
{
  t_hud			*hud;
  struct timespec	ts;

  timespec_get(&ts, TIME_UTC);
  if ((hud = malloc(sizeof(t_hud))) == NULL)
    return (NULL);
  hud->hp = 100;
  hud->helmet = 0;
  hud->ammo = 12;
  hud->gun = 0;
  hud->cpt = 0;
  hud->time = (long)(ts.tv_sec * 1000000000L + ts.tv_nsec) / 10000000;
  if ((hud->sprite = malloc(sizeof(sfSprite*) * HUD_SIZE)) == NULL
      || (hud->number = malloc(sizeof(sfSprite*) * 12)) == NULL
      || create_hud_number(hud) == -1
      || (hud->heal = malloc(sizeof(sfSprite*) * 12)) == NULL
      || (hud->blood = malloc(sizeof(sfSprite*) * 22)) == NULL
      || create_hud_heal(hud) == -1
      || create_hud_blood(hud) == -1
      || create_hud_sprite(hud) == -1)
    return (NULL);
  return (hud);
}
