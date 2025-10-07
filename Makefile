# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/25 09:31:00 by ehossain          #+#    #+#              #
#    Updated: 2025/10/07 23:04:25 by ehossain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_MAIN = ./src/minishell.c \

ALL_SRC = $(SRC_MAIN) \

NAME = minishell
INCLUDE = ./include
LIBFT_DIR = ./libft
LIBFT = ./libft/libft.a
OBJ = ${ALL_SRC:.c=.o}
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
MAKE = make --no-print-directory

all : $(NAME)

$(NAME) : $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) -lreadline
	@echo "$(GREEN)minishell compiling...."
	@$(MAKE) loading
	@echo "$(END)"

$(LIBFT) :
	@$(MAKE) all -C $(LIBFT_DIR)

%.o : %.c 
	@$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

clean : 
	@$(MAKE) clean -C $(LIBFT_DIR)
	@rm -f $(OBJ)
	@echo "$(RED)removing minishlell object files...."
	@$(MAKE) loading
	@echo "$(END)"

fclean : 
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@rm -f $(OBJ) 
	@rm -f $(NAME)
	@echo "$(RED)removing minishlell object files & minishell...."
	@$(MAKE) loading
	@echo "$(END)"

re : fclean all

.PHONY = clean fclean re all loading

loading:
	@for i in $$(seq 1 30); do \
		sleep 0.01; \
		printf "\r[%-30s] %d%%" "$$(printf '#%.0s' $$(seq 1 $$i))" $$((i*100/30)); \
	done; \

# Define color variables
RED = \033[0;31m
GREEN = \033[0;32m
END = \033[0m

