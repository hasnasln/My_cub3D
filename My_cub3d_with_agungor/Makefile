NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

GET_NEX_LINE =	get_next_line/get_next_line.c \
				get_next_line/get_next_line_utils.c

MLXFLAG = -L minilibx-linux -lmlx -lXext -lX11 -lm

ERRORS =	errors/error_message.c \
			errors/animation_functions.c

LIBFT =	libft/libft.a

SAFE_ALLOCATION =	safe_allocation/clear_residual_data.c \
					safe_allocation/s_free.c \
					safe_allocation/s_malloc.c\
					safe_allocation/s_allocation_utils.c

ALLOCATE =	SRC/allocation/t_cub3d_allocation.c \
			SRC/allocation/program_exit.c

CHECK_CENTER =	SRC/check_center/check_arg.c \
				SRC/check_center/map_center.c \
				SRC/check_center/read_game_map.c \
				SRC/check_center/set_player.c \
				SRC/check_center/map_helper.c \
				SRC/check_center/check_map.c 

RAYCAST =	SRC/raycast/raycast.c \
			SRC/raycast/find_wall.c \
			SRC/raycast/draw.c

HELPER =	SRC/helper/pixel_operations.c \
			SRC/helper/xpm_to_image.c \
			SRC/helper/key_press.c

SRC =	SRC/main.c \
		$(ALLOCATE) \
		$(CHECK_CENTER) \
		$(ERRORS) \
		$(SAFE_ALLOCATION) \
		$(GET_NEX_LINE) \
		$(RAYCAST) \
		$(HELPER)


OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: $(LIBFT) mlx $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L libft -lft $(MLXFLAG)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C libft

mlx:
	make -C minilibx-linux

clean:
	rm -rf $(OBJ_DIR)
	make clean -C libft
	make clean -C minilibx-linux

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all

norm: 
	norminette $(SRC)

.PHONY: all clean fclean re
