/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_cast_ray_00.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:18:22 by musenov           #+#    #+#             */
/*   Updated: 2024/05/03 13:44:19 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"

float	get_color(t_game *game, float dist, int color_idx, float w)
{
	game->wall.txt_idx = color_idx;
	game->wall.txt_w = w;
	return (dist);
}

void	initialize_ray_direction_and_position(t_game *game, t_ray *r, float v)
{
	r->dx = cos(v);
	r->dy = -sin(v);
	r->sx = get_sign(r->dx);
	r->sy = get_sign(r->dy);
	r->vert_x = (int) game->player.pos_x;
	r->hor_y = (int) game->player.pos_y;
	if (r->sx > 0)
		r->vert_x += 1.0f;
	if (r->sy > 0)
		r->hor_y += 1.0f;
}

float	cast_ray(t_game *game, float angle)
{
	t_ray	ray;

	initialize_ray_direction_and_position(game, &ray, angle);
	dist_to_vert_grid_lines(game, &ray);
	dist_to_hor_grid_lines(game, &ray);
	if (ray.vert_dist < ray.hor_dist)
		return (get_color(game, ray.vert_dist, ray.sx + 1, ray.vert_w));
	else
		return (get_color(game, ray.hor_dist, ray.sy + 2, ray.hor_w));
}
