/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:14:40 by musenov           #+#    #+#             */
/*   Updated: 2024/04/15 15:25:07 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

void	draw_background(t_game *game)
{
	int			x;
	int			y;
	int			color;

	color = rgba_to_color(game->color.ceiling.r, game->color.ceiling.g, \
							game->color.ceiling.b, 255);
	y = 0;
	while (y < WIN_H / 2)
	{
		x = 0;
		while (x < WIN_W)
			mlx_put_pixel(game->img, x++, y, color);
		y++;
	}
	color = rgba_to_color(game->color.floor.r, game->color.floor.g, \
							game->color.floor.b, 255);
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
			mlx_put_pixel(game->img, x++, y, color);
		y++;
	}
}

void	draw_lines(t_game *game)
{
	float	v;
	float	dv;
	int		x;
	float	dist;

	v = game->player.view_angle + FOV / 2;
	dv = FOV / (WIN_W - 1);
	x = -1;
	while (++x < WIN_W)
	{
		// here u pull the pixels from the textures
		dist = cast_ray(game, v) * cos(game->player.view_angle - v);
		draw_line(game, x, dist);
		v -= dv;
	}
}





/*


void	ft_ray_casting(t_game *game)
{
	int		x;
	float	dv;
	float	v;

	// v = game->view - FOV / 2;
	v = game->view + FOV / 2;
	dv = FOV / (WINDOW_W - 1);
	x = -1;
	while (++x < WINDOW_W)
	{
		ft_line(game, x, ft_ray(game, v) * cos(game->view - v)); // cos is for fish eye effect removal
		// v += dv;
		v -= dv;
	}
}


*/





void	render(t_game *game)
{
	draw_background(game);
	draw_lines(game);
}
