/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:18:22 by musenov           #+#    #+#             */
/*   Updated: 2024/03/27 18:16:57 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

int	ft_sign(float f)
{
	if (f < 0.0f)
	{
		if (f > -0.000001)
			return (0);
		else
			return (-1);
	}
	else
	{
		if (f < 0.000001f)
			return (0);
		else
			return (1);
	}
}

void	ft_ray_initial_calculations(t_game *game, t_ray *r, float v)
{
	r->dx = cos(v);
	r->dy = -sin(v);
	r->sx = ft_sign(r->dx);
	r->sy = ft_sign(r->dy);
	r->vert_x = (int) game->player.pos_x;
	if (r->sx > 0)
		r->vert_x += 1.0f;
	r->hor_y = (int) game->player.pos_y;
	if (r->sy > 0)
		r->hor_y += 1.0f;
}

void	ft_ray_next_step_calculation(t_game *game, t_ray *r)
{
	if (r->sx != 0)
	{
		r->vert_y = game->player.pos_y + r->dy / r->dx * (r->vert_x - game->player.pos_x);
		r->vert_dist = sqrt(pow(game->player.pos_x - r->vert_x, 2.0)
				+ pow(game->player.pos_y - r->vert_y, 2.0));
		r->vert_w = r->vert_y - (int) r->vert_y;
		if (r->sx > 0)
			r->vert_w = 1 - r->vert_w;
	}
	else
		r->vert_dist = INFINITY;
	if (r->sy != 0)
	{
		r->hor_x = game->player.pos_x + r->dx / r->dy * (r->hor_y - game->player.pos_y);
		r->hor_dist = sqrt(pow(game->player.pos_x - r->hor_x, 2.0)
				+ pow(game->player.pos_y - r->hor_y, 2.0));
		r->hor_w = r->hor_x - (int) r->hor_x;
		if (r->sy < 0)
			r->hor_w = 1 - r->hor_w;
	}
	else
		r->hor_dist = INFINITY;
}

/* static float	ft_save_color(t_game *game, float dist, int color_idx, float w)
{
	game->txt_idx = color_idx;
	game->txt_w = w;
	return (dist);
} */

float	cast_ray(t_game *game, float v)
{
	t_ray	r;

	ft_ray_initial_calculations(game, &r, v);
	while (1)
	{
		ft_ray_next_step_calculation(game, &r);
		if (r.vert_dist < r.hor_dist)
		{
			if (game->map.map[(int)r.vert_y][(int)r.vert_x + (r.sx - 1) / 2] == '1')
				// return (ft_save_color(game, r.vert_dist, r.sx + 1, r.vert_w));
				return (r.vert_dist);
			else
				r.vert_x += r.sx;
		}
		else
		{
			if (game->map.map[(int)r.hor_y + (r.sy - 1) / 2][(int)r.hor_x] == '1')
				// return (ft_save_color(game, r.hor_dist, r.sy + 2, r.hor_w));
				return (r.hor_dist);
			else
				r.hor_y += r.sy;
		}
	}
}

/* void	ft_line(t_game *game, int w, float dist)
{
	unsigned int	*dst;
	unsigned int	*src;
	unsigned int	h;
	float			src_f;
	float			d_shift;

	h = (float) WIN_H / dist;
	src_f = 0.0f;
	d_shift = (float) game->txt[game->txt_idx].height / h;
	if (h > WIN_H)
	{
		src_f = 0.5f * (h - WIN_H) / h * game->txt[game->txt_idx].height;
		h = WIN_H;
	}
	src = (unsigned int *) game->txt[game->txt_idx].addr;
	src += (int)((float) game->txt_w * game->txt[game->txt_idx].width);
	dst = (unsigned int *) game->img.addr + w + (WIN_H - h) / 2 * WIN_W;
	while (h-- > 0)
	{
		*dst = *(src + ((int)src_f) * game->txt[game->txt_idx].width);
		// *dst = game->txt_idx * 255 + (1 - game->txt_idx) * (255 << 8);
		dst += WIN_W;
		src_f += d_shift;
	}
} */

/* void	draw_lineof_texture(t_game *game, int col, double wall_distance)
{
	t_draw	draw;

	draw.line_height = (int)(SCREEN_HEIGHT / wall_distance);
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
} */

void	draw_line(t_game *game, int col, float dist)
{
	t_draw	draw;

	draw.line_height = (int)(WIN_H / dist);
	draw.start = (WIN_H / 2) - (draw.line_height / 2);
	draw.end = (draw.line_height / 2) + (WIN_H / 2);
	draw_column(game, &draw, col);
}


void	draw_column(t_game *game, t_draw *draw, int col)
{
	unsigned int	color;
	int				t;

	t = -1;
	while (++t < WIN_H)
	{
		if (t >= draw->start && t <= draw->end)
		{
			color = rgba_to_color(205, 127, 50, 255);
			mlx_put_pixel(game->img, col, t, color);
		}
	}
}


/* void	ft_ray_casting(t_game *game)
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
} */
