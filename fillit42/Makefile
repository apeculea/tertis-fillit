# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcincean <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/23 15:07:33 by vcincean          #+#    #+#              #
#    Updated: 2017/01/23 15:15:13 by vcincean         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = src/arrange.c src/main.c src/printer.c src/reader.c src/solver.c \
	src/solver_utils.c src/string_functions.c src/structures.c src/validator.c
OBJ = arrange.o main.o printer.o reader.o solver.o solver_utils.o \
	string_functions.o structures.o validator.o
INCLUDES = includes/

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = /bin/rm -f

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -c $(SRC) -I $(INCLUDES)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
