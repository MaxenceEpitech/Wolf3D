/*
** my.h for include  in /home/Max/Documents/delivery/wolf3d
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Sat May 13 10:22:35 2017 fourrier maxence
** Last update Tue May 23 10:12:28 2017 fourrier maxence
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

sfVector2f		move_forward(sfVector2f pos, float direction,
				     float distance);
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

int	my_strlen(char *str);
int	my_str_who_bigger(char *s1, char *s2);
int	my_str_to_int(char *str);
int	my_strcmp(char *a, char *b);

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
