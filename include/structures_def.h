/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures_def.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:10:35 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/22 17:06:29 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_DEF_H
# define STRUCTURES_DEF_H

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define SUCCESS 0
# define ERROR 1

# define TRUE 1
# define FALSE 0

# define SPACE 32
# define TAB 9
# define BACKSLASH 92
# define SEMICOLON 59
# define DOUBLE_QUOTE 34 // "..."
# define SINGLE_QUOTE 39 // '...'
# define REDIR_IN 60     // <
# define REDIR_OUT 62    // >
# define PIPE 124        // |

# define PROMPT "➜ ehro@minishell:~"
# define RESET "\001\033[0m\002"
# define RED "\001\033[31m\002"
# define GREEN "\001\033[32m\002"
# define BLUE "\001\033[34m\002"

# include "../libft/include/ft_printf.h"
# include "../libft/include/get_next_line.h"
# include "../libft/include/libft.h"
# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <time.h>
# include <unistd.h>

/* ========================================================================== */
/*                            SYNTAX STRUCTURE                                */
/* ========================================================================== */

typedef struct s_syntax
{
	char *current; // The trimmed input string we're checking
	int error;     // Error code (0 = no error, >0 = error detected)
	int i;         // Current position in the string (iterator)
	int len_end;   // Index of last character (length - 1)

	// QUOTE TRACKING
	int sq_trigger; // 1 = inside single quotes, 0 = outside
	int dq_trigger; // 1 = inside double quotes, 0 = outside

	// REDIRECTION STATE FLAGS (track if we just saw a redir operator)
	int r_in;   // 1 = '<' redirection just encountered
	int r_out;  // 1 = '>' redirection just encountered
	int r_app;  // 1 = '>>' append redirection just encountered
	int r_here; // 1 = '<<' heredoc just encountered

	// PIPE STATE FLAG
	int pipe_flag; // 1 = '|' pipe just encountered, waiting for command
}					t_syntax;

/* ========================================================================== */
/*                          TOKENIZER STRUCTURE                               */
/* ========================================================================== */

/*
 * Token types
 */
typedef enum e_token_type
{
	TOKEN_WORD,         // regular word
	TOKEN_PIPE,         // |
	TOKEN_REDIR_IN,     // <
	TOKEN_REDIR_OUT,    // >
	TOKEN_APPEND,       // >>
	TOKEN_HEREDOC,      // <<
	TOKEN_SINGLE_QUOTE, // '...'
	TOKEN_DOUBLE_QUOTE, // "..."
	TOKEN_EOF,          // EOF
	TOKEN_ERROR,        // unknown char
}					t_token_type;

/*
 * Token structure - represents a single token
 */
typedef struct s_token
{
	char *value;          // the string/charactar containing the value
	t_token_type type;    // what type of token
	struct s_token *next; // pointer to the next token in the list
}					t_token;

/*
 * Tokenizer state - tracks position and state during tokenization
 */
typedef struct s_tokenizer
{
	char *input;        /* Input string to tokenize */
	char curr_char;     /* Current character being processed */
	size_t curr_pos;    /* Current position in input */
	size_t token_count; /* Count of tokens created */
	bool inside_quotes; /* Flag to track quote state */
	char quote_type;    /* ' or " if inside quotes */
}					t_tokenizer;

/* ========================================================================== */
/*								ENVIRONMENT STRUCTURE                         */
/* ========================================================================== */

typedef struct s_envp
{
	char			*key;
	char			*value;
	struct s_envp	*next;
}					t_envp;

/* ========================================================================== */
/*                           PARSER STRUCTURE                                 */
/* ========================================================================== */

// redirection node (for <, >, >>, <<)
typedef struct s_redir
{
	int type;   // one of TOKEN_REDIR_* or TOKEN_HEREDOC
	char *file; // filename or limiter for heredoc
	int				fd;
	struct s_redir	*next;
}					t_redir;

// command node
typedef struct s_cmd
{
	char **argv;        // arguments, like {"echo", "hello", NULL}
	t_redir *redir;     // linked list of redirections
	struct s_cmd *next; // next command in pipeline
}					t_cmd;

// the parsed structure (for entire line)
typedef struct s_parser
{
	t_cmd *cmds; // list of commands separated by pipes
	struct s_parser	*next;
}					t_parser;

/* ========================================================================== */
/*                            COMMAND STRUCTURE                               */
/* ========================================================================== */

/*
 * Redirection types - defines how I/O should be handled
 */
typedef enum e_redir_type
{
	REDIR_NONE,    // No redirection
	REDIR_INPUT,   // < file
	REDIR_OUTPUT,  // > file
	REDIR_APPEND,  // >> file
	REDIR_HEREDOC, // << delimiter
}					t_redir_type;

/*
 * Command structure - represents a single command in the pipeline
 */
typedef struct s_command
{
	char **argv;            // NULL-terminated argument
	int argc;               // Number of arguments (for convenience)
	t_redir *redirs;        // Linked list of redirections
	int pipe_fd[2];         // Pipe file descriptors for this command
	pid_t pid;              // Process ID when executed
	struct s_command *next; // Next command in pipeline
}					t_command;

/* ========================================================================== */
/*                            MINISHELL STRUCTURE                             */
/* ========================================================================== */

typedef struct s_ms_data
{
	int exit_status; // Last exit status
	int running;     // Shell running flag
	char			*prompt;
	char *input;         // User input
	char **envp_arg;     // cpy of envp
	t_envp *envp;        // Envp list
	t_envp *envp_cp;     // Copy
	t_token *tokens;     // Token lists
	t_parser *parser;    // Parser list
	t_command *commands; // Command list

}					t_ms_data;

#endif
