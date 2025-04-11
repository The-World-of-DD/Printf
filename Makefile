# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dierojas < dierojas@student.42madrid.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/08 20:30:26 by dierojas          #+#    #+#              #
#    Updated: 2025/04/11 19:22:54 by dierojas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SOURCES = ft_printf.c ft_printf_utils.c ft_printf_aux.c
OBJS = $(SOURCES:.c=.o)
CC = cc
CCFLAGS = -Wall -Werror -Wextra
AR = ar
LIBFT = libft

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT)
	mkdir -p tmp_folder
	cd tmp_folder && $(AR) x ../$(LIBFT)/libft.a
	$(AR) rcs $@ $^ tmp_folder/*.o
	rm -rf tmp_folder

%.o: %.c
	$(CC) -c $(CCFLAGS) $< -o $@

clean: 
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT) fclean

re: fclean all

.PHONY : all clean fclean re
