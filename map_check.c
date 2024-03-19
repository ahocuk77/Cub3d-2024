/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocuk <ahocuk@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 18:42:13 by ahocuk            #+#    #+#             */
/*   Updated: 2024/03/18 18:31:52 by ahocuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int space_skip(t_game *game, int x)
{
	int y;

	y = 0;
	if(game->map.map[x][y] == '\t' || game->map.map[x][y] == ' ')
	{
		while(game->map.map[x][y] == '\t' || game->map.map[x][y] == ' ')
			y++;
	}
	return (y);
}

int horizontal_validate(t_game *game, int x, int y, int len)
{
	printf("horizontal_validate start\n");
	while(game->map.map[x][y] != ' ' && y <= len)
		y++;
	printf("y in h: %d\n", y);
	printf("len in h: %d\n", game->len);
	if(y >= len)
	{
		printf("in func\n");
		if(game->map.map[x][y] != '1')
		{
			while(game->map.map[x][y] == ' ' || game->map.map[x][y] == '\t' || game->map.map[x][y] == '\n')
				y--;
		}
		printf("in func2\n");
		printf("game->map.map[x][y]: %c\n", game->map.map[x][y]);
		if(game->map.map[x][y] == '1')
				return -2;
		printf("in func3\n");
		return -1;
	}
	printf("test 33\n");
	if(game->map.map[x][y] != ' ' || game->map.map[x][y - 1] != '1')
		return -1;
	while(game->map.map[x][y] == ' ' && y <= len)
		y++;
	if(game->map.map[x][y] != '1')
	{
		if (y == len)
		{
			while(game->map.map[x][y] == ' ' || game->map.map[x][y] == '\t')
				y--;
			if(game->map.map[x][y] == '1')
				return y;
			else
				return -1;
		}
		else
			return -1;
	}
	return y;
}


int horizontal_check(t_game *game)
{
	int x;
	int y;

	x = 0;
	while(x <= game->height - 1)
	{
		printf("xxxxxxxxx: %d\n", x);
		y = space_skip(game, x);
		if(game->map.map[x][y] != '1')
			return -1;
		printf("y: %d\n", y);
		game->len = ft_strlen(game->map.map[x]) - 2;
		printf("len: %d\n", game->len);
		while(y <= game->len)
		{
			printf("test 1\n");
			if (horizontal_validate(game, x, y, game->len) == -1)
				return -1;
			else if (horizontal_validate(game, x, y, game->len) == -2)
				break;
			else
				y = horizontal_validate(game, x, y, game->len);
		}
		printf("test 2\n");
		x++;
	}
	return 0;
}

void map_check(t_game *game)
{
	if(horizontal_check(game) == -1)
	{
		printf("String: %s\n", "horizontal_check error");
		exit(1);
	}
}