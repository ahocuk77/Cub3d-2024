/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocuk <ahocuk@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 20:10:33 by ahocuk            #+#    #+#             */
/*   Updated: 2024/05/03 20:11:24 by ahocuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*new_line_checker(t_game *game, int fd)
{
	char	*str;

	str = get_next_line(fd);
	if (str[0] == '\n')
	{
		while (str[0] == '\n')
		{
			free(str);
			str = get_next_line(fd);
		}
		game->map.new_line_checker = true;
	}
	return (str);
}

void	delete_slash_n(char *str)
{
	char	*current_line;
	int		i;

	current_line = str;
	i = 0;
	while (current_line && current_line[i])
	{
		if (current_line[i] == '\n')
			current_line[i] = '\0';
		i++;
	}
}

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
