CFLAGS	= -Wall -Werror -Wextra -Iincludes -Ilibft1
CC		= cc $(CFLAGS)
MLX_DIR	= mlx_linux
MLX_LIB	= $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd

NAME =	so_long
LIBFT =	libft1/libft.a
SRCS =	main.c \
		src/events/ft_handle_event.c \
		src/events/ft_texture_loader.c \
		src/events/ft_handle_trap.c \
		src/events/ft_map_manager.c \
		src/events/ft_game_manager.c \
		src/events/get_next_line.c \
		src/render/ft_render_map.c \
		src/utils/ft_player_controller.c \
		src/utils/ft_trap_moves.c \
		src/utils/get_next_line_utils.c \
		src/validator/ft_check_error.c \
		src/validator/ft_check_map.c \

OBJ = $(SRCS:.c=.o)

all: $(MLX_LIB) $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX_LIB)
	$(CC) $(OBJ) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

$(MLX_LIB):
	cd $(MLX_DIR) && $(MAKE)

$(LIBFT):
	cd libft1 && $(MAKE)

%.o: %.c
	$(CC) -I$(MLX_DIR) -c $< -o $@

clean:
	rm -f $(OBJ)
	cd libft1 && $(MAKE) clean

fclean: clean
	cd libft1 && $(MAKE) fclean
	cd $(MLX_DIR) && $(MAKE) clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re