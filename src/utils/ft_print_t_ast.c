/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_t_ast.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 13:09:30 by ehossain          #+#    #+#             */
/*   Updated: 2025/07/27 15:56:26 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

// static t_ast	*ft_t_ast_init(void);
// static void		ft_print_argv(char **argv);
// static void		ft_print_t_ast_left(t_ast *ast);
// static void		ft_print_t_ast_right(t_ast *ast);
//
// t_ast	*ft_print_t_ast(t_ast *org_ast)
// {
// 	t_ast	*ast;
//
// 	ast = ft_t_ast_init();
// 	ast = org_ast;
// 	printf("ast->type = %s\n", ast->type);
// 	if (ast->argv)
// 		ft_print_argv(ast->argv);
// 	else
// 	{
// 		ft_print_t_ast_left(ast);
// 		ft_print_t_ast_right(ast);
// 	}
// 	exit(EXIT_FAILURE);
// 	return (ast);
// }
//
// static t_ast	*ft_t_ast_init(void)
// {
// 	t_ast	*new_ast;
//
// 	new_ast = malloc(sizeof(t_ast));
// 	new_ast->type = NULL;
// 	new_ast->argv = NULL;
// 	new_ast->left = NULL;
// 	new_ast->right = NULL;
// 	new_ast->redirs = NULL;
// 	return (new_ast);
// }
//
// static void	ft_print_argv(char **argv)
// {
// 	int	i;
//
// 	i = 0;
// 	while (argv[i])
// 	{
// 		printf("argv[i] = %s\n", argv[i]);
// 		i++;
// 	}
// }
//
// static void	ft_print_t_ast_left(t_ast *old_ast)
// {
// 	t_ast	*ast;
//
// 	ast = ft_t_ast_init();
// 	ast = old_ast;
// 	printf("ast->type = %s\n", ast->type);
// 	if (ast->argv)
// 		ft_print_argv(ast->argv);
// }
//
// static void	ft_print_t_ast_right(t_ast *old_ast)
// {
// 	t_ast	*ast;
//
// 	ast = ft_t_ast_init();
// 	ast = old_ast;
// 	printf("ast->type = %s\n", ast->type);
// 	if (ast->argv)
// 		ft_print_argv(ast->argv);
// }
