/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:45:41 by ehossain          #+#    #+#             */
/*   Updated: 2025/07/20 14:45:19 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "include.h"

void		ft_display_banner(void);
char		*ft_prompt(void);

/* ========================================================================== */
/* ================================ PARSING ================================= */
/* ========================================================================== */

/* ============================== UTILS PARSING ============================= */
int			ft_isword(char c);
char		ft_peak(t_lexer *lexer);
void		ft_skip_whitespace(t_lexer *lexer);
int			ft_check_operator(char c);
void		*ft_realloc(void *ptr, size_t old_size, size_t new_size);
int			ft_strcmp(const char *s1, const char *s2);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		ft_print_token(t_lexer *lexer);
char		ft_advance(t_lexer *lexer);
void		ft_strerror(char *str);
/* ========================================================================== */

/* =============================== TOKENISATION ============================= */
t_lexer		*ft_lexing(char *str, t_lexer *lexer);
void		ft_tokenisation(t_lexer *lexer);
void		ft_lex_word(t_lexer *lexer);
void		ft_lex_quote(t_lexer *lexer);
void		ft_lex_operator(t_lexer *lexer);
void		ft_add_token(t_lexer *lexer, int type, char *str, size_t len);
/* ========================================================================== */

/* ================================ PARSER ================================== */
t_parser	*ft_parser_init(t_lexer *lexer);
t_ast		*ft_parse_pipeline(t_parser *parser);
t_ast		*ft_parse_command(t_parser *parser);
void		ft_parser_expect(t_parser *parser, int type);
int			ft_parser_match(t_parser *parser, int type);
t_token		*ft_parser_current(t_parser *parser);
void		ft_print_ast_recursive(t_ast *ast, int indent, const char *prefix);
void		ft_print_redirs(t_redir *r, int indent);
/* ========================================================================== */

/* ================================== FREE ================================== */
void		ft_free_all(t_ast *ast, t_lexer *lexer, t_parser *parser);
/* ========================================================================== */

/* ========================================================================== */
/* ================================== END  ================================== */
/* ========================================================================== */

/* ========================================================================== */
/* =============================== EXECUTION ================================ */
/* ========================================================================== */

/* ========================================================================== */
/* ================================== END  ================================== */
/* ========================================================================== */
#endif
