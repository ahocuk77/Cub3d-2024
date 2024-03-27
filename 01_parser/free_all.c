/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocuk <ahocuk@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:14:51 by ahocuk            #+#    #+#             */
/*   Updated: 2024/03/27 14:41:41 by ahocuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_all(t_game *game)
{
	int	i;

	i = 0;
	printf("%s\n", "memory free start");
	while (i < game->wall.path_num)
	{
		printf("%s\n", game->wall.path[i]);
		free(game->wall.path[i]);
		i++;
	}
	i = 0;
	if (game->wall.path_num < 4 && game->wall.path_num != 0)
	{
		while (i < game->wall.path_num -1)
		{
			mlx_delete_xpm42(game->wall.xpm[i]);
			i++;
		}
		mlx_delete_xpm42(game->wall.xpm[i]);
	}
	else
	{
		while (i < game->wall.path_num)
		{
			mlx_delete_xpm42(game->wall.xpm[i]);
			i++;
		}
	}
	i = 0;
	if (game->map.map == NULL)
		return ;
	while (i < game->map.height)
	{
		free(game->map.map[i]);
		i++;
	}
	free(game->map.map);
}

	// while(game->map.map[i] != NULL)
	// {
	// 	free(game->map.map[i]);
	// 	i++;

	// 	printf("%s\n", "map deleted");
	// 	if(game->map.map[i] == NULL)
	// 	{
	// 		free(game->map.map);
	// 		break ;
	// 	}
	// }