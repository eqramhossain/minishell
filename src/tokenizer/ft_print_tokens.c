/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tokens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:40:36 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/25 17:10:23 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

static const char	*ft_token_type_to_string(t_token_type type)
{
	if (type == TOKEN_WORD)
		return ("WORD");
	else if (type == TOKEN_PIPE)
		return ("PIPE");
	else if (type == TOKEN_REDIR_IN)
		return ("REDIR_IN");
	else if (type == TOKEN_REDIR_OUT)
		return ("REDIR_OUT");
	else if (type == TOKEN_APPEND)
		return ("APPEND");
	else if (type == TOKEN_HEREDOC)
		return ("HEREDOC");
	else if (type == TOKEN_SINGLE_QUOTE)
		return ("SINGLE_QUOTE");
	else if (type == TOKEN_DOUBLE_QUOTE)
		return ("DOUBLE_QUOTE");
	else if (type == TOKEN_EOF)
		return ("EOF");
	else if (type == TOKEN_ERROR)
		return ("ERROR");
	else
		return ("UNKNOWN");
}

void	ft_print_tokens(t_token *head)
{
	size_t		i;
	const char	*type_str;
	const char	*val;

	if (!head)
	{
		printf("[tokens] (no tokens)\n");
		return ;
	}
	i = 0;
	while (head)
	{
		type_str = ft_token_type_to_string(head->type);
		if (!type_str)
			type_str = "(null)";
		val = head->value;
		if (!val)
			val = "(null)";
		printf("[token %zu] type=%s, value=%s\n", i, type_str, val);
		head = head->next;
		i++;
	}
}
