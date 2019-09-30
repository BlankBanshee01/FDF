NAME = fdf
LIBFT = libft/libft.a
SRC = draw_line.c drawing.c drawing_iso.c events.c freeing.c main.c reading.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(LIBFT) :
	make -C libft

$(OBJ) : %.o : %.c
	gcc -Wall -Wextra -Werror -c -Ifdf.h $< -o $@

$(NAME) : $(OBJ) $(LIBFT)
	gcc -Wall -Wextra -Werror $(OBJ) $(LIBFT) -framework OpenGL -framework Appkit -lmlx -o $(NAME)

clean:
	rm -f $(OBJ)
	make fclean -C libft

fclean: clean
	rm -f $(NAME)
	rm -f fdf.h.gch
	make fclean -C libft

re: fclean all
