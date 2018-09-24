##
## Makefile for makefile in /home/Max/Documents/delivery/CPE_year_Pushswap
## 
## Made by fourrier maxence
## Login   <maxence.fourrier@epitech.eu>
## 
## Started on  Tue Apr 11 10:05:45 2017 fourrier maxence
## Last update Fri Jun  9 13:17:04 2017 fourrier maxence
##

NAME		= 	wolf3d

CC		= 	gcc

RM		= 	rm -f

SRCS		=	main.c

OBJS		= 	$(SRCS:.c=.o)

all		:	$(NAME)

$(NAME)		: 	$(OBJS)
			$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(LDFLAGS)

clean		:
			$(RM) $(OBJS)

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY		: 	all clean fclean re

