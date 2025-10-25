/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:30:34 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/25 15:29:19 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static int	is_numeric_string(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	count_args(char **args)
{
	int	count;

	count = 0;
	while (args[count])
		count++;
	return (count);
}

static void	exit_with_error(char *arg)
{
	ft_putstr_fd("minishell: exit: ", STDERR);
	ft_putstr_fd(arg, STDERR);
	ft_putendl_fd(": numeric argument required", STDERR);
	exit(2);
}

int	ft_exit(char **args, t_ms_data *ms_data)
{
	int			exit_code;
	int			arg_count;
	long long	temp;

	ft_putendl_fd("exit", STDOUT);
	arg_count = count_args(args);
	if (arg_count == 1)
		exit(ms_data->exit_status);
	if (!is_numeric_string(args[1]))
		exit_with_error(args[1]);
	if (arg_count > 2)
	{
		ft_putendl_fd("minishell: exit: too many arguments", STDERR);
		return (ERROR);
	}
	temp = ft_atoi(args[1]);
	exit_code = (unsigned char)temp;
	exit(exit_code);
	return (SUCCESS);
}
