# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbahraou <sbahraou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/24 17:19:49 by sbahraou          #+#    #+#              #
#    Updated: 2022/02/25 01:09:40 by sbahraou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c print_ptr.c print_hexa.c print_uns.c

OBJS = $(SRCS:.c=.o)

CC = gcc

HEADER = ft_printf.h

CFLAGS = -Wall -Werror -Wextra


all : $(NAME)

$(NAME) : $(HEADER) $(OBJS)
	ar -rsc $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all 

.PHONY: all fclean clean re