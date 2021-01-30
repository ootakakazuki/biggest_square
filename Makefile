# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkuroish <kkuroish@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/24 16:19:33 by kkuroish          #+#    #+#              #
#    Updated: 2020/02/24 16:19:55 by kkuroish         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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