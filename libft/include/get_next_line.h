/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:13:42 by ehossain          #+#    #+#             */
/*   Updated: 2025/07/27 19:39:23 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
char	*ft_read_file(int fd, char *buffer);
char	*ft_set_line(char *buffer);
char	*ft_set_remaining(char *buffer);
void	ft_inisialize(int *i, int *j);

size_t	ft_strlen_gnl(const char *str);
char	*ft_strchr_gnl(const char *str, int i);
void	*ft_calloc_gnl(size_t nmemb, size_t size);
char	*ft_strjoin_gnl(char const *s1, char const *s2);
char	*ft_str_free_join_gnl(char *str1, char *str2);

#endif
