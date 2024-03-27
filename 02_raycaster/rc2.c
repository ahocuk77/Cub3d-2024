/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:14:40 by musenov           #+#    #+#             */
/*   Updated: 2024/03/27 18:55:26 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

void	draw_background(t_game *game)
{
	int			x;
	int			y;
	int			color;

	color = rgba_to_color(39, 181, 245, 200);
	y = 0;
	while (y < WIN_H / 2)
	{
		x = 0;
		while (x < WIN_W)
		{
			mlx_put_pixel(game->img, x++, y, color);
		}
		y++;
	}
	color = rgba_to_color(6, 170, 85, 200);
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			mlx_put_pixel(game->img, x++, y, color);
		}
		y++;
	}
}

void	draw_lines(t_game *game)
{
	float	v;
	float	dv;
	int		x;
	float	dist;

	// v = game->view - FOV / 2;
	v = game->player.view_angle + FOV / 2;
	dv = FOV / (WIN_W - 1);
	x = -1;
	while (++x < WIN_W)
	{
		dist = cast_ray(game, v) * cos(game->player.view_angle - v);
		// dist = cast_ray(game, v);
		draw_line(game, x, dist);
		// v += dv;
		v -= dv;
	}
}

void	render(t_game *game)
{
	draw_background(game);
	draw_lines(game);
}

