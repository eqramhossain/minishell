/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 23:29:35 by ehossain          #+#    #+#             */
/*   Updated: 2025/10/20 22:51:28 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include "structures_def.h"
# include "utils.h"

/*
 * Main tokenization function - converts input string to token list
 * Returns the head of the token list or NULL on error
 */
t_token	*ft_tokenize(char *input);

/*
 * Helper functions for tokenization
 */
void	ft_init_tokenizer(t_tokenizer *tokenizer, char *input);
void	ft_advance_tokenizer(t_tokenizer *tokenizer);
void	ft_skip_whitespaces(t_tokenizer *tokenizer);
t_token	*ft_create_token(char *value, t_token_type type);
void	ft_free_tokens(t_token *tokens);

/*
 * Token recognition functions
 */
t_token	*ft_handle_word(t_tokenizer *tokenizer);
t_token	*ft_handle_operator(t_tokenizer *tokenizer);
t_token	*ft_handle_quotes(t_tokenizer *tokenizer);
t_token	*ft_handle_variable(t_tokenizer *tokenizer);
bool	ft_is_whitespace(char c);
bool	ft_is_operator_char(char c);
bool	ft_is_quote(char c);

/*
 * Token list functions
 */
void	ft_add_token(t_token **head, t_token *new_token);

void	ft_print_tokens(t_token *head);

#endif
