/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:46:02 by ehossain          #+#    #+#             */
/*   Updated: 2025/07/22 17:32:06 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stddef.h>

# define PROMPT "➜ ehro@minishell:~"

# define RESET "\033[0m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"
# define BOLD "\033[1m"

# define TOKEN_WORD 0
# define TOKEN_PIPE 1    // |
# define TOKEN_INPUT 2   // <
# define TOKEN_TRUNK 3   // >
# define TOKEN_APPEND 4  // >>
# define TOKEN_HEREDOC 5 // <<
# define TOKEN_EOF 6     // EOF
# define TOKEN_ERROR 7

# define AST_COMMAND 10
# define AST_PIPE 20

/* ========================================================================== */
/* ================================ PARSING ================================= */
/* ========================================================================== */

typedef struct s_redir
{
	int				type;
	char			*file;
	struct s_redir	*next;
}					t_redir;

typedef struct s_ast
{
	char			*type;
	char			**argv;
	struct s_ast	*left;
	struct s_ast	*right;
	t_redir			*redirs;
}					t_ast;

typedef struct s_token
{
	int				type;
	char			*text;
}					t_token;

typedef struct s_parser
{
	t_token			**tokens;
	size_t			pos;
	size_t			token_count;
}					t_parser;

typedef struct s_lexer
{
	const char		*input;
	size_t			pos;
	t_token			**tokens;
	size_t			token_count;
	size_t			token_capacity;
}					t_lexer;

/* ========================================================================== */
/* ================================== END  ================================== */
/* ========================================================================== */

#endif
