/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:00:34 by ahocuk            #+#    #+#             */
/*   Updated: 2024/05/03 20:25:32 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_cubcheck(char *map)
{
	int	len;

	len = ft_strlen(map);
	if (map[len - 1] != 'b' || map[len - 2] != 'u'
		|| map[len - 3] != 'c' || map[len - 4] != '.')
		return (1);
	else
		return (0);
}

void	map_w(t_game *game, int fd)
{
	char	*str;
	int		tmp;

	str = new_line_checker(game, fd);
	game->map.width = ft_strlen(str);
	free(str);
	while (1)
	{
		str = get_next_line(fd);
		game->map.new_line_checker = false;
		if (str == NULL)
			break ;
		tmp = ft_strlen2(str);
		if (game->map.width < tmp)
			game->map.width = ft_strlen2(str);
		free(str);
	}
	free(str);
}

void	parser(t_game *game, int fd)
{
	p_texture(game, fd);
	if (game->wall.texture_check == 1)
	{
		close(fd);
		return ;
	}
	p_color(game, fd);
	if (game->color.color_check == 1)
	{
		close(fd);
		return ;
	}
	p_map(game, fd);
	if (game->map.map_check == 1)
	{
		close(fd);
		return ;
	}
	close(fd);
	map_check(game);
}
