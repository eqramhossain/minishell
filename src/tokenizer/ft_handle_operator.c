/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_operator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 18:41:51 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/20 20:28:24 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

static t_token	*ft_create_pipe(t_tokenizer *tokenizer);
static t_token	*ft_create_redir_in(t_tokenizer *tokenizer);
static t_token	*ft_create_redir_out(t_tokenizer *tokenizer);

t_token	*ft_handle_operator(t_tokenizer *tokenizer)
{
	if (tokenizer->curr_char == '|')
		return (ft_create_pipe(tokenizer));
	else if (tokenizer->curr_char == '<')
		return (ft_create_redir_in(tokenizer));
	else if (tokenizer->curr_char == '>')
		return (ft_create_redir_out(tokenizer));
	return (NULL);
}

static t_token	*ft_create_pipe(t_tokenizer *tokenizer)
{
	t_token	*token;

	token = ft_create_token("|", TOKEN_PIPE);
	ft_advance_tokenizer(tokenizer);
	return (token);
}

static t_token	*ft_create_redir_in(t_tokenizer *tokenizer)
{
	char	*value;

	value = "<";
	if (tokenizer->input[tokenizer->curr_pos + 1] == '<')
	{
		ft_advance_tokenizer(tokenizer);
		ft_advance_tokenizer(tokenizer);
		value = "<<";
		return (ft_create_token(value, TOKEN_HEREDOC));
	}
	else
	{
		ft_advance_tokenizer(tokenizer);
		return (ft_create_token(value, TOKEN_REDIR_IN));
	}
}

static t_token	*ft_create_redir_out(t_tokenizer *tokenizer)
{
	char	*value;

	value = ">";
	if (tokenizer->input[tokenizer->curr_pos + 1] == '>')
	{
		ft_advance_tokenizer(tokenizer);
		ft_advance_tokenizer(tokenizer);
		value = ">>";
		return (ft_create_token(value, TOKEN_APPEND));
	}
	else
	{
		ft_advance_tokenizer(tokenizer);
		return (ft_create_token(value, TOKEN_REDIR_OUT));
	}
}
