/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 10:57:51 by marvin            #+#    #+#             */
/*   Updated: 2021/06/03 10:57:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif


int     get_next_line(int fd, char **line);
char    *ft_substr(char const *s, unsigned int start, size_t len);
void    gnl_free(char **save);
size_t  ft_strlen(const char *s);
char    *ft_strdup(const char *s1);
char    *ft_strjoin(char const *s1, char const *s2);

#endif
