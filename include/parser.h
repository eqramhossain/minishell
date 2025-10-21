/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekram <ekram@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 13:15:38 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/21 18:26:08 by ekram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "structures_def.h"

t_parser	*ft_parser(t_token *tokens);
t_cmd		*ft_parse_command(t_token **tokens);
t_redir		*ft_parse_redirections(t_token **tokens);
void		ft_add_command(t_cmd **list, t_cmd *new);
void		ft_add_redir(t_redir **list, t_redir *new);

int			ft_count_pipes(t_token *token);
char		*ft_expand_variables(char *word, t_envp *env);
void		ft_remove_quotes_inplace(char *str);

void		ft_free_parser(t_parser *parser);
void		ft_free_cmd(t_cmd *cmd);
void		ft_free_redir(t_redir *redir);

void		ft_print_parser(t_parser *parser);

#endif
