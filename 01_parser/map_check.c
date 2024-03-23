/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocuk <ahocuk@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 18:42:13 by ahocuk            #+#    #+#             */
/*   Updated: 2024/03/22 17:22:00 by ahocuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void replace_spaces_with_one(t_game *game) {
    int map_height = 0;
    while (game->map.map[map_height] != NULL) {
        char *current_line = game->map.map[map_height];
        while (*current_line != '\0') {
            if (*current_line == ' ' || *current_line == '\n' || *current_line == '\0') {
                *current_line = '1';
            }
            current_line++;
        }
        map_height++;
    }
}

void map_check(t_game *game)
{
	printf("String: %s\n", "mapcheck start");
	if(horizontal_check(game) == -1)
	{
		printf("String: %s\n", "horizontal_check error");
		exit(1);
	}
	printf("String: %s\n", "horizontal_check passed");
	if(vertical_check(game) == -1)
	{
		printf("String: %s\n", "vertical_check error");
		exit(1);
	}
	replace_spaces_with_one(game);
}
