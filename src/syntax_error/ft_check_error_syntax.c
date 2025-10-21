/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error_syntax.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekram <ekram@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:12:29 by gmarquis          #+#    #+#             */
/*   Updated: 2025/10/18 15:18:31 by ekram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax.h"

/*
** This file handles the final error reporting after syntax checking is complete
** 
** WHY THIS APPROACH?
** During parsing, we detect errors and set error codes (error = 1, 2, 3, etc.)
** At the end, we print the appropriate error message based on what we found
** 
** Error codes (mandatory):
** 1 = newline (redirection/pipe at end with no argument)
** 2 = '<'  (consecutive input redirections)
** 3 = '<<' (consecutive heredoc)
** 4 = '>'  (consecutive output redirections)
** 5 = '>>' (consecutive append redirections)
** 6 = '|'  (pipe errors: at start, at end, double pipe)
*/ 

/*
** Print the specific error token based on error code
** Matches bash's error message format exactly
*/
static void	st_print_error_token(int error)
{
	if (error == 1)
		ft_putstr_fd("`newline'\n", 2);
	else if (error == 2)
		ft_putstr_fd("`<'\n", 2);
	else if (error == 3)
		ft_putstr_fd("`<<'\n", 2);
	else if (error == 4)
		ft_putstr_fd("`>'\n", 2);
	else if (error == 5)
		ft_putstr_fd("`>>'\n", 2);
	else if (error == 6)
		ft_putstr_fd("`|'\n", 2);
}

/*
** Final error check and message printer
** 
** Called after we've scanned the entire input string
** Checks if any errors were detected during scanning:
** - Operator/redirection errors (error > 0)
** - Unclosed quotes (sq_trigger or dq_trigger still set to 1)
** 
** If errors found, prints bash-style error message and returns 1
** 
** Returns: 0 if no errors, 1 if errors detected
*/
int	ft_check_error_syntax(t_syntax **syntax)
{
	t_syntax	*synt;

	synt = *syntax;
	if (synt->sq_trigger || synt->dq_trigger || synt->error > 0)
	{
		ft_putstr_fd("minishell: syntax error near unexpected token ", 2);
		if (synt->error > 0)
			st_print_error_token(synt->error);
		else if (synt->sq_trigger == 1)
			ft_putstr_fd("`\''\n", 2);
		else if (synt->dq_trigger == 1)
			ft_putstr_fd("`\"'\n", 2);
		return (1);
	}
	return (0);
}
