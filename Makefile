# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/21 19:35:52 by hahmed            #+#    #+#              #
#    Updated: 2018/06/07 05:52:36 by hahmed           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

INC = -I ft_ls.h \
	  -I libft/include/

SRC = main.c error.c sort.c display_list.c listify_dir.c display_long.c \
	  width.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	make -C libft/
	$(CC) $(CFLAGS) $(INC) -c $(SRC)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L libft/ -lft

clean:
	make clean -C libft/
	$(RM) $(OBJ)

fclean: clean
	make fclean -C libft/
	$(RM) $(NAME)

re: fclean all
