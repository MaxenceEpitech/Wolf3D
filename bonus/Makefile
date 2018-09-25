##
## Makefile for makefile in /home/Max/Documents/delivery/CPE_year_Pushswap
## 
## Made by fourrier maxence
## Login   <maxence.fourrier@epitech.eu>
## 
## Started on  Tue Apr 11 10:05:45 2017 fourrier maxence
## Last update Thu Jun 15 14:08:57 2017 fourrier maxence
##

DEBUG		=	yes

NAME		= 	wolf3d

CC		= 	gcc

ECHO		=	echo

NORMAL		=	tput sgr0

RED		=	tput setaf 1

BOLD		=	tput bold

BLUE		=	tput setaf 5

RM		= 	rm -f

SRCS_DIR	= 	./src/

WOLF3D		= 	./my_src/

SRCS		=	$(WOLF3D)main.c				\
			$(WOLF3D)tools.c			\
			$(WOLF3D)ammo.c				\
			$(WOLF3D)draw_ammo.c			\
			$(WOLF3D)sprite_tools.c			\
			$(WOLF3D)move_joff.c			\
			$(WOLF3D)wolf3d.c			\
			$(WOLF3D)audio.c			\
			$(WOLF3D)check_fire.c			\
			$(WOLF3D)enemy_fire.c			\
			$(WOLF3D)raycast_buffer.c		\
			$(WOLF3D)gun.c				\
			$(WOLF3D)draw_health.c			\
			$(WOLF3D)thread.c			\
			$(WOLF3D)rotate.c			\
			$(WOLF3D)utils.c			\
			$(WOLF3D)helmet.c			\
			$(WOLF3D)fire.c				\
			$(WOLF3D)mouse.c			\
			$(WOLF3D)init_sprite.c			\
			$(WOLF3D)init.c				\
			$(WOLF3D)hud.c				\
			$(WOLF3D)draw_hud.c			\
			$(WOLF3D)draw_floor.c			\
			$(WOLF3D)tools_enemy.c			\
			$(WOLF3D)move_enemy.c			\
			$(WOLF3D)draw_enemy.c			\
			$(WOLF3D)menu.c				\
			$(WOLF3D)action_menu.c			\
			$(WOLF3D)game.c				\
			$(WOLF3D)get_buff.c			\
			$(WOLF3D)init_texture.c			\
			$(WOLF3D)raycast.c			\
			$(WOLF3D)tools_raycast.c		\
			$(WOLF3D)move.c				\
			$(WOLF3D)draw.c				\
			$(WOLF3D)create_map.c			\
			$(WOLF3D)my_framebuffer_create.c	\
			$(WOLF3D)create_windows.c		\
			$(WOLF3D)create_pixel_buffer.c		\
			$(SRCS_DIR)my_put_pixel.c		\
			$(SRCS_DIR)my_draw_line.c		\
			$(SRCS_DIR)my_draw_line_2.c		\
			$(SRCS_DIR)my_draw_line_3.c

OBJS		= 	$(SRCS:.c=.o)

CFLAGS		+= 	-I./include ##-Wall -Werror -Wextra

LDFLAGS		+=	-L./lib/my -lmy -lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system -lm -lpthread

ifeq ($(DEBUG), yes)
	CFLAGS	+=	-g3
endif

all		:	$(NAME)
			$(NORMAL)

$(NAME)		: 	print_debug $(OBJS)
			@make -C ./lib/my
			@$(BLUE)
			@$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(LDFLAGS)
			@$(RED)
			@$(BOLD)
			@$(ECHO) ""
			@$(ECHO) "___________		START MAKE		___________"
			@$(BLUE)
			@$(ECHO) ""
			@$(ECHO) "OBJS		= OK"
			@$(ECHO) "Lib Make	= OK"
			@$(ECHO) "Binary		= OK"
			@$(ECHO) ""
			@$(RED)
			@$(ECHO) "___________		END MAKE		___________"
			@$(ECHO) ""
			@$(ECHO) ""
			@$(NORMAL)

clean		:	print_debug
			@make clean -C ./lib/my
			@$(RM) $(OBJS)
			@$(RED)
			@$(BOLD)
			@$(ECHO) ""
			@$(ECHO) "___________		START CLEAN		___________"
			@$(BLUE)
			@$(ECHO) ""
			@$(ECHO) "Lib clean	= OK"
			@$(ECHO) "OBJS deleted 	= OK"
			@$(ECHO) ""
			@$(RED)
			@$(ECHO) "___________		END CLEAN		___________"
			@$(ECHO) ""
			@$(ECHO) ""
			@$(NORMAL)

fclean		:	clean
			@make fclean -C ./lib/my
			@$(RM) $(NAME)
			@$(RED)
			@$(BOLD)
			@$(ECHO) ""
			@$(ECHO) "___________		START FCLEAN		___________"
			@$(BLUE)
			@$(ECHO) ""
			@$(ECHO) "Lib fclean	= OK"
			@$(ECHO) "Binary deleted 	= OK"
			@$(ECHO) ""
			@$(RED)
			@$(ECHO) "___________		END FCLEAN		___________"
			@$(ECHO) ""
			@$(ECHO) ""
			@$(NORMAL)

print_debug	:
ifeq ($(DEBUG), yes)
			@$(BLUE)
			@$(BOLD)
			@echo ""
			@echo "  ____  _____ ____  _   _  ____   __  __  ___  ____  _____ "
			@echo " |  _ \| ____| __ )| | | |/ ___| |  \/  |/ _ \|  _ \| ____|"
			@echo " | | | |  _| |  _ \| | | | |  _  | |\/| | | | | | | |  _|  "
			@echo " | |_| | |___| |_) | |_| | |_| | | |  | | |_| | |_| | |___ "
			@echo " |____/|_____|____/ \___/ \____| |_|  |_|\___/|____/|_____|"
			@echo ""
			@$(NORMAL)
endif

re		:	print_debug fclean all

.SILENT		:

.PHONY		: 	all clean fclean re

