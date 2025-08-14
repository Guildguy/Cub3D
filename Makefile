# Program
NAME = cub3D

# Compiler
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -Iincludes -ILibft

# Directories
LIBFT = Libft/libft.a
SRC_DIR = src/
OBJ_DIR = objs/

# Find all .c files
SRCS = $(shell find $(SRC_DIR) -type f -name "*.c")

OBJS = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))

# Libraries
LIBS = -lreadline

all: $(NAME)

fd: all
	valgrind --track-fds=yes --suppressions=suppfile.sup ./$(NAME)

v: all
	valgrind -q --leak-check=full --show-leak-kinds=all --suppressions=suppfile.sup ./$(NAME)

val: all
	@/bin/valgrind -q --suppressions=suppfile.sup \
				--leak-check=full \
				--show-leak-kinds=all \
				--track-origins=yes \
				--track-fds=yes \
				--trace-children=yes \
				--trace-children-skip='*/bin/*,*/sbin/*,/usr/bin/*' \
				./${NAME}

$(LIBFT):
	make -C ./Libft

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o ./$(NAME) $(OBJS) $(LIBFT) $(LIBS)

clean:
	$(RM) -r $(OBJ_DIR)
	make clean -C ./Libft

fclean: clean
	$(RM) ./$(NAME)
	make fclean -C ./Libft

re: fclean all

.PHONY: all clean fclean re