/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_check2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocuk <ahocuk@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:47:42 by ahocuk            #+#    #+#             */
/*   Updated: 2024/03/21 14:40:45 by ahocuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int vertical_space_skip(t_game *game, int y) // dikey yap 
{
	int x;

	x = 0;
	if(game->map.map[x][y] == ' ')
	{
		while(game->map.map[x][y] == ' ')
			x++;
	}
	printf("x EXIT %d\n", x);
	printf("y EXIT %d\n", y);
	return (x);
}
int horizontal_length(char **map, int x) {
    int length = 0;
    while (map[x][length] != '\0') {
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
int vertical_validate(t_game *game, int x, int y, int len)
{
	
	while(game->map.map[x][y] != ' ' && x < len)
		x++;
	if(x >= len)
	{
		if(game->map.map[x][y] != '1')
		{
			while(game->map.map[x][y] == ' ')
				x--;
		}
		if(game->map.map[x][y] == '1')
				return -2;
		return -1;
	}
	// if(game->map.map[x][y] != ' ' || game->map.map[x - 1][y] != '1')// check again
	// 	return -1;
	while(game->map.map[x][y] == ' ' && x <= len)
		x++;
	if(game->map.map[x][y] != '1' && game->map.map[x][y] != '\0' && game->map.map[x][y] != '\n')
	{
		if (x == len)
		{
			while(game->map.map[x][y] != '1')
				x--;
			if(game->map.map[x][y] == '1')
			{
				while(x <= len)
				{
					x++;
					if(game->map.map[x][y] == '0')
						return -1;
				}
				return x;
			}
			else
				return -1;
		}
		else
			return -1;
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
		game->leng = horizontal_length(game->map.map, x);
		if(game->map.map[x][y] != '1')
			return -1;
		game->len = vertical_length(game->map.map, y);
		while(x <= game->len)
		{
			if (vertical_validate(game, x, y, game->len) == -1)
				return -1;
			else if (vertical_validate(game, x, y, game->len) == -2)
				break;
			else
				x = vertical_validate(game, x, y, game->len);
		}
		y++;
	}
	return 0;
}