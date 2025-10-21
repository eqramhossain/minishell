/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_reinit_syntax.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekram <ekram@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:18:39 by gmarquis          #+#    #+#             */
/*   Updated: 2025/10/21 13:03:05 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax.h"

/*
** This file manages the "state machine" - resetting flags when appropriate
**
** WHY DO WE NEED THIS?
** When checking syntax, we use flags to track if we just saw:
** - A redirection operator (< > << >>)
** - A pipe operator (|)
**
** We need to RESET these flags when we encounter actual content (filenames,
** commands, etc.) to avoid false positives.
**
** Example: "cat < file.txt"
** - We see '<', set r_in = 1
** - We see 'f' (start of filename), RESET r_in = 0
** - This tells us the redirection has a valid filename
*/

/*
** Check if character should reset redirection flags
** We reset when we hit actual content (not spaces, operators, or redirections)
**
** Returns: 1 if we should reset redirection flags, 0 otherwise
*/
static int	st_reinit_redir(char c)
{
	if (c != ' ' && c != '\t' && c != '|' && c != '<' && c != '>'
		&& ft_isascii(c))
		return (1);
	return (0);
}

/*
** Check if character should reset pipe flag
** We reset when we hit actual content (not spaces or pipes)
**
** Returns: 1 if we should reset pipe flag, 0 otherwise
*/
static int	st_reinit_pipe(char c)
{
	if (c != ' ' && c != '\t' && c != '|' && ft_isascii(c))
		return (1);
	return (0);
}

/*
** Main reinitialization function - manages state machine
**
** Called for each character during syntax checking
**
** What it does:
** 1. Resets redirection flags when we hit actual content (filename/command)
** 2. Resets pipe flag when we hit actual content (command after pipe)
** 3. Calls redirection and pipe checkers when we hit operators
**
** Returns: 1 if error detected, 0 if OK to continue
*/
int	ft_check_reinit(t_syntax **syntax)
{
	t_syntax	*synt;

	synt = *syntax;
	if (st_reinit_redir(synt->current[synt->i]))
	{
		synt->r_in = 0;
		synt->r_here = 0;
		synt->r_out = 0;
		synt->r_app = 0;
	}
	if (st_reinit_pipe(synt->current[synt->i]))
		synt->pipe_flag = 0;
	if (!synt->dq_trigger && !synt->sq_trigger)
	{
		if (synt->current[synt->i] == '<' || synt->current[synt->i] == '>')
		{
			if (ft_redir_syntax(&synt))
				return (1);
		}
		if (synt->current[synt->i] == '|')
		{
			if (ft_pipe_syntax(&synt))
				return (1);
		}
	}
	return (0);
}
