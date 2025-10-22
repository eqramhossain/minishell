/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures_def.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:10:35 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/22 20:50:40 by ehossain         ###   ########.fr       */
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

# define PROMPT "➜ minishell:~"
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
	char			*current;
	int				error;
	int				i;
	int				len_end;
	int				sq_trigger;
	int				dq_trigger;
	int				r_in;
	int				r_out;
	int				r_app;
	int				r_here;
	int				pipe_flag;
}					t_syntax;

/* ========================================================================== */
/*                          TOKENIZER STRUCTURE                               */
/* ========================================================================== */

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

typedef struct s_token
{
	char			*value;
	t_token_type	type;
	struct s_token	*next;
}					t_token;

typedef struct s_tokenizer
{
	char			*input;
	char			curr_char;
	size_t			curr_pos;
	size_t			token_count;
	bool			inside_quotes;
	char			quote_type;
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

typedef struct s_redir
{
	int				type;
	char			*file;
	int				fd;
	struct s_redir	*next;
}					t_redir;

typedef struct s_cmd
{
	pid_t			pid;
	char			**argv;
	int				argc;
	t_redir			*redir;
	int				pipe_fd[2];
	struct s_cmd	*next;
}					t_cmd;

typedef struct s_parser
{
	t_cmd			*cmds;
	struct s_parser	*next;
}					t_parser;

/* ========================================================================== */
/*                            MINISHELL STRUCTURE                             */
/* ========================================================================== */

typedef struct s_ms_data
{
	int exit_status;  // Last exit status
	int running;      // Shell running flag
	char *prompt;     //
	char *input;      // User input
	char **envp_arg;  // cpy of envp
	t_envp *envp;     // Envp list
	t_envp *envp_cp;  // Copy
	t_token *tokens;  // Token lists
	t_parser *parser; // Parser list
}					t_ms_data;

#endif
