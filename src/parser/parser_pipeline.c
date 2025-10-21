/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_pipeline.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekram <ekram@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 18:14:16 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/21 18:26:09 by ekram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	ft_count_pipes(t_token *tokens)
{
	int	count;

	count = 0;
	while (tokens && tokens->type != TOKEN_EOF)
	{
		if (tokens->type == TOKEN_PIPE)
			count++;
		tokens = tokens->next;
	}
	return (count);
}
