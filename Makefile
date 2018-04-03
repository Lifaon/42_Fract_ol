# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/23 20:02:57 by mlantonn          #+#    #+#              #
#    Updated: 2018/04/03 16:14:55 by mlantonn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED = \033[31m
GRE = \033[32m
YEL = \033[33m
BLU = \033[34m
MAG = \033[35m
CYA = \033[36m
EOC = \033[37m

NAME = fractol
DIR_NAME = fract_ol
LIBFT_DIR = libft
MLX_DIR = mlx_macOS

CFLAGS = -Wall -Wextra -Werror
FMWKS = -framework OpenGL -framework AppKit

LIBS = $(LIBFT) $(LIBMLX)
LIBFT = -L $(LIBFT_DIR) -lft
LIBMLX = -L $(MLX_DIR) -lmlx

INCS = $(INC) $(INCMLX)
INC = -I includes -I $(LIBFT_DIR)/includes
INCMLX = -I $(MLX_DIR)

OBJS = $(SRCS:.c=.o)
OBJS_DIR = objs
OBJS_SUB_DIRS = draw events fractals init
OBJS_PRE = $(addprefix $(OBJS_DIR)/, $(OBJS))

SRCS_DIR = srcs
SRCS =	draw/anti_alias.c \
		draw/blur.c \
		draw/comp_pow.c \
		draw/comps.c \
		draw/draw_thread.c \
		draw/draw_image.c \
		\
		events/change_aa.c \
		events/change_blur.c \
		events/change_color.c \
		events/change_iter.c \
		events/change_pow.c \
		events/move_julia.c \
		events/move.c \
		events/redraw.c \
		events/reset_all.c \
		events/zoom.c \
		\
		fractals/burning_ship.c \
		fractals/moz.c \
		fractals/julia.c \
		fractals/julneg.c \
		fractals/mandelbar.c \
		fractals/mandelbrot.c \
		fractals/mandelneg.c \
		fractals/mandisk.c \
		fractals/newton.c \
		fractals/newtwo.c \
		\
		init/check_arg.c \
		init/color_init.c \
		init/data_init.c \
		init/img_init.c \
		init/init_all.c \
		init/t_mlx_init.c \
		init/thr_init.c \
		\
		exit_all.c \
		main.c

.PHONY = all $(OBJS_DIR) $(NAME) clean del fclean re

all: $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@echo "gcc $(CFLAGS) $(INCS) -c $^ -o $(CYA)$@$(EOC)"
	@gcc $(CFLAGS) $(INCS) -c $^ -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(addprefix $(OBJS_DIR)/, $(OBJS_SUB_DIRS))

$(NAME): $(OBJS_DIR) $(OBJS_PRE)
	@make -C $(LIBFT_DIR)
	@make -C $(MLX_DIR)
	@echo "gcc $(CFLAGS) $(OBJS_PRE) $(LIBS) $(FMWKS) -o $(MAG)$(NAME)$(EOC)"
	@gcc $(CFLAGS) $(OBJS_PRE) $(LIBS) $(FMWKS) -o $(NAME)

del_objs:
	@echo "$(RED)rm -rf$(EOC) $(OBJS_DIR) from $(DIR_NAME)"
	@rm -rf $(OBJS_DIR)

del_exe:
	@echo "$(RED)rm -rf$(EOC) $(NAME)"
	@rm -rf $(NAME)

clean: del_objs
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(MLX_DIR)

fclean: clean del_exe
	@make del_exe -C $(LIBFT_DIR)
	@make del_exe -C $(MLX_DIR)

re: fclean all

exe: del_objs del_exe all
