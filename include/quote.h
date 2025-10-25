/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 13:01:29 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/25 13:01:39 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUOTE_H
# define QUOTE_H

# include "structures_def.h"

char	*ft_remove_quotes(char *str);
char	**ft_remove_quotes_array(char **arr);

int		ft_is_quote(char c);
char	ft_get_quote_state(char *str, int pos);
int		ft_find_closing_quote(char *str, int start);
size_t	ft_count_unquoted_len(char *str);

int		ft_check_quotes_closed(char *str);
int		ft_is_inside_quotes(char *str, int pos);
char	ft_get_quote_type(char *str, int pos);

#endif
