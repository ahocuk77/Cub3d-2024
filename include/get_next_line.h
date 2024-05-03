/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocuk <ahocuk@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 19:48:54 by musenov           #+#    #+#             */
/*   Updated: 2024/05/03 16:30:57 by ahocuk           ###   ########.fr       */
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


char	*get_next_line(int fd);

#endif

