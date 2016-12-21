NAME = fillit
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = 	fl_add_tetra.c		fl_solve.c			ft_putstr.c \
		fl_free_slot.c		fl_isvalid.c		main.c		\
		fl_generate_map.c	fl_lstfunc.c		ft_func.c		ft_func2.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

.o:
	$(CC) -c $(SRC) $(CFLAGS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf fillit

re: fclean all
	@echo "ReDone"
