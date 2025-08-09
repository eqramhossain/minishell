# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekram <ekram@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/30 21:04:07 by ehossain          #+#    #+#              #
#    Updated: 2025/08/05 15:30:53 by ehossain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_MAIN = ./src/minishell.c \
		   ./src/ft_init_lex_ms_data.c \
		   ./src/ft_check_close_quote.c \

SRC_ENVP = ./src/envp/ft_envp_init.c \
		   ./src/envp/ft_free_t_envp.c \

SRC_TOKENIZE = ./src/tokenize/ft_tokenize_start.c \
			   ./src/tokenize/utils.c \
			   ./src/tokenize/ft_tokenize_operator.c \
			   ./src/tokenize/ft_add_token.c \
			   ./src/tokenize/ft_new_token.c \
			   ./src/tokenize/ft_insert_t_token.c \

SRC_PARSING = 

SRC_UTILS = ./src/utils/ft_prompt.c \
			./src/utils/ft_display_banner.c \
			./src/utils/ft_strjoin_free.c \
			./src/utils/ft_strldup.c \

SRC_SIGNALS = ./src/signals/ft_sigquit.c \
			  ./src/signals/ft_sigint.c \

SRC_SYNTAX = ./src/syntax_error/ft_ms_syntax_error.c \

ALL_SRC = $(SRC_MAIN) \
		  $(SRC_ENVP) \
		  $(SRC_FREE) \
		  $(SRC_TOKENIZE) \
		  $(SRC_PARSING) \
		  $(SRC_UTILS) \
		  $(SRC_SIGNALS) \
		  $(SRC_SYNTAX) \

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

