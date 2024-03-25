	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocuk <ahocuk@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:58:52 by ahocuk            #+#    #+#             */
/*   Updated: 2024/03/21 21:15:56 by ahocuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int len_checker(t_game *game, int x, int y)
{
	int len;

	len = ft_strlen(game->map.map[x]) -1;
	if(y > len)
	{
		while(y > len && x < game->height)
		{
			x++;
			if(x < game->height)
				len = ft_strlen(game->map.map[x]) -1;
		}
	}
	return x;
}

int len_checker2(t_game *game, int x, int y)
{
	int len;

	len = ft_strlen(game->map.map[x]) -1;
	if(y > len)
	{
		if(game->map.map[x - 1][y] != '1')
			return -1;
		while(y > len && x < game->height)
		{
			x++;
			if(x < game->height)
				len = ft_strlen(game->map.map[x]) -1;
		}
	}
	return x;
}

int vertical_space_skip(t_game *game, int y) // dikey yap 
{
	int x;
	int len;
	x = 0;
	len = ft_strlen(game->map.map[x]) -1;
	if(y > len)
	{
		while(y > len && x < game->height)
		{
			x++;
			len = ft_strlen(game->map.map[x]) -1;
		}
	}
	while(game->map.map[x][y] != '1' && game->map.map[x][y] != '0') // add player 
	{
		x++;
		x = len_checker(game, x, y);
	}	
	return (x);
}

int horizontal_length(char **map, int x)
{
    int length = 0;
    while (map[x][length] != '\0' && map[x][length] != '\n' ) {
        length++;
    }
    return length;
}

int vertical_length(char **map, int y)
{
    int length = 0;
    while (map[length] != NULL && map[length][y] != '\0') {
        length++;
    }
	length--;
    return length;
}
int vertical_validate(t_game *game, int x, int y)
{
	int tmp;
	while(x < game->height && game->map.map[x][y] != ' ')
	{
		x++;
		if(x >= game->height)
			return x;
		x = len_checker2(game, x, y);
		if(x >= game->height || x == -1)
			return x;
		if(game->map.map[x][y] == '\n' || game->map.map[x][y] == '\0')
		{
			tmp = x;
			while(x >= 0 && (game->map.map[x][y] == '\n' || game->map.map[x][y] == '\0'))
				x--;
			if(game->map.map[x][y] == '1')
			{
				x = tmp;
				while(x < game->height && game->map.map[x][y] != '1' && game->map.map[x][y] != '0')
					x++;
			}
			else
				return -1;
		}
		if(x < game->height && game->map.map[x][y] == ' ')
		{
			if(game->map.map[x-1][y] != '1')
				return -1;
			else
			{
				while(x < game->height && game->map.map[x][y] == ' ')
				{
					x++;
					x = len_checker(game, x, y);
				}
				if(x < game->height && game->map.map[x][y] != '1')
					return -1;
			}
		}
	}
	return x;
}

int vertical_check(t_game *game)
{
	int x;
	int y;

	y = 0;
	while(y < game->width)
	{
		x = vertical_space_skip(game, y);
		game->len_width = horizontal_length(game->map.map, x);
		if(game->map.map[x][y] != '1')// check later 
			return -1;
		while(x < game->height)
		{
			if (vertical_validate(game, x, y) == -1)
				return -1;
			else
			{
				x = vertical_validate(game, x, y);
			}
		}
		y++;
	}
	return 0;
}
