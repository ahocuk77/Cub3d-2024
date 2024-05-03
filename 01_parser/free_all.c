/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocuk <ahocuk@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:14:51 by ahocuk            #+#    #+#             */
/*   Updated: 2024/05/03 21:36:00 by ahocuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_all2(t_game *game)
{
	int	i;

	i = 0;
	if (game->wall.path_num < 4 && game->wall.path_num != 0)
	{
		while (i < game->wall.path_num -2)
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
}

void	free_all(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->wall.path_num)
	{
		free(game->wall.path[i]);
		i++;
	}
	free_all2(game);
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
