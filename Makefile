CC=gcc
CFLAGS=-Wall -Wextra -Werror
NAME=checker
SRC= $(wildcard src/*.c)
OBJ= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $@ $^

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re