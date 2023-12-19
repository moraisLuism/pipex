# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmorais- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/15 08:43:20 by lmorais-          #+#    #+#              #
#    Updated: 2023/12/18 09:13:21 by lmorais-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
INCLUDES_DIR = includes
SRCS = 	srcs/pipex.c \
		srcs/ft_process_1.c \
		srcs/ft_process_2.c \
		srcs/ft_exec.c \
		srcs/ft_error.c \
		srcs/ft_path.c \
		srcs/libft/ft_split.c \
		srcs/libft/ft_strjoin.c \
		srcs/libft/ft_strlen.c \
		srcs/libft/ft_strncmp.c \
		srcs/libft/ft_strnstr.c
		
OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c $(INCLUDES_DIR)
	$(CC) $(CFLAGS) -I./$(INCLUDES_DIR) -c $< -o $@

clean:
	rm -rf  $(OBJ) 

fclean: clean
	rm -rf  $(NAME)

re: fclean all

.PHONY: all clean fclean re
