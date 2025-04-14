# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dierojas < dierojas@student.42madrid.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/08 20:30:26 by dierojas          #+#    #+#              #
#    Updated: 2025/04/12 00:06:16 by dierojas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SOURCES = ft_printf.c ft_printf_utils.c ft_printf_aux.c
OBJS = $(SOURCES:.c=.o)
CC = cc
CCFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C libft
	mkdir -p tmp_objs
	cd tmp_objs && ar x ../libft/libft.a
	ar rcs $@ $^ tmp_objs/*.o
	rm -rf tmp_objs

%.o: %.c
	$(CC) -c $(CCFLAGS) $< -o $@

clean:
	$(MAKE) -C libft clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
