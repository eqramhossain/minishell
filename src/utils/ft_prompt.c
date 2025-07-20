/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 14:39:50 by ehossain          #+#    #+#             */
/*   Updated: 2025/07/20 16:05:31 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_get_current_dir(void);

char	*ft_prompt(void)
{
	size_t	len_prompt;
	size_t	len_current_dir;
	size_t	len_color1;
	size_t	len_color2;
	size_t	len_reset;
	char	*current_dir;
	char	*prompt;

	len_prompt = ft_strlen(PROMPT);
	len_color1 = ft_strlen(GREEN);
	len_color2 = ft_strlen(BLUE);
	len_reset = ft_strlen(RESET);
	current_dir = ft_get_current_dir();
	len_current_dir = ft_strlen(current_dir);
	prompt = ft_calloc(sizeof(char), len_prompt + len_color1 + len_color2
			+ len_reset + len_reset + len_current_dir + 2);
	prompt = ft_strjoin(prompt, GREEN);
	prompt = ft_strjoin(prompt, PROMPT);
	prompt = ft_strjoin(prompt, RESET);
	prompt = ft_strjoin(prompt, BLUE);
	prompt = ft_strjoin(prompt, current_dir);
	prompt = ft_strjoin(prompt, RESET);
	prompt = ft_strjoin(prompt, "$ ");
	return (prompt);
}

static char	*ft_get_current_dir(void)
{
	char	*prompt;

	prompt = ft_calloc(sizeof(char), 1024);
	prompt = getcwd(prompt, 1024);
	return (prompt);
}
