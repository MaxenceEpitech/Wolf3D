/*
** init_sprite.c for init_sprite in /home/Max/Documents/delivery/wolf3d/bonus/my_src
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Thu Jun  1 19:19:27 2017 fourrier maxence
** Last update Thu Jun 15 14:26:40 2017 fourrier maxence
*/

#include "my.h"

t_tab_sprite		**init_sprite_tab()
{
  t_tab_sprite		**sprite_tab;

  if ((sprite_tab = malloc(sizeof(t_tab_sprite*) * (NB_SPRITE))) == NULL)
    return (NULL);
  if ((sprite_tab[H_ID] = create_sprite(HELMET_X, HELMET_Y, 12)) == NULL
      || (sprite_tab[G_ID] = create_sprite(GUN_X, GUN_Y, 13)) == NULL
      || (sprite_tab[2] = create_sprite(5.5, 8.8, LAMP_C)) == NULL
      || (sprite_tab[3] = create_sprite(2.5, 5.5, LAMP_C)) == NULL
      || (sprite_tab[4] = create_sprite(5.5, 2.5, LAMP_C)) == NULL
      || (sprite_tab[5] = create_sprite(8.5, 5.5, LAMP_C)) == NULL
      || (sprite_tab[6] = create_sprite(0, 0, SOLIDER_C)) == NULL
      || (sprite_tab[7] = create_sprite(15.5, 5.5, SOLIDER_C)) == NULL
      || (sprite_tab[8] = create_sprite(15.3, 14.6, SOLIDER_C)) == NULL
      || (sprite_tab[9] = create_sprite(16.5, 13.3, SOLIDER_C)) == NULL
      || (sprite_tab[10] = create_sprite(6, 2.2, AMMO_C)) == NULL
      || (sprite_tab = init_sprite_solider(sprite_tab)) == NULL
      || (sprite_tab = init_sprite_lamp(sprite_tab)) == NULL
      || (sprite_tab = init_sprite_ammo(sprite_tab)) == NULL)
    return (NULL);
  sprite_tab[63] = NULL;
  return (sprite_tab);
}

t_tab_sprite		**init_sprite_solider(t_tab_sprite **sprite_tab)
{
  if ((sprite_tab[11] = create_sprite(13.5, 16.5, SOLIDER_C)) == NULL
      || (sprite_tab[12] = create_sprite(24.5, 28.5, SOLIDER_C)) == NULL
      || (sprite_tab[13] = create_sprite(16.5, 16.5, SOLIDER_C)) == NULL
      || (sprite_tab[14] = create_sprite(25.5, 31.5, SOLIDER_C)) == NULL
      || (sprite_tab[15] = create_sprite(13.5, 20.5, SOLIDER_C)) == NULL
      || (sprite_tab[16] = create_sprite(24.5, 32.5, SOLIDER_C)) == NULL
      || (sprite_tab[17] = create_sprite(16.5, 20.5, SOLIDER_C)) == NULL
      || (sprite_tab[18] = create_sprite(29.5, 21.5, SOLIDER_C)) == NULL
      || (sprite_tab[19] = create_sprite(30.5, 27.5, SOLIDER_C)) == NULL
      || (sprite_tab[20] = create_sprite(25.5, 29.5, SOLIDER_C)) == NULL
      || (sprite_tab[21] = create_sprite(14.5, 41.5, SOLIDER_C)) == NULL
      || (sprite_tab[22] = create_sprite(22.9, 42.4, SOLIDER_C)) == NULL
      || (sprite_tab[23] = create_sprite(23.8, 43.0, SOLIDER_C)) == NULL
      || (sprite_tab[24] = create_sprite(16.5, 43.5, SOLIDER_C)) == NULL)
    return (NULL);
  return (sprite_tab);
}

t_tab_sprite		**init_sprite_lamp(t_tab_sprite **sprite_tab)
{
  if ((sprite_tab[25] = create_sprite(15.5, 40.5, LAMP_C)) == NULL
      || (sprite_tab[26] = create_sprite(13.5, 42.5, LAMP_C)) == NULL
      || (sprite_tab[27] = create_sprite(17.5, 42.5, LAMP_C)) == NULL
      || (sprite_tab[28] = create_sprite(29.5, 42.5, LAMP_C)) == NULL
      || (sprite_tab[29] = create_sprite(29.5, 34.5, LAMP_C)) == NULL
      || (sprite_tab[30] = create_sprite(29.5, 26.5, LAMP_C)) == NULL
      || (sprite_tab[31] = create_sprite(13.5, 5.5, LAMP_C)) == NULL
      || (sprite_tab[32] = create_sprite(15.5, 15.5, LAMP_C)) == NULL
      || (sprite_tab[33] = create_sprite(12.5, 18.5, LAMP_C)) == NULL
      || (sprite_tab[34] = create_sprite(15.5, 21.5, LAMP_C)) == NULL
      || (sprite_tab[35] = create_sprite(17.5, 18.5, LAMP_C)) == NULL
      || (sprite_tab[36] = create_sprite(26.5, 18.5, LAMP_C)) == NULL
      || (sprite_tab[37] = create_sprite(21.5, 18.5, LAMP_C)) == NULL
      || (sprite_tab[38] = create_sprite(15.5, 32.5, LAMP_C)) == NULL
      || (sprite_tab[39] = create_sprite(15.5, 28.5, LAMP_C)) == NULL
      || (sprite_tab[40] = create_sprite(2.5, 18.5, LAMP_C)) == NULL
      || (sprite_tab[41] = create_sprite(2.5, 26.5, LAMP_C)) == NULL
      || (sprite_tab[42] = create_sprite(2.5, 34.5, LAMP_C)) == NULL
      || (sprite_tab[43] = create_sprite(2.5, 42.5, LAMP_C)) == NULL)
    return (NULL);
  return (sprite_tab);
}

t_tab_sprite		**init_sprite_ammo(t_tab_sprite **sprite_tab)
{
  if ((sprite_tab[44] = create_sprite(30.4, 17.4, AMMO_C)) == NULL
      || (sprite_tab[45] = create_sprite(30.4, 41.3, AMMO_C)) == NULL
      || (sprite_tab[46] = create_sprite(16.5, 32.4, AMMO_C)) == NULL
      || (sprite_tab[47] = create_sprite(8, 30, AMMO_C)) == NULL
      || (sprite_tab[48] = create_sprite(23.8, 30.3, AMMO_C)) == NULL
      || (sprite_tab[49] = create_sprite(7.2, 18.9, SOLIDER_C)) == NULL
      || (sprite_tab[50] = create_sprite(1.5, 21.5, SOLIDER_C)) == NULL
      || (sprite_tab[51] = create_sprite(3.5, 21.5, SOLIDER_C)) == NULL
      || (sprite_tab[52] = create_sprite(5.5, 31.5, SOLIDER_C)) == NULL
      || (sprite_tab[53] = create_sprite(5.5, 29.5, SOLIDER_C)) == NULL
      || (sprite_tab[54] = create_sprite(1.4, 30.4, SOLIDER_C)) == NULL
      || (sprite_tab[55] = create_sprite(2.5, 38.5, SOLIDER_C)) == NULL
      || (sprite_tab[56] = create_sprite(3.5, 41.5, SOLIDER_C)) == NULL
      || (sprite_tab[57] = create_sprite(1.2, 43.2, SOLIDER_C)) == NULL
      || (sprite_tab[58] = create_sprite(23.8, 18, SOLIDER_C)) == NULL
      || (sprite_tab[59] = create_sprite(30.7, 32.4, SOLIDER_C)) == NULL
      || (sprite_tab[60] = create_sprite(15.4, 33.6, SOLIDER_C)) == NULL
      || (sprite_tab[61] = create_sprite(15.4, 27.3, SOLIDER_C)) == NULL
      || (sprite_tab[62] = create_sprite(JOFF_X, JOFF_Y, JOFF__)) == NULL)
    return (NULL);
  return (sprite_tab);
}
