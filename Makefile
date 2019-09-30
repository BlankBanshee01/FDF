NAME = fdf

SRC = *.c

all : $(NAME)

$(NAME) :
	gcc -Wall -Wextra -Werror *.c libft/libft.a -framework OpenGL -framework Appkit -lmlx -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all
