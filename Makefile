#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/01 18:16:17 by yzakharc          #+#    #+#              #
#    Updated: 2017/05/01 19:11:13 by yzakharc         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRC = data_record.c ft_itoa_base.c ft_printf.c check_specifiers.c
OBJECT = $(SRC:.c=.o)
LIBFT = ./libft/ft_strlen.o		\
		./libft/ft_strdup.o		\
		./libft/ft_strchr.o		\
		./libft/ft_atoi.o		\
		./libft/ft_isdigit.o	\
		./libft/ft_strnew.o		\
		./libft/ft_strdel.o		\
	 	./libft/ft_putchar.o	\
	 	./libft/ft_putstr.o		\

.PHONY: all $(NAME) clean fclean re

all: $(NAME)

$(NAME): libft.a $(OBJECT)
	ar rc $(NAME) $(OBJECT) $(LIBFT)
	ranlib $(NAME)

libft.a:
	make -C ./libft

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	rm -f $(OBJECT)
	make clean -C ./libft

fclean: clean
	rm -f $(NAME) libft/libft.a
re: fclean all