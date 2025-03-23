# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -I includes -I src/model -I src/controller -I src/view

# MinilibX path

MLX_PATH = minilibx-linux/


# Object files
OBJ = src/model/game.o src/model/map.o src/model/character.o src/controller/controller.o src/view/view.o src/main.o

# Linking flags (include the MinilibX library)
LDFLAGS = -L$(MLX_PATH) -lmlx -lX11 -lXext -lm

# Final executable
NAME = game

# Compilation and linking rules
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

# Rule for compiling the object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean the build
clean:
	rm -f $(OBJ)

# Clean the final executable
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all
