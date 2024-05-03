/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:12:09 by ahocuk            #+#    #+#             */
/*   Updated: 2024/03/27 16:07:31 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init(t_game *game)
{
	game->color.c_color_num = 0;
	game->color.f_color_num = 0;
	game->color.total_color_num = 0;
	game->wall.path_num = 0;
	game->wall.texture_num[NO] = 0;
	game->wall.texture_num[SO] = 0;
	game->wall.texture_num[WE] = 0;
	game->wall.texture_num[EA] = 0;
	game->map.size = 0;
	game->map.new_line_checker = false;
	game->map.height = 0;
	game->wall.texture_check = 0;
	game->map.map_check = 0;
	game->color.color_check = 0;
	game->map.map = NULL;
	game->map.player = '\0';
}
