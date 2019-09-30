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

SRC = ft_iscntrl.c ft_lstadd.c ft_memchr.c ft_putendl.c ft_strclr.c \
ft_strjoin.c ft_strnequ.c ft_tolower.c ft_isdigit.c ft_lstdel.c ft_memcmp.c \
ft_putendl_fd.c ft_strcmp.c ft_strlcat.c ft_strnew.c ft_toupper.c ft_atoi.c \
ft_islower.c ft_lstdelone.c  ft_memcpy.c ft_putnbr.c ft_strcpy.c ft_strlen.c \
ft_strnstr.c get_next_line.c ft_bzero.c ft_isnum.c ft_lstiter.c ft_memdel.c \
ft_putnbr_fd.c ft_strdel.c ft_strmap.c ft_strrchr.c ft_isalnum.c \
ft_isprint.c ft_lstmap.c ft_memmove.c ft_putstr.c ft_strdup.c ft_strmapi.c \
ft_strsplit.c ft_isalpha.c ft_isspace.c ft_lstnew.c ft_memset.c \
ft_putstr_fd.c ft_strequ.c ft_strncat.c ft_strstr.c ft_isascii.c ft_isupper.c \
ft_memalloc.c ft_putchar.c ft_strcat.c ft_striter.c ft_strncmp.c ft_strsub.c \
ft_isblank.c ft_itoa.c ft_memccpy.c ft_putchar_fd.c ft_strchr.c ft_striteri.c \
ft_strncpy.c ft_strtrim.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(OBJ) : %.o : %.c
	gcc -Wall -Wextra -Werror -c -Ilibft.h $< -o $@ 

$(NAME) : $(OBJ)
	ar rc $@ $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f libft.h.gch

re: fclean all
