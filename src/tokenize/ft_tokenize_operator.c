/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenize_operator.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:27:46 by ehossain          #+#    #+#             */
/*   Updated: 2025/08/04 17:49:29 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

static void	ft_tokenize_redir_in(t_token **token, t_var_token *var);
static void	ft_tokenize_redir_out(t_token **token, t_var_token *var);
static void	ft_tokenize_pipe(t_token **token, t_var_token *var);
static int	ft_check_next_char(t_var_token *var, char c);

void	ft_tokenize_operator(t_token **token, t_var_token *var)
{
	if (var->curr_char == PIPE)
	{
		ft_tokenize_pipe(token, var);
	}
	else if (var->curr_char == REDIR_IN)
	{
		ft_tokenize_redir_in(token, var);
	}
	else if (var->curr_char == REDIR_OUT)
	{
		ft_tokenize_redir_out(token, var);
	}
}

static void	ft_tokenize_pipe(t_token **token, t_var_token *var)
{
	if (*token == NULL)
	{
		*token = ft_new_token(&var->curr_char, TOKEN_PIPE, 1);
	}
	else if (*token)
	{
		ft_add_token(token, &var->curr_char, TOKEN_PIPE, 1);
	}
}

static void	ft_tokenize_redir_in(t_token **token, t_var_token *var)
{
	if (*token == NULL)
	{
		if (ft_check_next_char(var, REDIR_IN) == TRUE)
		{
		}
		else
		{
		}
	}
	else if (*token)
	{
		if (ft_check_next_char(var, REDIR_IN) == TRUE)
		{
		}
		else
		{
		}
	}
}

static void	ft_tokenize_redir_out(t_token **token, t_var_token *var)
{
	if (*token == NULL)
	{
		if (ft_check_next_char(var, REDIR_OUT) == TRUE) // means it is a HEREDOC
		{
		}
		else
		{
		}
	}
	else if (*token)
	{
		if (ft_check_next_char(var, REDIR_OUT) == TRUE) // means it is a APPEND
		{
		}
		else
		{
		}
	}
}

static int	ft_check_next_char(t_var_token *var, char c)
{
	if (var->input[var->curr_pos])
	{
		var->curr_pos++;
		if (var->input[var->curr_pos] != '\0' && var->input[var->curr_pos] == c)
		{
			return (1);
		}
	}
	return (0);
}
