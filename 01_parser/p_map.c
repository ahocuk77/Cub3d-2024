/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocuk <ahocuk@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:55:33 by ahocuk            #+#    #+#             */
/*   Updated: 2024/05/03 20:11:18 by ahocuk           ###   ########.fr       */
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

char	*ft_strcat(char *dst, const char *src)
{
	size_t	i;
	size_t	len_dst;

	i = 0;
	len_dst = ft_strlen(dst);
	while (src[i] != '\0')
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	return (dst);
}

char	*put_map_spaces(t_game *game, char *str)
{
	char	*temp_str;
	int		j;
	int		str_length;
	int		required_spaces;

	str_length = ft_strlen2(str);
	required_spaces = game->map.width - str_length;
	j = 0;
	if (required_spaces > 0)
	{
		temp_str = malloc(sizeof(char) * (game->map.width + 1));
		ft_strcpy(temp_str, str);
		while (j < required_spaces)
		{
			ft_strcat(temp_str, " ");
			j++;
		}
		free(str);
		str = temp_str;
	}
	return (str);
}

int	put_map(t_game *game, char *str, int line)
{
	int		result;
	char	**temp;
	int		i;

	result = m_valid_check(game, str);
	if (result == -1)
		return (-1);
	str = put_map_spaces(game, str);
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
