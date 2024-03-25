/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocuk <ahocuk@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 18:42:13 by ahocuk            #+#    #+#             */
/*   Updated: 2024/03/25 17:48:17 by ahocuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void replace_spaces_with_one(t_game *game) {
    int map_height = 0;
    while (map_height < game->height -1) {
        char *current_line = game->map.map[map_height];
        // while (current_line && (*current_line != '\0'))
		int len = ft_strlen(game->map.map[map_height]);
		int i = 0;
		while (i <= len)
		{
            if (current_line[i] == ' ' || current_line[i] == '\n' || current_line[i] == '\0') {
                current_line[i] = '1';
            }
            i++;
        }
        map_height++;
    }
}


// void replace_spaces_with_one(t_game *game) {
//     int map_height = 0;
//     while (map_height <= game->height) {
//         char *current_line = game->map.map[map_height];
//         // while (current_line && (*current_line != '\0'))
// 		// ft_strlen()
// 		// while ((current_line != NULL) && (*current_line != '\0'))
// 		int i = 0;
// 		while (current_line[i])
// 		{
//             if (current_line[i] == ' ' || current_line[i] == '\n' || current_line[i] == '\0') {
//                 current_line[i] = '1';
//             }
//             i++;
//         }
//         map_height++;
//     }
// }

void map_check(t_game *game)
{
	printf("String: %s\n", "mapcheck start");
	// if(horizontal_check(game) == -1)
	// {
	// 	printf("String: %s\n", "horizontal_check error");
	// 	exit(1);
	// }
	// printf("String: %s\n", "horizontal_check passed");
	// if(vertical_check(game) == -1)
	// {
	// 	printf("String: %s\n", "vertical_check error");
	// 	exit(1);
	// }
	replace_spaces_with_one(game);
}
