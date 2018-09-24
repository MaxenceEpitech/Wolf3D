/*
** my.h for include  in /home/Max/Documents/delivery/wolf3d
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Sat May 13 10:22:35 2017 fourrier maxence
** Last update Tue Jun  6 10:59:40 2017 fourrier maxence
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

/*
** __ Define __
*/

# define EXIT_MALLOC	84

# define RETURN_USAGE	84
# define RETURN_MALLOC	84
# define RETURN_READ	84
# define RETURN_ERROR	84

# define RETURN_SUCCESS	0

# define SCREEN_WIDTH	100
# define SCREEN_HEIGHT	100

/*
** __ T_list __
*/

typedef struct		s_my_framebuffer
{
  sfUint8		*pixels;
  int			width;
  int			height;
}			t_my_framebuffer;

/*
** __ lib graph __
*/

float			raycast(sfVector2f pos, float direction,
				int **map, sfVector2i mapSize);
sfVector2f		init_all(sfVector2i *pos_map, sfVector2f pos,
                                 sfVector2f *dir, float direction);
void			get_all(sfVector2f *side, sfVector2i *pos_map,
                                sfVector2f delta, sfVector2i step);
sfVector2f		get_side(sfVector2f dir, sfVector2f pos,
                                 sfVector2f delta);
sfVector2i		get_step(sfVector2f dir);
sfVector2f		move_forward(sfVector2f pos, float direction,
				     float distance);
void			my_put_pixel(t_my_framebuffer *, int x,
				     int y, sfColor);
void			my_draw_line(t_my_framebuffer *,
                                     sfVector2i, sfVector2i, sfColor);
int			draw_line_1(t_my_framebuffer *, sfVector2i,
                                    sfVector2i, sfColor);
int			draw_line_2(t_my_framebuffer *, sfVector2i,
                                    sfVector2i, sfColor);
int			draw_line_3(t_my_framebuffer *, sfVector2i,
                                    sfVector2i, sfColor);
int			draw_line_4(t_my_framebuffer *, sfVector2i,
                                    sfVector2i, sfColor);
int			draw_line_5(t_my_framebuffer *, sfVector2i,
                                    sfVector2i, sfColor);
int			draw_line_6(t_my_framebuffer *, sfVector2i,
                                    sfVector2i, sfColor);
int			draw_line_7(t_my_framebuffer *, sfVector2i,
                                    sfVector2i, sfColor);
int			draw_line_8(t_my_framebuffer *, sfVector2i,
                                    sfVector2i, sfColor);
int			line_is_vertical(t_my_framebuffer *,
                                         sfVector2i, sfVector2i, sfColor);
int			line_is_horizontal(t_my_framebuffer *,
                                           sfVector2i, sfVector2i, sfColor);

#endif /* !__MY_H_ */
