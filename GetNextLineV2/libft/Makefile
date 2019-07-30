# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iet-tibi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/16 21:56:44 by iet-tibi          #+#    #+#              #
#    Updated: 2018/10/25 18:01:06 by iet-tibi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = *.c

all : $(NAME)

$(NAME) :
	gcc -Wall -Wextra -Werror libft.h -c *.c
	ar rc $(NAME) *.o

clean:
	rm -f *.o

fclean: clean
	rm -f libft.a

re: fclean all
