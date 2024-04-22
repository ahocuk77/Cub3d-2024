/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:14:40 by musenov           #+#    #+#             */
/*   Updated: 2024/04/22 20:35:14 by musenov          ###   ########.fr       */
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

	// int				t;
	uint8_t			*pixel;
	int				num;



/* 	if (game->wall.side == EA || game->wall.side == WE)
		// here distance.x is distance to vertical grid-line, i.e. hor distance
		draw_lineof_texture(game, i, distance.x - game->ray.delta_x);
	else
		// here distance.y is distance to horizontal grid-line, i.e. vert distance
		draw_lineof_texture(game, i, distance.y - game->ray.delta_y); */



	draw.line_height = (int)(WIN_H / dist);
	draw.start = (WIN_H / 2) - (draw.line_height / 2);
	draw.end = (draw.line_height / 2) + (WIN_H / 2);

/* 	if (game->wall.txt_idx == 0 || game->wall.txt_idx == 2)
		draw.wall_x = game->player.pos_y + dist * game->ray.dy;
	else
		draw.wall_x = game->player.pos_x + dist * game->ray.dx; */


	// draw.wall_x -= floor(draw.wall_x);
	draw.wall_x = game->wall.txt_w;
	draw.text_x = (int)(draw.wall_x * (double)game->wall.texture[game->wall.txt_idx].width);
	draw.text_y = 0;
	draw.text_step = (double)game->wall.texture[game->wall.txt_idx].height / (double)draw.line_height;
	if (draw.start < 0)
		draw.text_y = fabs((double)draw.start) * draw.text_step;

/*

	if (game->wall.txt_idx == 0)
		color = rgba_to_color(235, 233, 20, 255);
	else if (game->wall.txt_idx == 1)
		color = rgba_to_color(93, 106, 235, 255);
	else if (game->wall.txt_idx == 2)
		color = rgba_to_color(209, 255, 194, 255);
	else if (game->wall.txt_idx == 3)
		color = rgba_to_color(234, 56, 56, 255);

*/

	h = 0;
	while (h < WIN_H)
	{
		if (h >= draw.start && h <= draw.end)
		{
			num = game->wall.texture[game->wall.txt_idx].width * 4 * (int)draw.text_y + (int)draw.text_x * 4;
			pixel = &game->wall.texture[game->wall.txt_idx].pixels[num];
			color = rgba_to_color(pixel[0], pixel[1], pixel[2], pixel[3]);
			mlx_put_pixel(game->img, col, h, color);
			draw.text_y += draw.text_step;
		}
		h++;
	}
}





/* void	prepare_texture(t_game *game, int col, double wall_distance)
{
	t_draw	draw;

	draw.line_height = (int)(WIN_H / wall_distance);
	draw.start = (SCREEN_HEIGHT / 2) - (draw.line_height / 2);
	draw.end = (draw.line_height / 2) + (SCREEN_HEIGHT / 2);
	if (game->wall.side == WE || game->wall.side == EA)
		draw.wall_x = game->player.y + wall_distance * game->ray.y;
	else
		draw.wall_x = game->player.x + wall_distance * game->ray.x;
	draw.wall_x -= floor(draw.wall_x);
	draw.text_x = (int)(draw.wall_x * \
	(double)game->wall.texture[game->wall.side].width);
	draw.text_y = 0;
	draw.text_step = (double)game->wall.texture[game->wall.side].height / \
	(double)draw.line_height;
	if (draw.start < 0)
		draw.text_y = fabs((double)draw.start) * draw.text_step;
	draw_column(game, &draw, col);
}



void	draw_column(t_game *game, t_draw *draw, int col)
{
	unsigned int	color;
	int				t;
	uint8_t			*pixel;
	int				num;

	t = -1;
	while (++t < SCREEN_HEIGHT)
	{
		if (t >= draw->start && t <= draw->end && \
		draw->text_y < game->wall.texture[game->wall.side].height)
		{
			num = game->wall.texture[game->wall.side].width * 4 * \
			(int)draw->text_y + (int)draw->text_x * 4;
			pixel = &game->wall.texture[game->wall.side].pixels[num];
			color = ft_pixel(pixel[0], pixel[1], pixel[2], pixel[3]);
			mlx_put_pixel(game->img, col, t, color);
			draw->text_y += draw->text_step;
		}
		else if (t < draw->start)
			mlx_put_pixel(game->img, col, t, \
			ft_pixel(game->c_color.r, game->c_color.g, game->c_color.b, 255));
		else if (t > draw->end)
			mlx_put_pixel(game->img, col, t, \
			ft_pixel(game->f_color.r, game->f_color.g, game->f_color.b, 255));
	}
} */





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



/* 		if (game->wall.txt_idx == 0 || game->wall.txt_idx == 2)
			// here distance.x is distance to vertical grid-line, i.e. hor distance
			draw_line(game, x, game->ray.vert_dist);
			// draw_lineof_texture(game, i, distance.x - game->ray.delta_x);
		else
			// here distance.y is distance to horizontal grid-line, i.e. vert distance
			draw_line(game, x, game->ray.hor_dist);
			// draw_lineof_texture(game, i, distance.y - game->ray.delta_y); */



		draw_line(game, x, dist);
		// draw_line_call_count++;
		// printf("draw_line_call: %d\n", draw_line_call_count);
		v -= dv;
	}
}




void	render(t_game *game)
{
	draw_background(game);
	draw_lines(game);
}

