/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 23:22:00 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/21 10:51:45 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

t_token	*ft_tokenize(char *input)
{
	t_token		*tokens;
	t_token		*tmp;
	t_tokenizer	tokenizer;

	tokens = NULL;
	ft_init_tokenizer(&tokenizer, input);
	while (tokenizer.curr_char != '\0')
	{
		ft_skip_whitespaces(&tokenizer);
		if (tokenizer.curr_char == '\0')
			break ;
		if (ft_is_quote(tokenizer.curr_char))
			tmp = ft_handle_quotes(&tokenizer);
		else if (ft_is_operator_char(tokenizer.curr_char))
			tmp = ft_handle_operator(&tokenizer);
		else if (tokenizer.curr_char == '$')
			tmp = ft_handle_variable(&tokenizer);
		else
			tmp = ft_handle_word(&tokenizer);
		if (!tmp)
		{
			ft_free_tokens(tokens);
			return (NULL);
		}
		ft_add_token(&tokens, tmp);
	}
	return (tokens);
}

void	ft_init_tokenizer(t_tokenizer *tokenizer, char *input)
{
	tokenizer->input = input;
	if (input && *input)
		tokenizer->curr_char = input[0];
	else
		tokenizer->curr_char = 0;
	tokenizer->curr_pos = 0;
	tokenizer->token_count = 0;
	tokenizer->inside_quotes = FALSE;
	tokenizer->quote_type = 0;
}

void	ft_advance_tokenizer(t_tokenizer *tokenizer)
{
	if (tokenizer->curr_char != '\0')
	{
		tokenizer->curr_pos++;
		tokenizer->curr_char = tokenizer->input[tokenizer->curr_pos];
	}
}

void	ft_add_token(t_token **head, t_token *new_token)
{
	t_token	*current_token;

	if (!new_token)
		return ;
	if (*head == NULL)
	{
		*head = new_token;
		return ;
	}
	current_token = *head;
	while (current_token->next != NULL)
		current_token = current_token->next;
	current_token->next = new_token;
}
