/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 17:31:52 by ehossain          #+#    #+#             */
/*   Updated: 2025/07/30 20:14:41 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXING_H
# define LEXING_H

# include "all_include.h"

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
	t_token_type	type;
	char			*value;
	struct s_token	*next;
}					t_token;

typedef struct s_lexing
{
	char			*input;
	char			curr_char;
	size_t			char_pos;
	size_t			token_count;
}					t_lexing;

t_lexing			*ft_lexing_init(char *input);

void				ft_inisialize_t_token(t_token *token);

#endif
