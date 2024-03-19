/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocuk <ahocuk@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:58:52 by ahocuk            #+#    #+#             */
/*   Updated: 2024/03/19 21:09:58 by ahocuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int vertical_space_skip(t_game *game, int y) // dikey yap 
{
	int x;

	x = 0;
	if(game->map.map[x][y] == '\t' || game->map.map[x][y] == ' ')
	{
		while(game->map.map[x][y] == '\t' || game->map.map[x][y] == ' ')
			x++;
	}
	printf("xxxxxx %d\n", x);
	return (x);
}

int vertical_validate(t_game *game, int x, int y, int len)
{
	printf("start1 \n");
	while((game->map.map[x][y] != ' ' && game->map.map[x][y] != '\t') && x < len)
		x++;
	printf("start2 \n");
	if(game->map.map[x][y] == '\t')
	{
		while(game->map.map[x][y] == '\t')
			x++;
		if(game->map.map[x][y] != '\0' || game->map.map[x][y] != '\n')
			return -1;
	}
	printf("start3 \n");
	if(x >= len)
	{
		if(game->map.map[x][y] != '1')
		{
			while(game->map.map[x][y] == ' ' || game->map.map[x][y] == '\t' || game->map.map[x][y] == '\n')
				x--;
		}
		if(game->map.map[x][y] == '1')
				return -2;
		return -1;
	}
	printf("4234242 in : %d\n", x);
	printf("start4 \n");
	// if(game->map.map[x][y] != ' ' || game->map.map[x - 1][y] != '1')// check again
	// 	return -1;
	printf("start5 \n");
	while(game->map.map[x][y] == ' ' && x <= len)
		x++;
	printf("xxxxxx in : %d\n", x);
	printf("start6 \n");
	if(game->map.map[x][y] != '1')
	{
		printf("start in 6 \n");
		printf("xxxxxx in 6: %d\n", x);
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
				printf("start in xxxx \n");
				return x;
			}
			else
				return -1;
			printf("start in 3333\n");
		}
		else
			return -1;
	}
	printf("start7 \n");
	return x;
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

void	print_map(t_game *game)
{
	for (int row = 0; row < game->width -1; ++row) {
		for (int col = 0; col < game->height -1 ; ++col) {
			printf("%3d", game->map.map[row][col]);
		}
		printf("\n");
	}
}

int vertical_check(t_game *game)
{
	int x;
	int y;

	y = 0;
	while(y < game->width - 1)
	{
		printf("String: %s\n", "vertical_check start");
		x = vertical_space_skip(game, y);
		if(game->map.map[x][y] != '1')
		{
			printf("y return;  %3d\n", y);
			printf("x return;  %3d\n", x);
			printf("game->width;  %3d\n", game->width);
			printf("game->map.map[x][y];  %d\n", game->map.map[x][y]);
			printf("return 1; \n");
			printf("-------\n");
			//print_map(game);
			printf("-------\n");
			return -1;
		}
		game->len = vertical_length(game->map.map, y);
		printf("game->len:  %d\n", game->len);
		while(x <= game->len)
		{
			printf("String: %s\n", "vertical_validate start");
			if (vertical_validate(game, x, y, game->len) == -1)
			{
				printf("return 2; \n");
				return -1;
			}
			else if (vertical_validate(game, x, y, game->len) == -2)
				break;
			else
				x = vertical_validate(game, x, y, game->len);
		}
		y++;
	}
	return 0;
}