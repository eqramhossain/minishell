# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/30 21:04:07 by ehossain          #+#    #+#              #
#    Updated: 2025/07/10 15:28:12 by ehossain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ./src/minishell.c \

NAME = minishell
INCLUDE = ./include
LIBFT_DIR = ./libft
LIBFT = ./libft/libft.a
OBJ = ${SRC:.c=.o}
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
MAKE = make --no-print-directory

all : $(NAME)

$(NAME) : $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)
	@echo "$(GREEN)minishell compiled$(END)"

$(LIBFT) :
	@$(MAKE) all -C $(LIBFT_DIR)

%.o : %.c 
	@$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

clean : 
	@$(MAKE) clean -C $(LIBFT_DIR)
	@rm -f $(OBJ)
	@echo "$(RED)minishell object files removed$(END)"


fclean : 
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@rm -f $(OBJ) 
	@rm -f $(NAME)
	@echo "$(RED)minishell object files removed$(END)"
	@echo "$(RED)minishell removed$(END)"

re : fclean all


.PHONY = clean fclean re all

# Define color variables
RED = \033[0;31m
GREEN = \033[0;32m
END = \033[0m
