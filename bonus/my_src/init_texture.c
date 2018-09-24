/*
** init_texture.c for init_texture in /home/Max/Documents/delivery/wolf3d/bonus/my_src
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Fri May 26 16:52:16 2017 fourrier maxence
** Last update Thu Jun 15 14:24:43 2017 fourrier maxence
*/

#include "my.h"

int			create_hud_sprite(t_hud *hud)
{
  if ((hud->sprite[HELMET_ID] = load_picture(HELMET_PATH)) == NULL
      || (hud->sprite[HELMET_1] = load_picture(HELMET__1)) == NULL
      || (hud->sprite[HELMET_2] = load_picture(HELMET__2)) == NULL
      || (hud->sprite[HELMET_3] = load_picture(HELMET__3)) == NULL
      || (hud->sprite[HELMET_4] = load_picture(HELMET__4)) == NULL
      || (hud->sprite[HELMET_5] = load_picture(HELMET__5)) == NULL
      || (hud->sprite[HELMET_6] = load_picture(HELMET__6)) == NULL
      || (hud->sprite[HELMET_7] = load_picture(HELMET__7)) == NULL
      || (hud->sprite[HELMET_8] = load_picture(HELMET__8)) == NULL
      || (hud->sprite[HELMET_9] = load_picture(HELMET__9)) == NULL
      || (hud->sprite[GUN_ID] = load_picture(GUN_PATH)) == NULL
      || (hud->sprite[SHOOT_ID] = load_picture(SHOOT_PATH)) == NULL
      || (hud->sprite[H_SHOOT_ID] = load_picture(H_SHOOT_PATH)) == NULL)
    return (-1);
  return (0);
}

sfColor			***init_texture()
{
  sfColor		***tab_color;

  if ((tab_color = malloc(sizeof(sfColor*) * (NB_COLOR))) == NULL)
    return (NULL);
  tab_color[0] = NULL;
  if ((tab_color[1] = create_color("texture/wall/wall_1.png")) == NULL
      || (tab_color[2] = create_color("texture/wall/wall_2.png")) == NULL
      || (tab_color[3] = create_color("texture/wall/wall_3.png")) == NULL
      || (tab_color[4] = create_color("texture/wall/wall_4.png")) == NULL
      || (tab_color[5] = create_color("texture/wall/bibli_1.png")) == NULL
      || (tab_color[6] = create_color("texture/wall/bibli_2.png")) == NULL
      || (tab_color[7] = create_color("texture/wall/bibli_3.png")) == NULL
      || (tab_color[8] = create_color("texture/wall/bibli_4.png")) == NULL
      || (tab_color[9] = create_color("texture/door.png")) == NULL)
    return (NULL);
  if (init_texture_rest(tab_color) == -1)
    return (NULL);
  return (tab_color);
}

int			init_texture_rest(sfColor ***tab_color)
{
  if ((tab_color[SOLIDER_C] = create_color(SOLIDER)) == NULL
      || (tab_color[HELMET_C] = create_color(HELMET)) == NULL
      || (tab_color[GUN_C] = create_color(GUN)) == NULL
      || (tab_color[LAMP_C] = create_color(LAMP)) == NULL
      || (tab_color[SOLIDER_F_C] = create_color(SOLIDER_F)) == NULL
      || (tab_color[AMMO_C] = create_color(AMMO)) == NULL
      || (tab_color[FLOOR_A_C] = create_color(FLOOR_A)) == NULL
      || (tab_color[FLOOR_B_C] = create_color(FLOOR_B)) == NULL
      || (tab_color[19] = create_color("texture/grass.png")) == NULL
      || (tab_color[20] = create_color("texture/grass.png")) == NULL
      || (tab_color[27] = create_color("pack/eridu757.bmp.jpg")) == NULL
      || (tab_color[28] = create_color("texture/wall/floor_a.png")) == NULL
      || init_texture_solider(tab_color) == -1)
    return (-1);
  return (0);
}

int			init_texture_solider(sfColor ***tab_color)
{
  if ((tab_color[DEAD_SOLIDER_C] = create_color(DEAD_SOLIDER)) == NULL
      || (tab_color[DEAD_S_C_2] = create_color(DEAD_S_2)) == NULL
      || (tab_color[DEAD_S_C_2 + 1] = create_color(DEAD_S_2)) == NULL
      || (tab_color[DEAD_S_C_1] = create_color(DEAD_S_1)) == NULL
      || (tab_color[DEAD_S_C_1 + 1] = create_color(DEAD_S_1)) == NULL
      || (tab_color[DEAD_S_C_0] = create_color(DEAD_S_0)) == NULL
      || (tab_color[DEAD_S_C_0 + 1] = create_color(DEAD_S_0)) == NULL
      || (tab_color[JOFF__] = create_color(JOFF)) == NULL)
    return (-1);
  return (0);
}

int			create_hud_blood(t_hud *hud)
{
  if ((hud->blood[0] = load_picture(BLOOD_20)) == NULL
      || (hud->blood[1] = load_picture(BLOOD_19)) == NULL
      || (hud->blood[2] = load_picture(BLOOD_18)) == NULL
      || (hud->blood[3] = load_picture(BLOOD_17)) == NULL
      || (hud->blood[4] = load_picture(BLOOD_16)) == NULL
      || (hud->blood[5] = load_picture(BLOOD_15)) == NULL
      || (hud->blood[6] = load_picture(BLOOD_14)) == NULL
      || (hud->blood[7] = load_picture(BLOOD_13)) == NULL
      || (hud->blood[8] = load_picture(BLOOD_12)) == NULL
      || (hud->blood[9] = load_picture(BLOOD_11)) == NULL
      || (hud->blood[10] = load_picture(BLOOD_10)) == NULL
      || (hud->blood[11] = load_picture(BLOOD_9)) == NULL
      || (hud->blood[12] = load_picture(BLOOD_8)) == NULL
      || (hud->blood[13] = load_picture(BLOOD_7)) == NULL
      || (hud->blood[14] = load_picture(BLOOD_6)) == NULL
      || (hud->blood[15] = load_picture(BLOOD_5)) == NULL
      || (hud->blood[16] = load_picture(BLOOD_4)) == NULL
      || (hud->blood[17] = load_picture(BLOOD_3)) == NULL
      || (hud->blood[18] = load_picture(BLOOD_2)) == NULL
      || (hud->blood[19] = load_picture(BLOOD_1)) == NULL
      || (hud->blood[20] = load_picture(BLOOD_0)) == NULL)
    return (-1);
  return (0);
}
