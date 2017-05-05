#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/01 18:16:17 by yzakharc          #+#    #+#              #
#    Updated: 2017/05/05 18:09:16 by yzakharc         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror
NAME	=	libftprintf.a
OBJ		=	data_record.o			\
			ft_itoa_base.o			\
			ft_printf.o				\
			check_specifiers.o		\
			important_functions.o	\
			ft_for_lib.o			\
			support_ft.o			\
			precision.o				\
			width.o					\

all: $(NAME)

$(NAME): $(OBJ)
	ar -cru $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: ./%.c ft_printf.h
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: clean all

norm:
	norminette *.c *.h