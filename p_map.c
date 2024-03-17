/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocuk <ahocuk@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:55:33 by ahocuk            #+#    #+#             */
/*   Updated: 2024/03/17 18:32:58 by ahocuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <string.h>
int	m_valid_check(t_game *game, char *str)
{
	int i;

	i = 0;

	if(str[0] == '\n')
	{
		printf("String: %s\n", "empty line");
		return -1;
	}
	while(str[i] != '\n' && str[i] != '\0')
	{
		if(str[i] != '0' && str[i] != '1')
		{
			if(str[i] != 'N' && str[i] != 'S' && str[i] != 'E' && str[i] != 'W'
				&& str[i] != '\t' && str[i] != ' ')
				return -1;
			if(str[i] != '\t' && str[i] != ' ')
			{
				if(game->map.player != '\0')
					return -1;
				game->map.player = str[i];
			}
		}
		i++;
	}
	return 0;
}

int put_map(t_game *game, char *str, int line)
{
	int result;
	char **temp;
	int lastsize;
	// line = line + 0;

	result = m_valid_check(game, str);
	if(result == -1)
		return -1;
	lastsize = game->map.size;
	game->map.size = ft_strlen(str) + game->map.size;
	temp = malloc(sizeof(char *) * game->map.size);
	memcpy(temp, game->map.map, sizeof(char *) * lastsize);
	temp[line] = strdup(str);
	free(game->map.map);
	game->map.map = temp;
	return 0;
}

char	*new_line_checker(t_game *game, int fd)
{
	char *str;

	str = get_next_line(fd);
	if(str[0] == '\n')
	{
		while(str[0] == '\n')
		{
			free(str);
			str = get_next_line(fd);
			printf("fd: %d\n", fd);
		}
		game->new_line_checker = true;
		printf("Start: %s\n", str);
	}
	return (str);

}

void	p_map(t_game *game, int fd)
{
	char *str;
	int line;

	str = new_line_checker(game, fd);
	line = 0;
	printf("Start2: %s\n", str);
	while(1)
	{
		if(game->new_line_checker != true)
			str = get_next_line(fd);
		game->new_line_checker = false;
		str = trimreplace(str, "\0\n");
		if(str == NULL)
			break ;
		if (ft_strlen(str) != 0 && put_map(game, str, line) == -1)
		{
			printf("String: %s\n", "put map error");
			game->map_check = 1;
			free(str);
			break ;
		}
		free(str);
		line++;
	}
}
