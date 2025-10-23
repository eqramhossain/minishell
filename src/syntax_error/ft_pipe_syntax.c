/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_syntax.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:40:02 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/23 11:40:03 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax.h"

/*
** Handles pipe '|' syntax checking (MANDATORY ONLY)
**
** Error cases we detect:
** 1. Pipe at the beginning: "| echo hello"
** 2. Pipe at the end: "echo hello |"
** 3. Double pipe: "echo hello || world" (this is logical OR in bonus)
** 4. Pipe after redirection without filename: "cat < |"
** 5. Consecutive pipes: "echo | | cat"
**
** How it works:
** - When we see a pipe, we set pipe_flag = 1
** - We check if there's another pipe right after (error: ||)
** - We check if we're at the end of line (error: | at end)
** - We check if there's an active redirection flag (error: no filename)
** - If pipe is at position 0, it's an error (| at start)
**
** Returns: 1 if error detected, 0 if valid
*/
int	ft_pipe_syntax(t_syntax **syntax)
{
	t_syntax	*synt;

	synt = *syntax;
	if (synt->current[synt->i] != '|')
		return (0);
	if (synt->current[synt->i + 1] && synt->current[synt->i + 1] == '|')
	{
		synt->error = 6;
		return (1);
	}
	if (synt->r_in || synt->r_here || synt->r_out || synt->r_app
		|| synt->pipe_flag)
	{
		synt->error = 6;
		return (1);
	}
	if (synt->i == 0 || synt->i == synt->len_end)
	{
		synt->error = 6;
		return (1);
	}
	synt->pipe_flag = 1;
	return (0);
}
