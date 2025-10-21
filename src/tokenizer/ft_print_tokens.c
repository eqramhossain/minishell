/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tokens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekram <ekram@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 22:35:10 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/20 23:00:02 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

static const char	*ft_token_type_to_string(t_token_type type)
{
	switch (type)
	{
	case TOKEN_WORD:
		return ("WORD");
	case TOKEN_PIPE:
		return ("PIPE");
	case TOKEN_REDIR_IN:
		return ("REDIR_IN");
	case TOKEN_REDIR_OUT:
		return ("REDIR_OUT");
	case TOKEN_APPEND:
		return ("APPEND");
	case TOKEN_HEREDOC:
		return ("HEREDOC");
	case TOKEN_SINGLE_QUOTE:
		return ("SINGLE_QUOTE");
	case TOKEN_DOUBLE_QUOTE:
		return ("DOUBLE_QUOTE");
	case TOKEN_EOF:
		return ("EOF");
	case TOKEN_ERROR:
		return ("ERROR");
	default:
		return ("UNKNOWN");
	}
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
		printf("[token %zu] type=%s, value=\"%s\"\n", i, type_str, val);
		head = head->next;
		i++;
	}
}
