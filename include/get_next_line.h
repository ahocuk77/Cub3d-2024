/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 19:48:54 by musenov           #+#    #+#             */
/*   Updated: 2024/03/21 20:55:23 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*

# define BUFF_SIZE 0 -> this will not work as we have to 
first check if BUFF_SIZE was defined before, e.g. among 
others in compilatin flags:

gcc -Wall -Wextra -Werror -D BUFF_SIZE=42 bonus2.c

*/

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 41
# endif

# include "common.h"

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

size_t	ft_strlen(const char *str);
char	*ft_strnew(size_t size);
char	*ft_strchr(const char *s, int c);
// char	*ft_strdup(char *s1);
char	*ft_strjoin_gnl(char const *s1, char const *s2);

int		read_to_buf(char **left, char **line, char **p_n, int *fd);
char	*check_left(char **left, char **line, char **p_n);
char	*get_next_line(int fd);

#endif
