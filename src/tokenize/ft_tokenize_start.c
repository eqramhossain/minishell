/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenize_start.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 13:37:24 by ehossain          #+#    #+#             */
/*   Updated: 2025/08/04 16:48:30 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

static void	ft_var_init(t_var_token *var, char *input);
// static void	ft_token_init(t_token *token);

t_token	*ft_start_tokenizer(char *input)
{
	t_token		*token;
	t_var_token	var;

	// ft_token_init(&token);
	token = NULL;
	ft_var_init(&var, input);
	while (var.input[var.curr_pos])
	{
		ft_skip_whitespaces(&var);
		var.curr_char = ft_get_curr_char(&var);
		if (var.curr_char == '\0')
			break ;
		else if (ft_check_operator(&var) == TRUE)
		{
			ft_tokenize_operator(&token, &var);
		}
		var.curr_pos++;
	}
	return (NULL);
}

static void	ft_var_init(t_var_token *var, char *input)
{
	var->input = input;
	var->curr_pos = 0;
	var->curr_char = 0;
	var->token_count = 0;
}

// static void	ft_token_init(t_token *token)
// {
// 	token->value = NULL;
// 	token->type = 0;
// 	token->next = NULL;
// }
