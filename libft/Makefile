# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/18 16:35:26 by hahmed            #+#    #+#              #
#    Updated: 2018/05/13 10:49:55 by hahmed           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

SRC_FILES = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
	  ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c \
	  ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
	  ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
	  ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	  ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c \
	  ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
	  ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
	  ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c \
	  ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c \
	  ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c \
	  ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_strndup.c ft_strnjoin.c \
	  ft_digits.c ft_digits_base.c ft_udigits_base.c ft_itoa_base.c \
	  ft_uitoa_base.c ft_wcharlen.c ft_putwchar.c ft_wstrlen.c ft_putwstr.c \
	  ft_max.c ft_min.c ft_putnchar.c ft_putnstr.c ft_putnwstr.c \
	  ft_lstaddback.c ft_lstrev.c ft_lstfree.c ft_lstsize.c ft_swap.c \
	  ft_swapptr.c ft_lstswap.c

FT_PRINTF_FILES = ft_printf.c parse.c cast_length.c string.c format.c \
				  print_d.c print_u.c print_o.c print_x.c print_p.c \
				  print_c.c print_wc.c print_s.c print_ws.c print_percent.c \
				  print_invalid.c print_with_padding.c

OBJ_FILES = $(SRC_FILES:.c=.o) $(FT_PRINTF_FILES:.c=.o)

SRC_DIR = src/

FT_PRINTF_DIR = src/ft_printf/

OBJ_DIR = obj/

INC = include/

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES)) \
	  $(addprefix $(FT_PRINTF_DIR), $(FT_PRINTF_FILES))

OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -c $(SRC) -I $(INC)
	mkdir -p $(OBJ_DIR)
	mv $(OBJ_FILES) $(OBJ_DIR)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all
