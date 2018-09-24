/*
** my.h for include  in /home/Max/Documents/delivery/wolf3d
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Sat May 13 10:22:35 2017 fourrier maxence
** Last update Thu Jun 15 15:31:40 2017 fourrier maxence
*/

#ifndef _MY_H_
# define _MY_H_

/*
** __ Include __
*/

# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# include <SFML/Graphics.h>
# include <SFML/Audio.h>

/*
** __ Define __
*/

# define RETURN_USAGE	84
# define RETURN_MALLOC	84
# define RETURN_READ	84
# define RETURN_ERROR	84

# define RETURN_SUCCESS	0

# define SCREEN_WIDTH	1024
# define SCREEN_HEIGHT	576
# define SCREEN_NAME	"My_Wolf3d"

# define BUFF_SIZE	1024

# define RIGHT		1
# define DOWN		2
# define LEFT		3
# define UP		4

# define TEX_WIDTH	64
# define TEX_HEIGHT	64

# define NB_COLOR	70
# define NB_SPRITE	70

# define HUD_SIZE	20
# define H_ID		0
# define HELMET_X	15.5
# define HELMET_Y	18.5
# define G_ID		1
# define GUN_X		4
# define GUN_Y		4
# define TIME_FIRE	30

# define BLOOD_0	"texture/hud/blood_0.png"
# define BLOOD_1	"texture/hud/blood_1.png"
# define BLOOD_2	"texture/hud/blood_2.png"
# define BLOOD_3	"texture/hud/blood_3.png"
# define BLOOD_4	"texture/hud/blood_4.png"
# define BLOOD_5	"texture/hud/blood_5.png"
# define BLOOD_6	"texture/hud/blood_6.png"
# define BLOOD_7	"texture/hud/blood_7.png"
# define BLOOD_8	"texture/hud/blood_8.png"
# define BLOOD_9	"texture/hud/blood_9.png"
# define BLOOD_10	"texture/hud/blood_10.png"
# define BLOOD_11	"texture/hud/blood_11.png"
# define BLOOD_12	"texture/hud/blood_12.png"
# define BLOOD_13	"texture/hud/blood_13.png"
# define BLOOD_14	"texture/hud/blood_14.png"
# define BLOOD_15	"texture/hud/blood_15.png"
# define BLOOD_16	"texture/hud/blood_16.png"
# define BLOOD_17	"texture/hud/blood_17.png"
# define BLOOD_18	"texture/hud/blood_18.png"
# define BLOOD_19	"texture/hud/blood_19.png"
# define BLOOD_20	"texture/hud/blood_20.png"

# define NUMBER_0	0
# define NUMBER_0_PATH	"texture/number/0.png"
# define HEAL_0_PATH	"texture/heal/0.png"
# define NUMBER_1	1
# define NUMBER_1_PATH	"texture/number/1.png"
# define HEAL_1_PATH	"texture/heal/1.png"
# define NUMBER_2	2
# define NUMBER_2_PATH	"texture/number/2.png"
# define HEAL_2_PATH	"texture/heal/2.png"
# define NUMBER_3	3
# define NUMBER_3_PATH	"texture/number/3.png"
# define HEAL_3_PATH	"texture/heal/3.png"
# define NUMBER_4	4
# define NUMBER_4_PATH	"texture/number/4.png"
# define HEAL_4_PATH	"texture/heal/4.png"
# define NUMBER_5	5
# define NUMBER_5_PATH	"texture/number/5.png"
# define HEAL_5_PATH	"texture/heal/5.png"
# define NUMBER_6	6
# define NUMBER_6_PATH	"texture/number/6.png"
# define HEAL_6_PATH	"texture/heal/6.png"
# define NUMBER_7	7
# define NUMBER_7_PATH	"texture/number/7.png"
# define HEAL_7_PATH	"texture/heal/7.png"
# define NUMBER_8	8
# define NUMBER_8_PATH	"texture/number/8.png"
# define HEAL_8_PATH	"texture/heal/8.png"
# define NUMBER_9	9
# define NUMBER_9_PATH	"texture/number/9.png"
# define HEAL_9_PATH	"texture/heal/9.png"

# define HELMET_ID	0
# define HELMET_PATH	"texture/hud/helmet.png"
# define HELMET_1	1
# define HELMET__1	"texture/hud/helmet_1.png"
# define HELMET_2	2
# define HELMET__2	"texture/hud/helmet_2.png"
# define HELMET_3	3
# define HELMET__3	"texture/hud/helmet_3.png"
# define HELMET_4	4
# define HELMET__4	"texture/hud/helmet_4.png"
# define HELMET_5	5
# define HELMET__5	"texture/hud/helmet_5.png"
# define HELMET_6	6
# define HELMET__6	"texture/hud/helmet_6.png"
# define HELMET_7	7
# define HELMET__7	"texture/hud/helmet_7.png"
# define HELMET_8	8
# define HELMET__8	"texture/hud/helmet_8.png"
# define HELMET_9	9
# define HELMET__9	"texture/hud/helmet_9.png"
# define GUN_ID		10
# define GUN_PATH	"texture/hud/gun.png"
# define SHOOT_ID	11
# define SHOOT_PATH	"texture/hud/shooting.png"
# define H_SHOOT_ID	12
# define H_SHOOT_PATH	"texture/hud/h_shooting.png"

# define SOLIDER	"texture/sprite/solider.png"
# define SOLIDER_C	11
# define HELMET		"texture/sprite/helmet.png"
# define HELMET_C	12
# define GUN		"texture/sprite/gun.png"
# define GUN_C		13
# define LAMP		"texture/sprite/lamp.png"
# define LAMP_C		14
# define SOLIDER_F	"texture/sprite/solider_shoot.png"
# define SOLIDER_F_C	15
# define AMMO		"texture/sprite/ammo.png"
# define AMMO_C		16

# define FLOOR_A_C	17
# define FLOOR_A	"texture/wall/floor_a.png"
# define FLOOR_B_C	18
# define FLOOR_B	"texture/wall/floor_b.png"

# define CEILING_A_C	27
# define CEILING_A	"texture/wall/ceiling_a.png"
# define CEILING_B_C	28
# define CEILING_B	"texture/wall/ceiling_b.png"

# define JOFF__		47
# define JOFF		"texture/joff.png"
# define JOFF_C		62
# define JOFF_X		2
# define JOFF_Y		6
# define JOFF_SPEED	0.06

# define DEAD_SOLIDER	"texture/sprite/dead_solider.png"
# define DEAD_SOLIDER_C	40
# define DEAD_S_2	"texture/sprite/dead_solider_2.png"
# define DEAD_S_C_2	41
# define DEAD_S_1	"texture/sprite/dead_solider_1.png"
# define DEAD_S_C_1	43
# define DEAD_S_0	"texture/sprite/dead_solider_0.png"
# define DEAD_S_C_0	45

# define TO_RAD(a)	(M_PI * a / 180)
# define ANGLE		TO_RAD(90)
# define VISION		66
# define MOVE_SPEED	0.1
# define ROTATE_SPEED	0.04
# define POS_X		6
# define POS_Y		2
# define AMMO_BOX	10
# define REGEN_HP	6

# define MONSTER_SPEED	0.04

# define DIR_RANGE	15
# define DIR_SPACE	5

# define SKY		color(99, 87, 87, 255)
# define FLOOR		color(48, 44, 44, 255)
# define WALL_2		color(219, 14, 14, 255)
# define WALL_1		color(180, 13, 13, 255)

/*
** __ T_list __
*/

typedef struct		s_list
{
  char			*data;
  struct s_list		*next;
}			t_list;

typedef struct		s_my_sprite
{
  sfVector2i		drawstart;
  sfVector2i		drawend;
  sfVector2f		t;
  int			s;
  int			h;
  int			w;
}			t_my_sprite;

typedef struct		s_my_framebuffer
{
  sfUint8		*pixels;
  int			width;
  int			height;
}			t_my_framebuffer;

typedef struct		s_sprite
{
  sfSprite		*play;
  sfSprite		*quit;
  sfSprite		*option;
  sfSprite		*menu;
}			t_sprite;

typedef struct		s_graph
{
  sfEvent		event;
  sfRenderWindow	*window;
  t_my_framebuffer	*framebuffer;
  sfTexture		*texture;
  t_sprite		*spr;
  sfSprite		*sprite;
}			t_graph;

typedef struct		s_map
{
  int			**map;
  int			width;
  int			height;
}			t_map;

typedef struct		s_player
{
  sfVector2f		pos;
  double		move_speed;
  double		rotate_speed;
  double		angle;
  int			vision;
  sfVector2f		dir;
  sfVector2f		plane;
}			t_player;

typedef struct		s_menu
{
  int			play;
  int			quit;
  int			option;
}			t_menu;

typedef struct		s_ray
{
  sfVector2f		pos;
  sfVector2f		dir;
  sfVector2f		side;
  sfVector2f		delta;
  sfVector2i		map;
  sfVector2i		step;
  sfVector2i		draw;
  double		wallx;
  int			wall_side;
  int			height;
  int			i;
  int			y;
}			t_ray;

typedef struct		s_tab_sprite
{
  sfVector2f		pos;
  int			color;
  int			fire;
}			t_tab_sprite;

typedef struct		s_hud
{
  int			cpt;
  int			hp;
  int			helmet;
  int			ammo;
  long			time;
  int			gun;
  sfSprite		**sprite;
  sfSprite		**number;
  sfSprite		**heal;
  sfSprite		**blood;
}			t_hud;

typedef struct		s_all
{
  t_player		*player;
  t_map			*game;
  t_graph		*graph;
  t_menu		*menu;
  sfColor		***color;
  t_tab_sprite		**sprite;
  t_hud			*hud;
  sfVector2i		addr;
  sfVector2f		pos;
  sfMusic		**sound;
}			t_all;

/*
** __ wolf3d __
*/

void		draw_victory(t_all *all);
int		has_won(t_all *all);
void		move_joff(t_all *all);

int		regen_hp(t_all *all);
void		add_ammo(t_all *all);
int		pos_ammo(t_all *all);

sfMusic		*init_music(char *str);
sfMusic		**init_sound();

void		enemy_can_fire(t_all *all, int i);

int		init_thread(t_all *all);
void		*received_thread(void *arg);
void		*send_thread(void *arg);

void		write_zbuffer(t_ray *ray, double *zbuffer, int i);
double		*malloc_zbuffer();
int		end_raycast(t_all *all, t_ray *ray, double *zbuffer);

int		check_mouse(t_all *all);

int		draw_0(t_all *all, int nb);
int		draw_10(t_all *all, int nb);
int		draw_100(t_all *all, int nb);

int		draw_0_(t_all *all, int nb);
int		draw_10_(t_all *all, int nb);
int		draw_100_(t_all *all, int nb);

int		pos_gun(t_all *all);
void		put_gun(t_all *all);

void		draw_helmet(t_all *all);
void		draw_health(t_all *all);
void		draw_gun(t_all *all);
void		draw_ammo(t_all *all);
void		draw_blood(t_all *all);

int		check_dir_fire(t_all *all);
int		sprite_touch(t_all *all, sfVector2f map);

void		draw_fire(t_all *all);
int		check_fire(t_all *all);
int		fire(t_all *all);
int		can_fire_again(t_all *all, long nb);

int		pos_helmet(t_all *all);
void		put_helmet(t_all *all);

int		can_move(int nb);

void		walk_enemy(t_all *all, float dist,
			   sfVector2f delta, int i);
int		check_move_enemy(t_all *all, int i);
void		move_enemy(t_all *all);
int		no_wall_enemy(t_all *all, sfVector2f dir,
			      sfVector2f delta, int i);

sfVector2f	init_transform(t_all *all, int nb);
sfVector2i	my_get_draw_s(int sheight,
			      int spritescreen, sfVector2f transform);
sfVector2i	my_get_draw_e(int sheight,
			      int spritescreen, sfVector2f transform);
void		boucle(t_all *all, double *Zbuffer,
		       t_my_sprite *my_s, int nb);
int		my_draw_enemy(t_ray *ray, t_all *all, double *Zbuffer);
void		draw_sprite_color(t_all *all, sfVector2i cpt,
				  sfVector2i tex, t_my_sprite *my_s);

t_tab_sprite	**init_sprite_solider(t_tab_sprite **my_sprite);
t_tab_sprite	**init_sprite_ammo(t_tab_sprite **my_sprite);
t_tab_sprite	**init_sprite_lamp(t_tab_sprite **my_sprite);
t_my_sprite	*init_my_sprite(t_my_sprite *my_sprite, t_all *all, int nb);
int		get_nb_sprite(t_all *all);
sfVector2f	*algo_sort(sfVector2f *sprite, int total);
sfVector2f	*sort_sprite(t_all *all, int total);

int		wolf3d(char *str, char *nb1, char *nb2);

t_player	*rotate_left(t_player *player, int power);
t_player	*rotate_right(t_player *player, int power);

t_player	*move_front(t_player *player, t_map *game, int nb);
t_player	*move_back(t_player *player, t_map *game);
t_player	*move_left(t_player *player, t_map *game);
t_player	*move_right(t_player *player, t_map *game);

int		game(t_all *all);
int		my_event(t_all *all);
int		button_pressed(t_all *all);

t_ray		*init_ray(t_player *player, int i);
sfVector2i	set_step(t_ray *ray);
int		get_line_height(t_ray *ray, sfVector2i step, int side);
int		get_side(t_ray *ray, sfVector2i step, int **map);
void		my_draw_wall(t_ray *ray, t_all *all, int i);
void		my_draw_floor(t_ray *ray, t_all *all, int i);
int		my_raycast(t_all *all);

sfVector2f	get_floor(t_ray *ray);
void		draw_floor(t_all *all, sfVector2i pos,
			   sfVector2i tfloor, int x);
double		get_weight(t_ray *ray, double cdist);

int		draw_hud(t_all *all);
int		draw_all(t_all *all);
int		draw_wall(t_all *all);
int		draw_minimap(t_map *game, t_graph *graph, t_player *player);

t_all		*init_all(char *str);
t_map		*init_game(char *str);
t_player	*init_player();
t_graph		*init_graph();
t_sprite	*init_spr();

sfColor		***init_texture();
int		init_texture_rest(sfColor ***tab_color);
int		init_texture_solider(sfColor ***tab_color);
int		create_hud_blood(t_hud *hud);
t_hud		*init_hud();

int		create_hud_number(t_hud *hud);
int		create_hud_sprite(t_hud *hud);

sfColor		**create_color(char *str);
t_tab_sprite	**init_sprite_tab();
t_tab_sprite	*create_sprite(float x, float y, int color);

void		my_free_map(int **map);
void		clear_ressources(t_all *all);
sfColor		color(int r, int g, int b, int a);
sfVector2i	create_vector_i(int x, int y);
sfSprite	*load_picture(char *str);

int		**create_map(char *str);
int		get_width(char *str);
int		get_height(char *str);
int		**cpy_map(int **map, char *str);

char		*get_buff(char *str);

void		check_where_clicked(sfVector2i vec, t_menu *menu,
				    t_graph *graph);

int		init_menu(t_all *all);
int		menu(t_all *all);
int		menu_event(t_graph *graph, t_menu *menu);

sfVector2i	create_draw(int height);
sfVector2i	get_tex_x(t_ray *ray, int side, int height, sfVector2i step);
sfVector2i	get_tex_y(t_ray *ray, int height, sfVector2i tex, int c);
void		draw_line(sfColor color, sfVector2i x,
			  int side, t_all *all);

sfColor		my_color(int x, int y, sfColor **color);
sfColor		**get_color(t_all *all, t_ray *ray);

/*
** __ lib graph __
*/

sfRenderWindow		*create_window(char *name, int width, int height);
sfUint8*		create_pixel_buffer(int width, int height);
t_my_framebuffer	*my_framebuffer_create(int width, int height);
void			my_put_pixel(t_my_framebuffer *, int x,
				     int y, sfColor);
void                    my_draw_line(t_my_framebuffer *,
                                     sfVector2i, sfVector2i, sfColor);
int                     draw_line_1(t_my_framebuffer *, sfVector2i,
                                    sfVector2i, sfColor);
int                     draw_line_2(t_my_framebuffer *, sfVector2i,
                                    sfVector2i, sfColor);
int                     draw_line_3(t_my_framebuffer *, sfVector2i,
                                    sfVector2i, sfColor);
int                     draw_line_4(t_my_framebuffer *, sfVector2i,
                                    sfVector2i, sfColor);
int                     draw_line_5(t_my_framebuffer *, sfVector2i,
                                    sfVector2i, sfColor);
int                     draw_line_6(t_my_framebuffer *, sfVector2i,
                                    sfVector2i, sfColor);
int                     draw_line_7(t_my_framebuffer *, sfVector2i,
                                    sfVector2i, sfColor);
int                     draw_line_8(t_my_framebuffer *, sfVector2i,
                                    sfVector2i, sfColor);
int                     line_is_vertical(t_my_framebuffer *,
                                         sfVector2i, sfVector2i, sfColor);
int                     line_is_horizontal(t_my_framebuffer *,
                                           sfVector2i, sfVector2i, sfColor);

/*
** __ Lib __
*/

t_list	*my_rev_list(t_list *list);
t_list	*my_link_list(t_list *list, char *data);
t_list	*my_list_cpy(t_list *list);
int	my_list_size(t_list *begin);
int	my_list_is_empty(t_list *liste);
void	my_print_list(t_list *liste);

int	my_decimal_to_octal(int nb);
int	my_strlen(char *str);
int	my_str_who_bigger(char *s1, char *s2);
int	my_str_to_int(char *str);
int	my_strcmp(char *a, char *b);
int	my_swap(int *a, int *b);

void	my_putstr_error(char *str);
void	my_putnbr(int nb);
void	my_putchar(char a);
void	my_putstr(char *str);

char	*my_int_to_str(int nb);
char	*my_str_maj(char *str);
char	*my_decimal_to_hexa(int nb);
char	*supp_0(char *str);
char	*my_revstr(char *str);
char	*my_strcpy(char *dest, char *src);

#endif /* !__MY_H_ */
