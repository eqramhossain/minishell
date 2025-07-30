/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd_builtins.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 13:03:52 by ehossain          #+#    #+#             */
/*   Updated: 2025/07/28 17:34:56 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// void	ft_pwd_builtin(char *cmd, char **arg, char **envp)
// {
// 	char	*dir;
// 	int		i;
//
// 	(void)cmd;
// 	(void)envp;
// 	i = 0;
// 	while (arg[i])
// 		i++;
// 	if (i >= 2)
// 		return ;
// 	dir = NULL;
// 	dir = getcwd(NULL, 0);
// 	if (!dir)
// 		perror("getcwd");
// 	ft_putstr(dir);
// 	ft_putchar('\n');
// 	free(dir);
// }
