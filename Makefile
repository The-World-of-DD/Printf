# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dierojas < dierojas@student.42madrid.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/08 20:30:26 by dierojas          #+#    #+#              #
#    Updated: 2025/04/11 23:52:29 by dierojas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SOURCES = ft_printf.c ft_printf_utils.c ft_printf_aux.c
OBJS = $(SOURCES:.c=.o)
CC = cc
CCFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	cd libft && make $(MAKE)
	$(CC) $(CCFLAGS) $(OBJ) -L ./libft -lft -o $(NAME)

clean: 
	cd libft && $(MAKE) clean
	rm -f $(OBJS)

fclean: clean
	cd libft && $(MAKE) fclean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
