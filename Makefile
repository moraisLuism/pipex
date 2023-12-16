# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmorais- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/15 08:43:20 by lmorais-          #+#    #+#              #
#    Updated: 2023/12/15 08:43:24 by lmorais-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIBFT_PATH = libft/
LIBFT_LIB = $(LIBFT_PATH)libft.a
INCLUDE = -I./includes
RM = rm -rf
VPATH = srcs

SRCS = 	ft_error.c\
		ft_exec.c\
		ft_path.c\
		ft_process_1.c\
		ft_process_2.c\
		pipex.c
		
OBJ_DIR = obj
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ_DIR)  $(OBJS)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) -o $(NAME)

$(OBJ_DIR):
	mkdir -p obj

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJ_DIR)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)
	
re: fclean all

.PHONY: all clean fclean re