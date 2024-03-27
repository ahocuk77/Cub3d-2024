/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocuk <ahocuk@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:00:34 by ahocuk            #+#    #+#             */
/*   Updated: 2024/03/27 15:40:43 by ahocuk           ###   ########.fr       */
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
