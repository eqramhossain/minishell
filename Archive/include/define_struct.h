/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:46:02 by ehossain          #+#    #+#             */
/*   Updated: 2025/07/30 19:28:37 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stddef.h>

# define PROMPT "➜ ehro@minishell:~"
# define RESET "\001\033[0m\002"
# define RED "\001\033[31m\002"
# define GREEN "\001\033[32m\002"
# define BLUE "\001\033[34m\002"

# define TOKEN_WORD 0    // "TEXT"
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
	int type;             // INPUT (<), OUTPUT (>), APPEND (>>), HEREDOC (<<)
	char *file;           // Where is the data going/coming from?
	struct s_redir *next; // Multiple redirections? Chain them!
}	t_redir;

typedef struct s_ast
{
	char *type;          // "command" or "pipe"
	char **argv;         // The actual command and argument
	t_redir *redirs;     // All the redirections for this command
	struct s_ast *left;  // Left side of a pipe
	struct s_ast *right; // Right side of a pipe
}	t_ast;

typedef struct s_token
{
	int type;   // What KIND of word is this?
	char *text; // What does it actually say?
}	t_token;

typedef struct s_parser
{
	t_token **tokens;   // all tokens form lexer part
	size_t pos;         //
	size_t token_count; // token_count in lexer part
}	t_parser;

typedef struct s_lexer
{
	const char *input;     // input collected from readline
	size_t pos;            //
	t_token **tokens;      // all the token collected from input
	size_t token_count;    // how many token have been found including EOF
	size_t token_capacity; // token_capacity = 64
							// when reach the token_capacity increase the token_capacity
							// and realloc new memory for tokens
}	t_lexer;

typedef struct s_all_parsing
{
	t_lexer *lexer;   // struct lexer
	t_parser *parser; // struct parset
	t_ast *ast;       // struct ast
	char *prompt;     // prompt
}	t_all_parsing;

/* ========================================================================== */
/* ================================== END  ================================== */
/* ========================================================================== */

#endif
