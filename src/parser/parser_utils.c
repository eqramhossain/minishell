/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekram <ekram@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 13:30:00 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/21 18:26:08 by ekram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
** Remove quotes from a string in-place
** 
** Handles both single and double quotes
** Modifies the string directly by shifting characters
** 
** Example: "hello" -> hello
**          'world' -> world
**          "it's" -> it's
*/
void	ft_remove_quotes_inplace(char *str)
{
	char	quote;
	int		i;
	int		j;

	if (!str)
		return ;
	i = 0;
	j = 0;
	quote = 0;
	while (str[i])
	{
		if ((str[i] == '\'' || str[i] == '\"') && !quote)
		{
			quote = str[i];
			i++;
			continue ;
		}
		if (str[i] == quote)
		{
			quote = 0;
			i++;
			continue ;
		}
		str[j++] = str[i++];
	}
	str[j] = '\0';
}

/*
** Expand environment variables in a word
** 
** This is a simplified version. You'll need to implement the full logic:
** - Find $ followed by variable name
** - Look up variable in env list
** - Replace $VAR with its value
** - Handle $? for exit status
** - Handle quotes (no expansion in single quotes)
** 
** For now, this is a placeholder that returns a copy of the word
** You should implement this based on your environment functions
*/
char	*ft_expand_variables(char *word, t_envp *env)
{
	char	*result;

	(void)env;
	if (!word)
		return (NULL);
	result = ft_strdup(word);
	return (result);
}
