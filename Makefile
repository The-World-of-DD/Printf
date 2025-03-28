# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dierojas < dierojas@student.42madrid.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/08 20:30:26 by dierojas          #+#    #+#              #
#    Updated: 2025/03/28 09:34:30 by dierojas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SOURCES = ft_printf.c ft_printf_utils.c ft_printf_aux.c
OBJS = $(SOURCES:.c=.o)
CC = gcc
CCFLAGS = -Wall -Werror -Wextra
AR = ar

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) rcs $@ $^

%.o: %.c
	$(CC) -c $(CCFLAGS) $< -o $@

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
