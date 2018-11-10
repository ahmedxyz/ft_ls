# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/21 19:35:52 by hahmed            #+#    #+#              #
#    Updated: 2018/11/10 01:03:20 by hahmed           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

SRC_FILES = main.c				\
	  		parse_options.c		\
	  		args_to_list.c		\
	  		sort_list.c			\
	  		split_list.c		\
	  		display_list.c		\
	  		display_directory.c	\
	  		set_width1.c		\
	  		set_width2.c		\
	  		display_long1.c		\
	  		display_long2.c		\
	  		display_long3.c		\
	  		display_columns.c	\
	  		free.c				\
	  		error.c

OBJ_FILES = $(SRC_FILES:.c=.o)

SRC_DIR = src/

OBJ_DIR = obj/

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

INC = -I inc/ -I libft/inc/

all: $(NAME)

$(NAME):
	make -C libft/
	$(CC) $(CFLAGS) $(INC) -c $(SRC)
	mkdir -p $(OBJ_DIR)
	mv $(OBJ_FILES) $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L libft/ -lft

clean:
	make clean -C libft/
	$(RM) $(OBJ_DIR)

fclean: clean
	make fclean -C libft/
	$(RM) $(NAME)

re: fclean all
