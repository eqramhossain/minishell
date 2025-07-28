/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 18:54:49 by ehossain          #+#    #+#             */
/*   Updated: 2025/07/23 20:50:23 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// to do
// when there is a "-option" error message and exit
void	ft_env_builtin(char *cmd, char **arg, char **envp)
{
	int		i;
	char	**my_envp;

	(void)cmd;
	(void)arg;
	i = 0;
	while (envp[i])
		i++;
	my_envp = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (envp[i])
	{
		my_envp[i] = ft_strdup(envp[i]);
		i++;
	}
	my_envp[i] = NULL;
	i = 0;
	while (my_envp[i])
	{
		printf("%s\n", my_envp[i]);
		i++;
	}
	i = 0;
	while (my_envp[i])
	{
		free(my_envp[i]);
		i++;
	}
	free(my_envp);
}

/*int	main(int ac, char **av, char **envp)*/
/*{*/
/*	(void)ac;*/
/*	ft_env_builtin(av[0], av, envp);*/
/*	return (0);*/
/*}*/
