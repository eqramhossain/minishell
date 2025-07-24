/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 14:39:50 by ehossain          #+#    #+#             */
/*   Updated: 2025/07/24 22:26:41 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_first_part(void);
static char	*ft_second_part(void);

char	*ft_prompt(void)
{
	char	*first_part;
	char	*second_part;
	char	*prompt;

	first_part = ft_first_part();
	second_part = ft_second_part();
	second_part = ft_strjoin(second_part, "$> ");
	prompt = ft_strjoin(first_part, second_part);
	return (prompt);
}

static char	*ft_first_part(void)
{
	char	*prompt;
	char	*green;
	char	*reset;
	char	*all;

	prompt = ft_strdup(PROMPT);
	green = ft_strdup(GREEN);
	reset = ft_strdup(RESET);
	all = "";
	all = ft_strjoin(all, green);
	free(green);
	all = ft_strjoin_free(all, prompt);
	all = ft_strjoin_free(all, reset);
	return (all);
}

static char	*ft_second_part(void)
{
	char	*current_dir;
	char	*blue;
	char	*reset;
	char	*all;

	current_dir = NULL;
	current_dir = getcwd(NULL, 0);
	blue = ft_strdup(BLUE);
	reset = ft_strdup(RESET);
	all = "";
	all = ft_strjoin(all, blue);
	free(blue);
	all = ft_strjoin_free(all, current_dir);
	all = ft_strjoin_free(all, reset);
	return (all);
}
