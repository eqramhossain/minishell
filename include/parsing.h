/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 20:26:03 by ehossain          #+#    #+#             */
/*   Updated: 2025/08/04 13:14:01 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

typedef struct s_redirect
{
	int type;                // REDIRECT_IN, REDIRECT_OUT, APPEND, HEREDOC
	int fd;                  // File descriptor (filled during execution)
	char *filename;          // Where to redirect
	struct s_redirect *next; // Multiple redirections possible
}	t_redirect;

typedef struct s_simple_cmd
{
	int argc;              // Number of arguments
	char **argv;           // Command and arguments
	t_redirect *redirects; // All redirections for this command
}	t_simple_cmd;

typedef struct s_pipeline
{
	int cmd_count;          // Number of commands in pipeline
	int background;         // & at end (bonus)
	t_simple_cmd *commands; // Array of simple commands
}	t_pipeline;

// typedef struct s_parsing
// {
// 	char	c;
// }			t_parsing;

#endif
