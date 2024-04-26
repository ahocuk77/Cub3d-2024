/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocuk <ahocuk@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:55:33 by ahocuk            #+#    #+#             */
/*   Updated: 2024/03/27 14:47:45 by ahocuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	m_valid_check(t_game *game, char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\n')
	{
		printf("String: %s\n", "empty line");
		return (-1);
	}
	while (str[i] != '\n' && str[i] != '\0')
	{
		if (str[i] != '0' && str[i] != '1')
		{
			if (str[i] != 'N' && str[i] != 'S' && str[i] != 'E' && str[i] != 'W'
				&& str[i] != ' ')
				return (-1);
			if (str[i] != '\t' && str[i] != ' ')
			{
				if (game->map.player != '\0')
					return (-1);
				game->map.player = str[i];
			}
		}
		i++;
	}
	return (0);
}


char *ft_strcpy(char *dst, const char *src)
{
    size_t i = 0;

    while (src[i] != '\0') {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return dst;
}

char *ft_strcat(char *dst, const char *src) {
    size_t i = 0;
    size_t len_dst = strlen(dst);
    
    while (src[i] != '\0') {
        dst[len_dst + i] = src[i];
        i++;
    }
    dst[len_dst + i] = '\0';
    return dst;
}

int	put_map(t_game *game, char *str, int line)
{
	int		result;
	char	**temp;
	int		i;
	int		j;

	j = 0;
	result = m_valid_check(game, str);
	if (result == -1)
		return (-1);
	int str_length = strlen(str);
	int required_spaces = game->map.width - str_length;
	if (required_spaces > 0) {
		char *temp_str = malloc(sizeof(char) * (game->map.width + 1));
		ft_strcpy(temp_str, str);
		while(j < required_spaces)
		{
			ft_strcat(temp_str, " ");
			j++;
		}
		str = temp_str;
	}

	temp = game->map.map;
	game->map.map = malloc (sizeof(char *) * (line + 1));
	i = 0;
	while (temp && temp[i])
	{
		game->map.map[i] = temp[i];
		i++;
	}
	game->map.map[i] = str;
	game->map.map[i + 1] = NULL;
	free(temp);
	return (0);
}

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

void	p_map(t_game *game, int fd)
{
	char	*str;

	str = new_line_checker(game, fd);
	while (1)
	{
		if (game->map.new_line_checker != true)
			str = get_next_line(fd);
		game->map.new_line_checker = false;
		delete_slash_n(str);
		if (str == NULL)
			break ;
		game->map.height++;
		if (ft_strlen(str) != 0 && put_map(game, str, game->map.height) == -1)
		{
			game->map.map_check = 1;
			break ;
		}
	}
	if (game->map.player == '\0')
		game->map.map_check = 1;
}
