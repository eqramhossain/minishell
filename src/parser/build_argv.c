/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 18:26:43 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/25 18:27:03 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	**build_argv(t_token **tokens)
{
	char	**argv;
	int		i;
	int		count;

	count = ft_count_args(*tokens);
	argv = (char **)malloc(sizeof(char *) * (count + 1));
	if (!argv)
		return (NULL);
	i = 0;
	while (*tokens && (*tokens)->type != TOKEN_PIPE
		&& (*tokens)->type != TOKEN_EOF)
	{
		if (ft_is_argument_token((*tokens)->type))
		{
			i = ft_add_merged_arg(argv, i, tokens);
			if (i == -1)
				return (ft_free_array(argv), NULL);
		}
		else if (ft_is_redir_token((*tokens)->type))
			ft_skip_redir_tokens(tokens);
		else
			*tokens = (*tokens)->next;
	}
	argv[i] = NULL;
	return (argv);
}
