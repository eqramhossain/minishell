/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:28:18 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/23 11:28:21 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

/**
 * Handle input redirection: < file
 */
static int	handle_redir_input(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("minishell: ", STDERR);
		ft_putstr_fd(filename, STDERR);
		ft_putendl_fd(": No such file or directory", STDERR);
		return (ERROR);
	}
	dup2(fd, STDIN);
	close(fd);
	return (SUCCESS);
}

/**
 * Handle output redirection: > file
 */
static int	handle_redir_output(char *filename)
{
	int	fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		ft_putstr_fd("minishell: ", STDERR);
		ft_putstr_fd(filename, STDERR);
		ft_putendl_fd(": Permission denied", STDERR);
		return (ERROR);
	}
	dup2(fd, STDOUT);
	close(fd);
	return (SUCCESS);
}

/**
 * Handle append redirection: >> file
 */
static int	handle_redir_append(char *filename)
{
	int	fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd < 0)
	{
		ft_putstr_fd("minishell: ", STDERR);
		ft_putstr_fd(filename, STDERR);
		ft_putendl_fd(": Permission denied", STDERR);
		return (ERROR);
	}
	dup2(fd, STDOUT);
	close(fd);
	return (SUCCESS);
}

/**
 * Handle heredoc: << delimiter
 * NOTE: Heredoc should be processed during parsing!
 * This is a simplified version for reference
 */
static int	handle_heredoc(char *delimiter)
{
	int		pipe_fd[2];
	char	*line;

	if (pipe(pipe_fd) < 0)
		return (ERROR);
	while (1)
	{
		line = readline("> ");
		if (!line || ft_strcmp(line, delimiter) == 0)
		{
			free(line);
			break ;
		}
		write(pipe_fd[1], line, ft_strlen(line));
		write(pipe_fd[1], "\n", 1);
		free(line);
	}
	close(pipe_fd[1]);
	dup2(pipe_fd[0], STDIN);
	close(pipe_fd[0]);
	return (SUCCESS);
}

int	ft_apply_redirections(t_redir *redir_list)
{
	t_redir	*current;

	current = redir_list;
	while (current)
	{
		if (current->type == TOKEN_REDIR_IN)
		{
			if (handle_redir_input(current->file) == ERROR)
				return (ERROR);
		}
		else if (current->type == TOKEN_REDIR_OUT)
		{
			if (handle_redir_output(current->file) == ERROR)
				return (ERROR);
		}
		else if (current->type == TOKEN_APPEND)
		{
			if (handle_redir_append(current->file) == ERROR)
				return (ERROR);
		}
		else if (current->type == TOKEN_HEREDOC)
		{
			if (handle_heredoc(current->file) == ERROR)
				return (ERROR);
		}
		current = current->next;
	}
	return (SUCCESS);
}
