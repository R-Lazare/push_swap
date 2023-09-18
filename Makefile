# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rluiz <rluiz@student.42lehavre.fr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/07 16:24:08 by rluiz             #+#    #+#              #
#    Updated: 2023/09/18 16:05:05 by rluiz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

name = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRC = main.c utils.c basefunc.c basefunc2.c basefunc3.c utils2.c

LIBFTSRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
       ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
       ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
       ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
       ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
       ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c \
       ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_striteri.c \
       arena.c arena_alloc.c ft_lstnew.c ft_lstsize.c \
	   ft_lstdelone.c ft_lstclear.c \
       ft_lstiter.c

SRC += $(addprefix libft/, $(LIBFTSRC))

OBJ = $(SRC:.c=.o)



all: $(name)

$(name): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) ft_printf/libftprintf.a -o $(name) && make clean

clean:
	rm -f $(OBJ)
	
fclean: clean
	rm -f $(name)

re: fclean all

.PHONY: all clean fclean re