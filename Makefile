# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekram <ekram@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/25 09:31:00 by ehossain          #+#    #+#              #
#    Updated: 2025/10/20 22:42:09 by ehossain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_MAIN = ./src/minishell.c \

SRC_SYNTAX_ERROR = ./src/syntax_error/ft_check_error_syntax.c \
				   ./src/syntax_error/ft_check_reinit_syntax.c \
				   ./src/syntax_error/ft_ms_syntax_error.c \
				   ./src/syntax_error/ft_quote_syntax.c \
				   ./src/syntax_error/ft_redir_syntax.c \
				   ./src/syntax_error/ft_pipe_syntax.c \

SRC_TOKENS =./src/tokenizer/ft_handle_operator.c \
			./src/tokenizer/ft_handle_quote.c \
			./src/tokenizer/ft_handle_variable.c \
			./src/tokenizer/ft_handle_word.c \
			./src/tokenizer/ft_print_tokens.c \
			./src/tokenizer/ft_token_checks.c \
			./src/tokenizer/ft_token_utils.c \
			./src/tokenizer/tokenize.c

SRC_UTILS = ./src/utils/ft_prompt.c \
			./src/utils/ft_free.c \
			./src/utils/ft_strjoin_free.c \
			./src/utils/ft_strldup.c \

ALL_SRC = $(SRC_MAIN) \
		  $(SRC_UTILS) \
		  $(SRC_SYNTAX_ERROR) \
		  $(SRC_TOKENS) \

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
		sleep 0.001; \
		printf "\r[%-30s] %d%%" "$$(printf '#%.0s' $$(seq 1 $$i))" $$((i*100/30)); \
	done; \

# Define color variables
RED = \033[0;31m
GREEN = \033[0;32m
END = \033[0m

