# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecoelho- <ecoelho-@student.42>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/11 19:54:27 by ecoelho-          #+#    #+#              #
#    Updated: 2024/12/12 00:38:00 by ecoelho-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=philo

SRC_PATH=./src/

SRCS=main.c check_args.c init.c routines.c \
	threads.c monitor.c utils.c aux.c \

OBJ=$(addprefix $(SRC_PATH), $(SRCS:.c=.o))

CC=cc

CFLAGS=-Wall -Wextra -Werror -g3

all: $(NAME)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@
	ar -rcs $(NAME) $@

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

norm:
	@norminette -R CheckForbiddenSource
	@echo "NORMINETTE SUCESS"

re: fclean all

valgrind: re
	@valgrind --leak-check=full \
	--show-reachable=yes \
	--show-leak-kinds=all -s \
	--track-origins=yes \
	./$(NAME) 4 4 4 4


.PHONY:	all clean fclean re valgrind norm