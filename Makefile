# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcuevas- <lcuevas-@student.42malaga.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/19 12:51:14 by lcuevas-          #+#    #+#              #
#    Updated: 2024/12/19 12:51:15 by lcuevas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

MLX42_PATH = libs/MLX42
MLX42 = $(MLX42_PATH)/build/libmlx42.a
#MLX42_BUILD_PATH = $(MLX42_PATH)/build

LIBFT_PATH = libs/libft
LIBFT = $(LIBFT_PATH)/libft.a

HEADERS = -I ./libs -I $(MLX42_PATH)/include/MLX42 -I $(LIBFT_PATH)

SRCS =	src/ft_main.c\

OBJS = $(SRCS:src/%.c=obj/%.o)

# colores?

######################################################

all : $(MLX42) $(LIBFT) $(NAME)

# .SILENT: pa silenciar echos

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX42) $(LIBFT) $(HEADERS) -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/" -o $(NAME) -lm
#a;adido el -lm para linkear bien la libreria math y poder tener floor y ceiling y eso. Podriamos hacer las nuestras si no.

$(LIBFT):
	make -C $(LIBFT_PATH)

$(MLX42):
	cmake $(MLX42_PATH) -B $(MLX42_PATH)/build && make -C $(MLX42_PATH)/build -j4

obj/%.o: src/%.c
	mkdir -p obj
	$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)

clean:
	$(RM) obj
	make -C $(LIBFT_PATH) clean
	make -C $(MLX42_PATH)/build clean

fclean:
	$(RM) obj $(NAME)
	make -C $(LIBFT_PATH) fclean
	$(RM) $(MLX42_PATH)/build

re: fclean all

.PHONY: all clean fclean re

