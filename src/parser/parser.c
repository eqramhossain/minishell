/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:31:39 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/25 18:03:56 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_parser	*ft_parser(t_token *tokens)
{
	t_parser	*parser;
	t_cmd		*cmd;

	if (!tokens)
		return (NULL);
	parser = ft_calloc(1, sizeof(t_parser));
	if (!parser)
		return (NULL);
	parser->cmds = NULL;
	parser->next = NULL;
	while (tokens && tokens->type != TOKEN_EOF)
	{
		cmd = ft_parse_command(&tokens);
		if (!cmd)
			return (ft_free_parser(parser), NULL);
		ft_add_command(&parser->cmds, cmd);
		if (tokens && tokens->type == TOKEN_PIPE)
			tokens = tokens->next;
	}
	return (parser);
}

void	ft_add_command(t_cmd **list, t_cmd *new)
{
	t_cmd	*current;

	if (!list || !new)
		return ;
	if (!*list)
	{
		*list = new;
		return ;
	}
	current = *list;
	while (current->next)
		current = current->next;
	current->next = new;
}

void	ft_free_parser(t_parser *parser)
{
	t_parser	*temp;

	while (parser)
	{
		temp = parser;
		parser = parser->next;
		ft_free_cmd(temp->cmds);
		free(temp);
	}
}

void	ft_free_cmd(t_cmd *cmd)
{
	t_cmd	*temp;
	int		i;

	while (cmd)
	{
		temp = cmd;
		cmd = cmd->next;
		if (temp->argv)
		{
			i = 0;
			while (temp->argv[i])
			{
				free(temp->argv[i]);
				i++;
			}
			free(temp->argv);
		}
		ft_free_redir(temp->redir);
		free(temp);
	}
}

void	ft_free_redir(t_redir *redir)
{
	t_redir	*temp;

	while (redir)
	{
		temp = redir;
		redir = redir->next;
		if (temp->file)
			free(temp->file);
		free(temp);
	}
}

// void	ft_print_parser(t_parser *parser)
// {
// 	t_cmd	*cmd;
// 	t_redir	*redir;
// 	int		cmd_num;
// 	int		i;
//
// 	if (!parser)
// 		return ;
// 	cmd_num = 0;
// 	cmd = parser->cmds;
// 	while (cmd)
// 	{
// 		ft_printf("Command %d:\n", cmd_num++);
// 		if (cmd->argv)
// 		{
// 			ft_printf("  Args: ");
// 			i = 0;
// 			while (cmd->argv[i])
// 			{
// 				ft_printf("[%s] ", cmd->argv[i]);
// 				i++;
// 			}
// 			ft_printf("\n");
// 		}
// 		redir = cmd->redir;
// 		while (redir)
// 		{
// 			ft_printf("  Redir: type=%d file=%s\n", redir->type, redir->file);
// 			redir = redir->next;
// 		}
// 		cmd = cmd->next;
// 	}
// }
