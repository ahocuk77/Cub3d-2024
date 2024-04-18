/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:14:40 by musenov           #+#    #+#             */
/*   Updated: 2024/04/18 20:04:45 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"

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


void	draw_line(t_game *game, int col, float dist)
{
	t_draw			draw;
	unsigned int	color;
	int				h;

	draw.line_height = (int)(WIN_H / dist);
	draw.start = (WIN_H / 2) - (draw.line_height / 2);
	draw.end = (draw.line_height / 2) + (WIN_H / 2);



	// ** // new code start
	
	
/* 	
	if (game->wall.txt_idx == WE || game->wall.txt_idx == EA)
		draw.wall_x = game->player.pos_y + dist * game->ray.y;
	else
		draw.wall_x = game->player.pos_x + dist * game->ray.x;
	 */
	
	
	// ** // new code end



	color = rgba_to_color(205, 127, 50, 255);
	h = 0;
	while (h < WIN_H)
	{
		if (h >= draw.start && h <= draw.end)
			mlx_put_pixel(game->img, col, h, color);
		h++;
	}
}

void	draw_lines(t_game *game)
{
	float	v;
	float	dv;
	int		x;
	float	dist;
	int		draw_line_call_count;

	v = game->player.view_angle + FOV / 2;
	dv = FOV / (WIN_W - 1);
	x = -1;
	draw_line_call_count = 0;
	while (++x < WIN_W)
	{
		// here u pull the pixels from the textures
		dist = cast_ray(game, v) * cos(game->player.view_angle - v);
		draw_line(game, x, dist);
		draw_line_call_count++;
		printf("draw_line_call: %d\n", draw_line_call_count);
		v -= dv;
	}
}




void	render(t_game *game)
{
	draw_background(game);
	draw_lines(game);
}

