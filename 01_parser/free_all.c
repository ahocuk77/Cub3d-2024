/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:14:51 by ahocuk            #+#    #+#             */
/*   Updated: 2024/05/04 19:33:59 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_all(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->wall.path_num -1)
	{
		free(game->wall.path[i]);
		i++;
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
