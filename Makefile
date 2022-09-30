# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/09 10:28:45 by ccariou           #+#    #+#              #
#    Updated: 2022/09/30 18:11:20 by ccariou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ccariou.filler 
HEAD = filler.h
# compile specs
FLAGS = -Werror -Wextra -Wall -g 
CC = gcc
LFT = -L ./libft/ -lft

# SOURCES FILES 
SRC_DIR = ./srcs/
SRCS = main.c get_info.c get_piece.c create_heat_map.c piece_position.c\

INC = -I ./includes
INC_LFT = -I ./libft/includes 

#OBJECTS
OBJ_DIR = ./object/
OBJ = $(addprefix $(OBJ_DIR), $(SRCS:%.c=%.o))

all: $(NAME) 

$(NAME): $(OBJ)
	 @ $(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LFT)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	 @make -C libft/
	 @ mkdir -p $(OBJ_DIR)
	 @ $(CC) $(FLAGS) $(INC_LIBFT) $(INC) -o $@ -c $<

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
