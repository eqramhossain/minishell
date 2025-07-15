/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roussada <roussada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:41:22 by roussada          #+#    #+#             */
/*   Updated: 2025/07/15 13:46:06 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_add_token(t_lexer *lexer, int type, char *str, size_t len)
{
	t_token	*token;

	(void)len;
	if (lexer->token_count >= lexer->token_capacity)
	{
		lexer->token_capacity *= 2;
		lexer->tokens = ft_realloc(lexer->tokens, (lexer->token_capacity / 2)
				* sizeof(t_token *), lexer->token_capacity * sizeof(t_token *));
	}
	token = malloc(sizeof(t_token));
	token->type = type;
	token->text = ft_strdup(str);
	lexer->tokens[lexer->token_count++] = token;
}

void	ft_lex_operator(t_lexer *lexer)
{
	char	c;

	c = ft_advance(lexer);
	if (c == '|')
		ft_add_token(lexer, TOKEN_PIPE, "|", 1);
	else if (c == '>')
	{
		if (ft_peak(lexer) == '>')
		{
			ft_advance(lexer);
			ft_add_token(lexer, TOKEN_APPEND, ">>", 2);
		}
		else
			ft_add_token(lexer, TOKEN_TRUNK, ">", 1);
	}
	else if (c == '<')
	{
		if (ft_peak(lexer) == '<')
		{
			ft_advance(lexer);
			ft_add_token(lexer, TOKEN_HEREDOC, "<<", 2);
		}
		else
			ft_add_token(lexer, TOKEN_INPUT, "<", 1);
	}
}

void	ft_lex_quote(t_lexer *lexer)
{
	char		c;
	const char	*start;
	size_t		len;

	c = ft_advance(lexer);
	start = &lexer->input[lexer->pos];
	len = 0;
	while (ft_peak(lexer) != c && ft_peak(lexer) != '\0')
	{
		ft_advance(lexer);
		len++;
	}
	if (ft_peak(lexer) == c)
		ft_advance(lexer);
	else
	{
		ft_add_token(lexer, TOKEN_ERROR, (char *)start, len);
		return ;
	}
	ft_add_token(lexer, TOKEN_WORD, (char *)start, len);
}

void	ft_lex_word(t_lexer *lexer)
{
	char		c;
	const char	*start;
	size_t		len;

	start = &lexer->input[lexer->pos];
	len = 0;
	while (1)
	{
		c = ft_peak(lexer);
		if (c == '\0' || c == 32 || ft_check_operator(c) || c == '\''
			|| c == '"')
			break ;
		ft_advance(lexer);
		len++;
	}
	if (len > 0)
		ft_add_token(lexer, TOKEN_WORD, (char *)start, len);
}

void	ft_tokenisation(t_lexer *lexer)
{
	char	c;

	while (1)
	{
		ft_skip_whitespace(lexer);
		c = ft_peak(lexer);
		if (c == '\0')
			break ;
		else if (ft_check_operator(c))
		{
			ft_lex_operator(lexer);
		}
		else if (c == '\'' || c == '"')
		{
			ft_lex_quote(lexer);
		}
		else if (ft_isword(c))
		{
			ft_lex_word(lexer);
		}
		else
			ft_advance(lexer);
	}
	ft_add_token(lexer, TOKEN_EOF, "EOF", 3);
}
