/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:12:09 by ahocuk            #+#    #+#             */
/*   Updated: 2024/03/25 15:40:24 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init(t_game *game)
{
	game->c_color_num = 0;
	game->f_color_num = 0;
	game->total_color_num = 0;
	game->path_num = 0;
	game->texture_num[NO] = 0;
	game->texture_num[SO] = 0;
	game->texture_num[WE] = 0;
	game->texture_num[EA] = 0;
	game->map.size = 0;
	game->new_line_checker = false;
	game->height = 0;
	game->texture_check = 0;
	game->map_check = 0;
	game->color_check = 0;
	game->map.map = NULL;
}