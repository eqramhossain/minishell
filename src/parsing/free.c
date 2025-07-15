/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roussada <roussada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:41:04 by roussada          #+#    #+#             */
/*   Updated: 2025/07/15 13:41:59 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_lexer(t_lexer *lexer)
{
	size_t	i;

	i = 0;
	if (!lexer)
		return ;
	while (i < lexer->token_count)
	{
		free(lexer->tokens[i]->text);
		free(lexer->tokens[i]);
		i++;
	}
	free(lexer->tokens);
	free(lexer);
}

void	ft_free_redir(t_redir *redir)
{
	t_redir	*tmp;

	while (redir)
	{
		tmp = redir;
		redir = redir->next;
		free(tmp);
	}
}

void	ft_free_ast(t_ast *ast)
{
	if (!ast)
		return ;
	if (ft_strcmp(ast->type, "pipe") == 0)
	{
		ft_free_ast(ast->left);
		ft_free_ast(ast->right);
	}
	else if (ft_strcmp(ast->type, "command") == 0)
	{
		free(ast->argv);
		ft_free_redir(ast->redirs);
	}
	free(ast);
}

void	ft_free_all(t_ast *ast, t_lexer *lexer, t_parser *parser)
{
	free(ast);
	free(parser);
	free(lexer);
}
