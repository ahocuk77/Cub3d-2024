/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:14:40 by musenov           #+#    #+#             */
/*   Updated: 2024/05/03 17:26:22 by musenov          ###   ########.fr       */
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

void	preliminary_calcs(t_draw *draw, t_game *game, float dist)
{
	draw->line_height = (int)(WIN_H / dist);
	draw->start = (WIN_H / 2) - (draw->line_height / 2);
	draw->end = (draw->line_height / 2) + (WIN_H / 2);
	draw->wall_x = game->wall.txt_w;
	draw->text_x = (int)(draw->wall_x * \
					(double)game->wall.texture[game->wall.txt_idx].width);
	draw->text_y = 0;
	draw->text_step = (double)game->wall.texture[game->wall.txt_idx].height / \
						(double)draw->line_height;
	if (draw->start < 0)
		draw->text_y = fabs((double)draw->start) * draw->text_step;
}

void	draw_line(t_game *game, int col, float dist)
{
	t_draw			draw;
	unsigned int	color;
	int				h;
	uint8_t			*pixel;
	int				num;

	int				max_index;

	preliminary_calcs(&draw, game, dist);
	h = 0;
	while (h < WIN_H)
	{
		if (h >= draw.start && h <= draw.end)
		{
			num = game->wall.texture[game->wall.txt_idx].width * 4 * \
							(int)draw.text_y + (int)draw.text_x * 4;
			max_index = game->wall.texture[game->wall.txt_idx].width * \
						game->wall.texture[game->wall.txt_idx].height * 4;
			if (num >= 0 && num < max_index)
			{
				pixel = &game->wall.texture[game->wall.txt_idx].pixels[num];
				color = rgba_to_color(pixel[0], pixel[1], pixel[2], pixel[3]);
				mlx_put_pixel(game->img, col, h, color);
				draw.text_y += draw.text_step;
			}
			else
			{
				printf("num is beyond limits and equals to -> %d\n", num);
				printf("while max_index is: %d\n", max_index);
			}
		}
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
	x = 0;
	draw_line_call_count = 0;
	while (x < WIN_W)
	{
		dist = cast_ray(game, v) * cos(game->player.view_angle - v);
		draw_line(game, x, dist);
		v -= dv;
		x++;
	}
}

void	render(t_game *game)
{
	draw_background(game);
	draw_lines(game);
}
