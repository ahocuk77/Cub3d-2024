/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocuk <ahocuk@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:58:52 by ahocuk            #+#    #+#             */
/*   Updated: 2024/05/03 20:00:43 by ahocuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//addplayer in last while

int	vertical_space_skip(t_game *game, int y)
{
	int	x;
	int	len;

	x = 0;
	len = ft_strlen(game->map.map[x]) - 1;
	if (y > len)
	{
		while (y > len && x < game->map.height)
		{
			x++;
			len = ft_strlen(game->map.map[x]) - 1;
		}
	}
	while (x < game->map.height && game->map.map[x][y] == ' ')
		x++;
	if (x == game->map.height)
		return (-2);
	while (game->map.map[x][y] != '1' && game->map.map[x][y] != '0')
	{
		x++;
		x = len_checker(game, x, y);
	}
	return (x);
}

int	horizontal_length(char **map, int x)
{
	int	length;

	length = 0;
	while (map[x][length] != '\0' && map[x][length] != '\n' )
		length++;
	return (length);
}

int	handle_newline(t_game *game, int *x, int y)
{
	int	tmp;

	tmp = *x;
	while (*x >= 0 && (game->map.map[*x][y] == '\n'
		|| game->map.map[*x][y] == '\0'))
		(*x)--;
	if (game->map.map[*x][y] == '1')
	{
		*x = tmp;
		while (*x < game->map.height && game->map.map[*x][y] != '1'
			&& game->map.map[*x][y] != '0')
			(*x)++;
	}
	else
		return (-1);
	return (*x);
}

int	vertical_validate(t_game *game, int x, int y)
{
	while (x < game->map.height && game->map.map[x][y] != ' ')
	{
		x++;
		if (x >= game->map.height)
			return (x);
		x = len_checker2(game, x, y);
		if (x >= game->map.height || x == -1)
			return (x);
		if (game->map.map[x][y] == '\n' || game->map.map[x][y] == '\0')
			if (handle_newline(game, &x, y) == -1)
				return (-1);
		if (x < game->map.height && game->map.map[x][y] == ' ')
		{
			if (game->map.map[x - 1][y] != '1')
				return (-1);
			else
			{
				while (x < game->map.height - 1 && game->map.map[x][y] == ' ')
					x = len_checker(game, x + 1, y);
				if (x < game->map.height - 1 && game->map.map[x][y] != '1')
					return (-1);
			}
		}
	}
	return (x);
}

int	vertical_check(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.width)
	{
		x = vertical_space_skip(game, y);
		if (x == -2)
		{
			y++;
			continue ;
		}
		game->map.len_width = horizontal_length(game->map.map, x);
		if (game->map.map[x][y] != '1')
			return (-1);
		while (x < game->map.height -1)
		{
			if (vertical_validate(game, x, y) == -1)
				return (-1);
			else
				x = vertical_validate(game, x, y);
		}
		y++;
	}
	return (0);
}
