# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcuevas- <lcuevas-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/16 10:18:18 by lcuevas-          #+#    #+#              #
#    Updated: 2024/09/25 10:58:44 by lcuevas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_bzero.c\
	ft_isalnum.c\
	ft_isalpha.c\
	ft_isascii.c\
	ft_isdigit.c\
	ft_isprint.c\
	ft_memcpy.c\
	ft_memmove.c\
	ft_memset.c\
	ft_strlcat.c\
	ft_strlcpy.c\
	ft_strlen.c\
	ft_tolower.c\
	ft_toupper.c\
	ft_strchr.c\
	ft_strrchr.c\
	ft_strncmp.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_strnstr.c\
	ft_atoi.c\
	ft_atoi_long.c\
	ft_atof.c\
	ft_abs.c\
	ft_calloc.c\
	ft_strdup.c\
	ft_substr.c\
	ft_strjoin.c\
	ft_strtrim.c\
	ft_split.c\
	ft_itoa.c\
	ft_strmapi.c\
	ft_striteri.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c\
	get_next_line.c\
	get_next_line_utils.c\
	ft_printf_char.c\
	ft_printf_numb.c\
	ft_printf.c\
	ft_lstnew_bonus.c\
	ft_lstadd_front_bonus.c\
	ft_lstsize_bonus.c\
	ft_lstlast_bonus.c\
	ft_lstadd_back_bonus.c\
	ft_lstdelone_bonus.c\
	ft_lstclear_bonus.c\
	ft_lstiter_bonus.c\
	ft_lstmap_bonus.c


OBJS = $(SRCS:.c=.o)

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
AR = ar -crs

all: $(NAME)

# pruedo crear los objetos de antemano y me ahorro la ristra de mensajes, pero si hay cualquier
# cambio se ejecuta TODO otra vez, se puede considerar relinks
# solo uqeremos ejecutar lo que se cambie, para eso la regla %.o: %.c
#.c.o:	$SRCS
#	$(CC) $(CFLAGS) -c $(SRCS)
#	@echo "creando objetos"

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "creando libreria"

# se supone que debería añadir algo así para las reglas de compilación pero al parecer está implícito en AR
#%.o: %.c
#	@$(CC) $(CFLAGS) -c $< -o $@
#	@echo "creando objeto"

clean:
	@$(RM) $(OBJS)
	@echo "limpiando objetos"

fclean:
	@$(RM) $(NAME) $(OBJS)
	@echo "limpieza profunda"

re: fclean all

.PHONY: re all clean fclean
