/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 17:31:52 by ehossain          #+#    #+#             */
/*   Updated: 2025/08/04 17:27:56 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZE_H
# define TOKENIZE_H

# include "all_include.h"
# include "utils.h"

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

typedef struct s_var_token
{
	char			*input;
	char			curr_char;
	size_t			curr_pos;
	size_t			token_count;
}					t_var_token;

t_token				*ft_start_tokenizer(char *input);
void				ft_add_token(t_token **token, char *value,
						t_token_type type, size_t len);
t_token				*ft_new_token(char *value, t_token_type type, size_t len);

void				ft_skip_whitespaces(t_var_token *var);
char				ft_get_curr_char(t_var_token *var);

int					ft_check_operator(t_var_token *var);
void				ft_tokenize_operator(t_token **token, t_var_token *var);

#endif
