/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_init_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:15:33 by musenov           #+#    #+#             */
/*   Updated: 2024/05/03 14:25:31 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"

void	init_player(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (game->map.map[i][j])
		{
			if (game->map.map[i][j] == 'E' || game->map.map[i][j] == 'S' || \
				game->map.map[i][j] == 'W' || game->map.map[i][j] == 'N')
			{
				game->player.pos_x = (float)j;
				game->player.pos_y = (float)i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	init_direction(t_game *game, char c)
{
	if (c == 'E')
		game->player.view_angle = 0.0f * PI;
	if (c == 'S')
		game->player.view_angle = -0.5f * PI;
	if (c == 'W')
		game->player.view_angle = 1.0f * PI;
	if (c == 'N')
		game->player.view_angle = 0.5f * PI;
}
