/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekram <ekram@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:33:09 by gmarquis          #+#    #+#             */
/*   Updated: 2025/10/20 15:16:31 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYNTAX_H
# define SYNTAX_H

# include "structures_def.h"

// Main entry point - checks entire input for syntax errors
int	ft_ms_syntax_error(const char *input);

// Core checking functions
int	ft_check_reinit(t_syntax **syntax);
int	ft_quote_syntax(t_syntax **syntax);
int	ft_check_error_syntax(t_syntax **syntax);
int	ft_redir_syntax(t_syntax **syntax);
int	ft_pipe_syntax(t_syntax **syntax);

#endif /*SYNTAX_H*/
