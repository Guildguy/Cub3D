# Program
NAME = cub3D

# Compiler and Flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -Iincludes -ILibft -I$(MLX_DIR)

# Directories
SRC_DIR = src
OBJ_DIR = objs
LIBFT_DIR = Libft
MLX_DIR = minilibx-linux

# Libraries
LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm

# Sources and Objects
SRCS =  src/cleanup/cleanup.c \
		src/events/events.c src/events/close_event.c src/events/movement_event.c src/events/rotate_event.c \
		src/init_files/init_player.c src/init_files/init.c \
		src/loader/load_images.c \
		src/parser/config_parser.c src/parser/main_parser.c src/parser/map_list_utils.c \
		src/parser/map_parser.c src/parser/map_validator_utils.c src/parser/map_validator.c \
		src/parser/config_utils.c \
		src/raycasting/raycasting.c \
		src/render/color.c src/render/render.c src/render/wall.c \
		src/validator/valid_format.c \
		src/main.c

OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# Default target
all: $(NAME)

v: all
	valgrind -q --leak-check=full --show-leak-kinds=all ./$(NAME)

val: all
	@/bin/valgrind -q \
				--leak-check=full \
				--show-leak-kinds=all \
				--track-origins=yes \
				--track-fds=yes \
				--trace-children=yes \
				--trace-children-skip='*/bin/*,*/sbin/*,/usr/bin/*' \
				./${NAME}

# Link final binary
$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBFT) $(MLX_FLAGS)

# Compile C files into .o files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Build libft and minilibx
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

# Clean
clean:
	$(RM) -r $(OBJ_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLX_DIR)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
