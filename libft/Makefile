# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmorais- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/01 09:33:38 by lmorais-          #+#    #+#              #
#    Updated: 2023/12/01 09:33:54 by lmorais-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -I../includes
RM = rm -rf
NAME = libft.a
OBJ_DIR = obj

SRCS = 	ft_print_s.c\
		ft_putstr_fd.c\
		ft_split.c\
		ft_strjoin.c\
		ft_strlen.c\
		ft_strncmp.c\
		ft_strnstr.c
	
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

all: $(OBJ_DIR) $(OBJ_DIR)/$(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	
$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	$(RM) $(OBJ_DIR) 
fclean: clean
	$(RM) $(NAME)
	
re: fclean all

.PHONY: all clean fclean re










