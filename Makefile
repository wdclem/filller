# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/09 10:28:45 by ccariou           #+#    #+#              #
#    Updated: 2022/09/09 12:34:36 by ccariou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ccariou.filler 
HEAD = filler.h
# compile specs
FLAGS = -g -Werror -Wextra -Wall
CC = gcc
LFT = -L ./libft/ -lft

# SOURCES FILES 
SRC_DIR = ./srcs/
SRCS = main.c\

INC = -I ./includes -I ./libft/includes

#OBJECTS
OBJ_DIR = ./object/
OBJ = $(addprefix $(SRC_DIR), $(SRCS))

all: $(NAME) 

$(NAME): $(OBJ)
	 @ $(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LFT)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	 @ mkdir -p $(OBJ_DIR)
	 @ $(CC) $(FLAGS) $(INC) -o $@ -c $<

lib:
	@ make -sC ./libft/ all
clean:
	@ rm -rf $(OBJ_DIR)
	@ make -C ./libft clean

fclean: clean
	@ rm -f $(NAME)
	@ make  -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re
