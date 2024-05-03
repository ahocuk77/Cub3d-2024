/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocuk <ahocuk@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 18:42:13 by ahocuk            #+#    #+#             */
/*   Updated: 2024/05/03 19:41:11 by ahocuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	replace_spaces_with_one(t_game *game)
{
	int		map_height;
	char	*current_line;
	int		len;
	int		i;

	map_height = 0;
	while (map_height < game->map.height)
	{
		current_line = game->map.map[map_height];
		len = ft_strlen(game->map.map[map_height]);
		i = 0;
		while (i <= len)
		{
			if (current_line[i] == ' ' || current_line[i] == '\n'
				|| current_line[i] == '\0')
			{
				if (current_line[i] == '\0')
					break ;
				current_line[i] = '1';
			}
			i++;
		}
		map_height++;
	}
}

void	map_check(t_game *game)
{
	printf("String: %s\n", "mapcheck start");
	if (horizontal_check(game) == -1)
	{
		printf("String: %s\n", "horizontal_check error");
		exit(1);
	}
	printf("String: %s\n", "horizontal_check passed");
	if (vertical_check(game) == -1)
	{
		printf("String: %s\n", "vertical_check error");
		exit(1);
	}
	replace_spaces_with_one(game);
}
