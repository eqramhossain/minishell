/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekram <ekram@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 13:01:29 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/25 14:24:11 by ekram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUOTE_H
# define QUOTE_H

# include "environment.h"
# include "structures_def.h"
# include "tokenizer.h"

int		ft_process_quotes_full(t_cmd *cmd_list);
int		ft_process_quotes_cmd(t_cmd *cmd);
int		ft_process_quotes_pipeline(t_cmd *cmd_list);
int		ft_process_quotes_redir(t_redir *redir);

char	*ft_remove_quotes(char *str);
char	**ft_remove_quotes_array(char **arr);

char	ft_get_quote_state(char *str, int pos);
int		ft_find_closing_quote(char *str, int start);
size_t	ft_count_unquoted_len(char *str);

int		ft_check_quotes_closed(char *str);
int		ft_is_inside_quotes(char *str, int pos);
char	ft_get_quote_type(char *str, int pos);

#endif
