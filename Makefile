
NAME = bsq
SRC = src/*.c
HEADERS = include
FLAGS = -Wall -Wextra -Werror

all: mkbsq

mkbsq:
	gcc $(SRC) -I$(HEADERS) $(FLAGS) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean mkbsq
