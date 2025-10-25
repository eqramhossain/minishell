# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekram <ekram@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/25 09:31:00 by ehossain          #+#    #+#              #
#    Updated: 2025/10/25 15:33:26 by ehossain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_MAIN = ./src/minishell.c \

SRC_SIGNAL = ./src/signals/ft_sigint.c \
			 ./src/signals/ft_sigquit.c \
			 ./src/signals/ft_setup_signal.c \

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

SRC_PARSER = ./src/parser/parser.c \
			 ./src/parser/parser_command.c \
			 ./src/parser/parse_redirection.c \
			 ./src/parser/utils.c 

SRC_ENVIRONMENT = ./src/environment/get_environment.c \
				  ./src/environment/ft_free_t_envp.c \
				  ./src/environment/env_utils.c \
				  ./src/environment/expansion.c \
				  ./src/environment/expand_string.c \
				  ./src/environment/expansion_utils.c \

SRC_BUILTINS = ./src/builtins/pwd_builtin.c \
			   ./src/builtins/env_builtin.c \
			   ./src/builtins/echo_builtin.c \
			   ./src/builtins/cd_builtin.c \
			   ./src/builtins/export_builtin.c \
			   ./src/builtins/unset_builtin.c \
			   ./src/builtins/exit_builtin.c 

SRC_EXECUTOR = ./src/executor/executor.c \
			   ./src/executor/executor_builtins.c \
			   ./src/executor/single_command.c \
			   ./src/executor/external_command.c \
			   ./src/executor/pipeline.c \
			   ./src/executor/redirections.c \
			   ./src/executor/path_finder.c \

SRC_QUOTE = ./src/quote/process_quote.c \
			./src/quote/quote.c \
			./src/quote/quote_check.c \
			./src/quote/quote_utils.c \
			./src/quote/filter_empty.c 

SRC_UTILS = ./src/utils/ft_prompt.c \
			./src/utils/ft_free.c \
			./src/utils/ft_strjoin_free.c \
			./src/utils/ft_strldup.c \
			./src/utils/ft_strcmp.c \
			./src/utils/ft_putendl.c \
			./src/utils/ft_edge.c \

ALL_SRC = $(SRC_MAIN) \
		  $(SRC_SIGNAL) \
		  $(SRC_SYNTAX_ERROR) \
		  $(SRC_TOKENS) \
		  $(SRC_PARSER) \
		  $(SRC_ENVIRONMENT) \
		  $(SRC_EXPANSION) \
		  $(SRC_BUILTINS) \
		  $(SRC_EXECUTOR) \
		  $(SRC_QUOTE) \
		  $(SRC_UTILS) \

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

