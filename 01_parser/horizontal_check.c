/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocuk <ahocuk@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:50:56 by ahocuk            #+#    #+#             */
/*   Updated: 2024/03/27 14:42:08 by ahocuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	horizontal_space_skip(t_game *game, int x)
{
	int	y;

	y = 0;
	if (game->map.map[x][y] == '\t' || game->map.map[x][y] == ' ')
	{
		while (game->map.map[x][y] == '\t' || game->map.map[x][y] == ' ')
			y++;
	}
	return (y);
}

int	handle_tab_case(t_game *game, int x, int y, int len)
{
	if (y >= len)
	{
		while (game->map.map[x][y] != '1')
			y--;
		if (game->map.map[x][y] == '1')
		{
			while (y <= len)
			{
				y++;
				if (game->map.map[x][y] == '0')
					return (-1);
			}
			return (y);
		}
		else
			return (-1);
	}
	else
		return (-1);
}

int	horizontal_validate(t_game *game, int x, int y, int len)
{
	while ((game->map.map[x][y] != ' ' && game->map.map[x][y] != '\t')
		&& y <= len)
		y++;
	if (y >= len)
	{
		if (game->map.map[x][y] != '1')
		{
			while (game->map.map[x][y] == ' ' || game->map.map[x][y] == '\n')
				y--;
		}
		if (game->map.map[x][y] == '1')
			return (-2);
		return (-1);
	}
	if (game->map.map[x][y] != ' ' || game->map.map[x][y - 1] != '1')
		return (-1);
	while (game->map.map[x][y] == ' ' && y <= len)
		y++;
	if (game->map.map[x][y] != '1')
		y = handle_tab_case(game, x, y, len);
	return (y);
}

int	horizontal_check(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x <= game->map.height - 1)
	{
		y = horizontal_space_skip(game, x);
		if (game->map.map[x][y] != '1')
			return (-1);
		game->map.len_width = ft_strlen(game->map.map[x]) - 2;
		while (y <= game->map.len_width)
		{
			if (horizontal_validate(game, x, y, game->map.len_width) == -1)
				return (-1);
			else if (horizontal_validate(game, x, y, game->map.len_width) == -2)
				break ;
			else
				y = horizontal_validate(game, x, y, game->map.len_width);
		}
		x++;
	}
	return (0);
}
