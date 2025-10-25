/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekram <ekram@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 13:15:38 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/25 18:25:08 by ekram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "environment.h"
# include "structures_def.h"

t_parser	*ft_parser(t_token *tokens);
t_cmd		*ft_parse_command(t_token **tokens);
t_redir		*ft_parse_redirections(t_token **tokens);
void		ft_add_command(t_cmd **list, t_cmd *new);
void		ft_add_redir(t_redir **list, t_redir *new);

void		ft_free_parser(t_parser *parser);
void		ft_free_cmd(t_cmd *cmd);
void		ft_free_redir(t_redir *redir);

int			ft_is_argument_token(t_token_type type);
char		*ft_merge_adjacent_tokens(t_token **tokens);

int			ft_is_redir_token(t_token_type type);
t_redir		*ft_create_redir(int type, char *file);
int			ft_count_args(t_token *tokens);
void		ft_skip_redir_tokens(t_token **tokens);
int			ft_add_merged_arg(char **argv, int i, t_token **tokens);

void		ft_print_parser(t_parser *parser);

#endif
