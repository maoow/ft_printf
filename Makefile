# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbinet <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/13 14:45:18 by cbinet            #+#    #+#              #
#    Updated: 2016/12/13 14:59:13 by cbinet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC= ft_printf.c srcs/*.c 

INCLUDES = libft.h

OBJ = *.o srcs/libft/*.o

all: $(NAME)

$(NAME):
	gcc -c $(SRC)
	make -C srcs/libft
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	make clean -C srcs/libft

fclean: clean
	rm -f $(NAME)
	make fclean -C srcs/libft

re: fclean all

