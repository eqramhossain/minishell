/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 17:38:46 by ehossain          #+#    #+#             */
/*   Updated: 2025/07/23 18:50:13 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd_builtin(char *cmd, char **arg, char **envp)
{
	char	*dir;
	int		i;

	(void)cmd;
	(void)envp;
	i = 0;
	while (arg[i])
		i++;
	if (i >= 2)
		return ;
	dir = NULL;
	dir = getcwd(NULL, 0);
	if (!dir)
		perror("getcwd");
	ft_putstr(dir);
	ft_putchar('\n');
	free(dir);
}

// Don't forget to free the returned value form getcwd

/*int	main(int ac, char **av, char **envp)*/
/*{*/
/*	(void)ac;*/
/*	ft_pwd_builtin(av[1], &av[1], envp);*/
/*	return (0);*/
/*}*/
