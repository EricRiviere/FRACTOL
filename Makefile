# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eriviere <eriviere@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/22 12:56:31 by eriviere          #+#    #+#              #
#    Updated: 2024/10/24 17:32:14 by eriviere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

# Object & source files
SRCS = main.c s_utils.c init.c math_utils.c render.c events.c colors.c
OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)

# Compilation flags
CFLAGS = -Iminilibx-linux -Wall -Wextra -Werror
MLX_FLAGS = -Lminilibx-linux -lmlx -lX11 -lXext -lm

# MiniLibX Library
MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a

# Main rule
all: $(MLX_LIB) $(NAME)

# Compile executable file
$(NAME): $(OBJS)
	cc $(OBJS) $(MLX_FLAGS) -o $(NAME)

# Compile objects
%.o: %.c
	cc $(CFLAGS) -c $< -o $@

-include $(DEPS)

# Download & compile MinilibX if it doesn't exist
$(MLX_LIB):
	@if [ ! -d "$(MLX_DIR)" ]; then \
		echo "MiniLibX not found, cloning..."; \
		git clone https://github.com/42Paris/minilibx-linux.git; \
	fi
	@make -C $(MLX_DIR)

# Clean object files & dependancies
clean:
	rm -f $(OBJS) $(DEPS)
	@make -C $(MLX_DIR) clean

# Clean all (exacutable & objects)
fclean: clean
	rm -f $(NAME)

# Recompile everything
re: fclean all

.PHONY: all clean fclean re

