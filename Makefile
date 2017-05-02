#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/01 18:16:17 by yzakharc          #+#    #+#              #
#    Updated: 2017/05/02 18:49:09 by yzakharc         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRC = data_record.o ft_itoa_base.o ft_printf.o check_specifiers.o				\
		important_functions.o
LIBFT = ./libft/*.o

.PHONY: all libft

all: $(NAME)

$(NAME): libft $(SRC)
	ar rc $(NAME) $(SRC) $(LIBFT)
	ranlib $(NAME)

libft:
	make -C ./libft

%.o: %.c ft_printf.h
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	rm -f $(SRC)
	make clean -C ./libft

fclean: clean
	rm -f $(NAME) libft/libft.a
re: fclean all