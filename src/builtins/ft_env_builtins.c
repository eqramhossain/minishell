/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_builtins.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 13:02:25 by ehossain          #+#    #+#             */
/*   Updated: 2025/07/28 13:02:38 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
