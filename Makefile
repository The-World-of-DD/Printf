# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dierojas < dierojas@student.42madrid.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/08 20:30:26 by dierojas          #+#    #+#              #
#    Updated: 2025/03/26 21:53:08 by dierojas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ftprintf.a
SOURCES = ft_printf.c ft_strlen.c ft_put_basics.c 
OBJS = $(SOURCES:.c=.o)
CC = gcc
CCFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) -r $@ $?

%.o: %.c
	$(CC) -c $(CCFLAGS) $?

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
