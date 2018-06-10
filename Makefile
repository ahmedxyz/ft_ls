# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/21 19:35:52 by hahmed            #+#    #+#              #
#    Updated: 2018/06/09 12:13:00 by hahmed           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

INC = -I ft_ls.h \
	  -I libft/include/

SRC = main.c				\
	  parse_options.c		\
	  listify_args.c		\
	  sort_list.c			\
	  split_list.c			\
	  display_list.c		\
	  display_directory.c	\
	  set_width1.c			\
	  set_width2.c			\
	  display_long1.c		\
	  display_long2.c		\
	  display_long3.c		\
	  display_columns.c		\
	  free.c				\
	  error.c

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
