#
#

RED = \033[31m
GRE = \033[32m
YEL = \033[33m
BLU = \033[34m
MAG = \033[35m
CYA = \033[36m
EOC = \033[37m

NAME = libmlx.a
DIR_NAME = mlx_macOS
SRC =	mlx_shaders.c \
		mlx_new_window.m \
		mlx_init_loop.m \
		mlx_new_image.m \
		mlx_xpm.c \
		mlx_int_str_to_wordtab.c

OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

del_objs:
	@echo "$(RED)rm -rf$(EOC) objs from $(DIR_NAME)"
	@rm -rf $(OBJ)

del_exe:
	@echo "$(RED)rm -rf$(EOC) $(NAME)"
	@rm -rf $(NAME)

clean: del_objs

fclean: clean del_exe

re: fclean all

exe: del_objs del_exe all
