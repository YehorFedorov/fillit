#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efedorov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/16 16:11:08 by efedorov          #+#    #+#              #
#    Updated: 2017/01/19 13:04:29 by efedorov         ###   ########.fr        #
#                                                                              #
#******************************************************************************#
NAME = fillit

HEADER = fillit.h

SRC = ft_check.c \
		ft_coords.c \
		ft_file.c \
		ft_putchar.c \
		ft_putendl.c \
		ft_putstr.c \
		ft_size.c \
		ft_solve.c \
		ft_strcmp.c \
		ft_strdup.c \
		ft_strlen.c \
		ft_strncpy.c \
		ft_strndup.c \
		ft_strnew.c \
		ft_strrev.c \
		ft_strsplit.c \
		ft_strsub.c \
		ft_strtrim.c \
		ft_valid.c \
		main.c \

OBJ = ft_check.o \
        ft_coords.o \
        ft_file.o \
        ft_putchar.o \
        ft_putendl.o \
        ft_putstr.o \
        ft_size.o \
        ft_solve.o \
        ft_strcmp.o \
        ft_strdup.o \
        ft_strlen.o \
        ft_strncpy.o \
        ft_strndup.o \
        ft_strnew.o \
        ft_strrev.o \
        ft_strsplit.o \
        ft_strsub.o \
        ft_strtrim.o \
        ft_valid.o \
        main.o \

CC = gcc

CFLAGS = -c -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ)

%.o: %.c $(HEADER)
		$(CC) $(CFLAGS) -o $@ $<

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all
