NAME = fillit
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = *.c
OBJ = $(SRC:.c=.o)

all: $(NAME)
	
$(NAME): $(OBJ)
	ar rc libft.a $(OBJ)
.o:
	$(CC) -c $(SRC) $(CFLAGS)
clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf libft.a

re: fclean all
	@echo "Done"
