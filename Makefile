NAME = fillit
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = 	fl_add_tetra.c		fl_solve.c			ft_putstr.c			\
		fl_isvalid.c		main.c				fl_generate_map.c	\
		fl_lstfunc.c		ft_func.c			ft_func2.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

fl_add_tetra.o:
	$(CC) -c fl_add_tetra.c $(CFLAGS)

fl_solve.o: fl_add_tetra.c
	$(CC) -c fl_solve.c $(CFLAGS)

ft_putstr.o: ft_putstr.c
	$(CC) -c ft_putstr.c $(CFLAGS)

fl_isvalid.o: fl_isvalid.c
	$(CC) -c fl_isvalid.c $(CFLAGS)

main.o: main.c
	$(CC) -c main.c $(CFLAGS)

fl_generate_map.o: fl_generate_map.c
	$(CC) -c fl_generate_map.c $(CFLAGS)

fl_lstfunc.o: fl_lstfunc.c
	$(CC) -c fl_lstfunc.c $(CFLAGS)

ft_func.o: ft_func.c
	$(CC) -c ft_func.c $(CFLAGS)

ft_func2.o: ft_func2.c
	$(CC) -c ft_func2.c $(CFLAGS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf fillit

re: fclean all
