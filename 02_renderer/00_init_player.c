/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_init_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:15:33 by musenov           #+#    #+#             */
/*   Updated: 2024/05/02 21:56:02 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"

void	find_view_angle(t_game *game, const char c)
{
	if (c == 'E')
		game->player.view_angle = 0.0f * M_PI;
	else if (c == 'N')
		game->player.view_angle = 0.5f * M_PI;
	else if (c == 'W')
		game->player.view_angle = 1.0f * M_PI;
	else if (c == 'S')
		game->player.view_angle = -0.5f * M_PI;
}

void	init_player(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.height)
	{
		j = -1;
		while (game->map.map[i][++j])
		{
			if (ft_strchr("NSWE", game->map.map[i][j]))
			{
				game->player.pos_x = (float) j + 0.5f;
				game->player.pos_y = (float) i + 0.5f;
				find_view_angle(game, game->map.map[i][j]);
				return ;
			}
		}
	}
}
