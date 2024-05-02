/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_cast_ray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:18:22 by musenov           #+#    #+#             */
/*   Updated: 2024/05/02 21:53:30 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"

float	get_color(t_game *game, float dist, int color_idx, float w)
{
	game->wall.txt_idx = color_idx;
	game->wall.txt_w = w;
	return (dist);
}

void	ray_start_calcs(t_game *game, t_ray *r, float v)
{
	r->dx = cos(v);
	r->dy = -sin(v);
	r->sx = get_sign(r->dx);
	r->sy = get_sign(r->dy);
	r->vert_x = (int) game->player.pos_x;
	if (r->sx > 0)
		r->vert_x += 1.0f;
	r->hor_y = (int) game->player.pos_y;
	if (r->sy > 0)
		r->hor_y += 1.0f;
}

void	calculate_dist_to_vert_grid_line(t_game *game, t_ray *r)
{
	r->vert_y = game->player.pos_y + (r->dy / r->dx) * \
				(r->vert_x - game->player.pos_x);
	r->vert_dist = sqrt(pow(game->player.pos_x - r->vert_x, 2.0) + \
					pow(game->player.pos_y - r->vert_y, 2.0));
	r->vert_w = r->vert_y - (int) r->vert_y;
	if (r->sx > 0)
		r->vert_w = 1 - r->vert_w;
}

void	dist_to_vert_grid_lines(t_game *game, t_ray *r)
{
	while (1)
	{
		if (r->sx != 0)
			calculate_dist_to_vert_grid_line(game, r);
		else
		{
			r->vert_dist = INFINITY;
			break ;
		}
		if ((int)r->vert_x >= 0 && (int)r->vert_x < game->map.width && \
			(int)r->vert_y >= 0 && (int)r->vert_y < game->map.height)
		{
			if (game->map.map[(int)r->vert_y] \
								[(int)r->vert_x + (r->sx - 1) / 2] == '1')
				break ;
			else
				r->vert_x += r->sx;
		}
		else
		{
			r->vert_dist = INFINITY;
			break ;
		}
	}
}

void	calculate_dist_to_hor_grid_line(t_game *game, t_ray *r)
{
	r->hor_x = game->player.pos_x + (r->dx / r->dy) * \
				(r->hor_y - game->player.pos_y);
	r->hor_dist = sqrt(pow(game->player.pos_x - r->hor_x, 2.0) + \
					pow(game->player.pos_y - r->hor_y, 2.0));
	r->hor_w = r->hor_x - (int) r->hor_x;
	if (r->sy < 0)
		r->hor_w = 1 - r->hor_w;
}

void	dist_to_hor_grid_lines(t_game *game, t_ray *r)
{
	while (1)
	{
		if (r->sy != 0)
			calculate_dist_to_hor_grid_line(game, r);
		else
		{
			r->hor_dist = INFINITY;
			break ;
		}
		if ((int)r->hor_x >= 0 && (int)r->hor_x < game->map.width && \
			(int)r->hor_y >= 0 && (int)r->hor_y < game->map.height)
		{
			if (game->map.map[(int)r->hor_y + (r->sy - 1) / 2] \
								[(int)r->hor_x] == '1')
				break ;
			else
				r->hor_y += r->sy;
		}
		else
		{
			r->hor_dist = INFINITY;
			break ;
		}
	}
}

float	cast_ray(t_game *game, float v)
{
	t_ray	r;

	r.dx = cos(v);
	r.dy = -sin(v);
	r.sx = get_sign(r.dx);
	r.sy = get_sign(r.dy);
	r.vert_x = (int) game->player.pos_x;
	if (r.sx > 0)
		r.vert_x += 1.0f;
	r.hor_y = (int) game->player.pos_y;
	if (r.sy > 0)
		r.hor_y += 1.0f;
	dist_to_vert_grid_lines(game, &r);
	dist_to_hor_grid_lines(game, &r);
	if (r.vert_dist < r.hor_dist)
		return (get_color(game, r.vert_dist, r.sx + 1, r.vert_w));
	else
		return (get_color(game, r.hor_dist, r.sy + 2, r.hor_w));
}
