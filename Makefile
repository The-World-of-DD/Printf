# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dierojas < dierojas@student.42madrid.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/08 20:30:26 by dierojas          #+#    #+#              #
#    Updated: 2025/04/11 17:47:01 by dierojas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SOURCES = ft_printf.c ft_printf_utils.c ft_printf_aux.c
OBJS = $(SOURCES:.c=.o)
CC = cc
CCFLAGS = -Wall -Werror -Wextra
AR = ar
LIBFT_SDIR = libft

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_SDIR)
	$(AR) rcs $@ $^ libft/libft.a

%.o: %.c
	$(CC) -c $(CCFLAGS) $< -o $@

clean: 
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_SDIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_SDIR) fclean

re: fclean all

.PHONY : all clean fclean re
