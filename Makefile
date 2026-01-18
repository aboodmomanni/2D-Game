NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror

MLX_DIR = mlx
MLX_LIB = $(MLX_DIR)/libmlx.a

LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

MLX_FLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm -lz
INCLUDES = -I$(MLX_DIR) -I$(LIBFT_DIR)

SRCS =	launcher.c \
		setup.c \
		board_loader.c \
		board_checker.c \
		grid_utils.c \
		path_finder.c \
		display.c \
		controls.c \
		hero_motion.c

OBJS = $(SRCS:.c=.o)

RM = rm -f

all: $(NAME)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT_LIB) $(OBJS)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) $(MLX_LIB) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
