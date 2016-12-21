NAME = fillit
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = 	fl_add_tetra.c		fl_get_height.c		fl_solve.c	\
		fl_free_slot.c		fl_isvalid.c		main.c		\
		fl_generate_map.c	fl_lstfunc.c
OBJ = $(SRC:.c=.o)

all: $(NAME)
	@echo "Done"

$(NAME): $(OBJ)
	$(CC) $(OBJ) libft.a

.o:
	$(CC) -c $(SRC) $(CFLAGS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf fillit

re: fclean all
	@echo "ReDone"
