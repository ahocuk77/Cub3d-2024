/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_cast_ray_00.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:18:22 by musenov           #+#    #+#             */
/*   Updated: 2024/05/03 13:39:30 by musenov          ###   ########.fr       */
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

/* void	initialize_ray_direction_and_position(t_game *game, t_ray *ray, float angle)
{
	// Calculate directional components of the ray based on the input angle.
	ray->dx = cos(angle);
	ray->dy = -sin(angle); // Using -sin to adjust for y-axis inversion in many graphics coordinate systems.

	// Determine the step direction in x and y (either -1, 0, or 1).
	ray->sx = get_sign(ray->dx);
	ray->sy = get_sign(ray->dy);

	// Set up the initial vertical and horizontal check positions based on the player's current position.
	// These positions are used to find where the ray intersects the grid lines of the map.
	ray->vert_x = (int)game->player.pos_x;
	ray->hor_y = (int)game->player.pos_y;

	// Adjust check positions to the next grid line if the step direction is positive.
	if (ray->sx > 0) {
		ray->vert_x += 1.0f; // Move to the right grid line if moving right.
	}
	if (ray->sy > 0) {
		ray->hor_y += 1.0f; // Move to the next lower grid line if moving downward.
	}
} */




float	cast_ray(t_game *game, float angle)
{
	t_ray	ray;

/* 	r.dx = cos(v);
	r.dy = -sin(v);
	r.sx = get_sign(r.dx);
	r.sy = get_sign(r.dy);
	r.vert_x = (int) game->player.pos_x;
	if (r.sx > 0)
		r.vert_x += 1.0f;
	r.hor_y = (int) game->player.pos_y;
	if (r.sy > 0)
		r.hor_y += 1.0f; */
	initialize_ray_direction_and_position(game, &ray, angle);
	dist_to_vert_grid_lines(game, &ray);
	dist_to_hor_grid_lines(game, &ray);
	if (ray.vert_dist < ray.hor_dist)
		return (get_color(game, ray.vert_dist, ray.sx + 1, ray.vert_w));
	else
		return (get_color(game, ray.hor_dist, ray.sy + 2, ray.hor_w));
}
