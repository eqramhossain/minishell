/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_include.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <ehossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 18:47:07 by ehossain          #+#    #+#             */
/*   Updated: 2025/08/04 19:35:18 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALL_INCLUDE_H
# define ALL_INCLUDE_H

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define SUCCESS 0
# define FAILURE 1

# define TRUE 1
# define FALSE 0

# define SPACE 32
# define TAB 9
# define BACKSLASH 92
# define SEMICOLON 59

# define DOUBLE_QUOTE 34 // "..."
# define SINGLE_QUOTE 39 // '...'
# define REDIR_IN 60     // <
# define REDIR_OUT 62    // >
# define PIPE 124        // |

# include "../libft/include/get_next_line.h"
# include "../libft/include/libft.h"
# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <time.h>
# include <unistd.h>

#endif
