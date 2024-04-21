/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_cast_ray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:18:22 by musenov           #+#    #+#             */
/*   Updated: 2024/04/21 15:32:24 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"

float	get_color(t_game *game, float dist, int color_idx, float w)
{
	// (void)w;
	game->wall.txt_idx = color_idx;
/* 	if (game->wall.txt_idx == 0)
		printf("direction: NO, %d\n", NO);
	else if (game->wall.txt_idx == 1)
		printf("direction: SO, %d\n", SO);
	else if (game->wall.txt_idx == 2)
		printf("direction: WE, %d\n", WE);
	else if (game->wall.txt_idx == 3)
		printf("direction: EA, %d\n", EA); */
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


/*

// // this solution will worj if we have a map which is fully filled, i.e. rectangular.
// // i am  calculating dist_to_vert_grid_lines continuosly until the wall is reached, but
// // the map is not rectangular therefore this doesnt work.

void	dist_to_vert_grid_lines(t_game *game, t_ray *r)
{
	while (1)
	{
		if (r->sx != 0)
		{
			r->vert_y = game->player.pos_y + (r->dy / r->dx) * (r->vert_x - game->player.pos_x);
			r->vert_dist = sqrt(pow(game->player.pos_x - r->vert_x, 2.0) + pow(game->player.pos_y - r->vert_y, 2.0));
			r->vert_w = r->vert_y - (int) r->vert_y;
			if (r->sx > 0)
				r->vert_w = 1 - r->vert_w;
		}
		else
		{
			r->vert_dist = INFINITY;
			break ;
		}
		if ((int)r->vert_x >= 0 && (int)r->vert_x < game->map.width && (int)r->vert_y >= 0 && (int)r->vert_y < game->map.height)
		{
			if (game->map.map[(int)r->vert_y][(int)r->vert_x + (r->sx - 1) / 2] == '1')
				break ;
			else
				r->vert_x += r->sx;
		}
		else
			break ;
	}
}

*/

void	dist_to_vert_grid_lines(t_game *game, t_ray *r)
{
	if (r->sx != 0)
	{
		r->vert_y = game->player.pos_y + r->dy / r->dx * (r->vert_x - game->player.pos_x);
		r->vert_dist = sqrt(pow(game->player.pos_x - r->vert_x, 2.0) + pow(game->player.pos_y - r->vert_y, 2.0));
		r->vert_w = r->vert_y - (int) r->vert_y;
		if (r->sx > 0)
			r->vert_w = 1 - r->vert_w;
	}
	else
		r->vert_dist = INFINITY;
}

/*

void	dist_to_hor_grid_lines(t_game *game, t_ray *r)
{
	while (1)
	{
		if (r->sy != 0)
		{
			r->hor_x = game->player.pos_x + (r->dx / r->dy) * (r->hor_y - game->player.pos_y);
			r->hor_dist = sqrt(pow(game->player.pos_x - r->hor_x, 2.0) + pow(game->player.pos_y - r->hor_y, 2.0));
			r->hor_w = r->hor_x - (int) r->hor_x;
			if (r->sy < 0)
				r->hor_w = 1 - r->hor_w;
		}
		else
		{
			r->hor_dist = INFINITY;
			break ;
		}
		if (game->map.map[(int)r->hor_y + (r->sy - 1) / 2][(int)r->hor_x] == '1')
			break ;
		else
			r->hor_y += r->sy;
	}
}

*/

void	dist_to_hor_grid_lines(t_game *game, t_ray *r)
{
	if (r->sy != 0)
	{
		r->hor_x = game->player.pos_x + r->dx / r->dy * (r->hor_y - game->player.pos_y);
		r->hor_dist = sqrt(pow(game->player.pos_x - r->hor_x, 2.0) + pow(game->player.pos_y - r->hor_y, 2.0));
		r->hor_w = r->hor_x - (int) r->hor_x;
		if (r->sy < 0)
			r->hor_w = 1 - r->hor_w;
	}
	else
		r->hor_dist = INFINITY;
}

/*

float	cast_ray(t_game *game, float v)
{
	t_ray	r;

	// ft_ray_initial_calculations(game, &r, v);
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
		return (ft_save_color(game, r.vert_dist, r.sx + 1, r.vert_w));
	else
		return (ft_save_color(game, r.hor_dist, r.sy + 2, r.hor_w));
}

*/

float	cast_ray(t_game *game, float v)
{
	t_ray	r;

	ray_start_calcs(game, &r, v);
	while (1)
	{
		dist_to_vert_grid_lines(game, &r);
		dist_to_hor_grid_lines(game, &r);
		if (r.vert_dist < r.hor_dist)
		{
			if (game->map.map[(int)r.vert_y][(int)r.vert_x + (r.sx - 1) / 2] == '1')
				return (get_color(game, r.vert_dist, r.sx + 1, r.vert_w));
			else
				r.vert_x += r.sx;
		}
		else
		{
			if (game->map.map[(int)r.hor_y + (r.sy - 1) / 2][(int)r.hor_x] == '1')
				return (get_color(game, r.hor_dist, r.sy + 2, r.hor_w));
			else
				r.hor_y += r.sy;
		}
	}
}

/*

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
				return (ft_save_color(game, r.vert_dist, r.sx + 1, r.vert_w));
			else
				r.vert_x += r.sx;
		}
		else
		{
			if (game->map.map[(int)r.hor_y + (r.sy - 1) / 2][(int)r.hor_x] == '1')
				return (ft_save_color(game, r.hor_dist, r.sy + 2, r.hor_w));
			else
				r.hor_y += r.sy;
		}
	}
}

*/











/* 
void	draw_map(t_game *game)
{
	int		i;
	double	camera_x;
	t_coord	distance;

	i = -1;
	while (++i < SCREEN_WIDTH)
	{
		camera_x = 2 * i / (double)SCREEN_WIDTH - 1;
		game->ray.x = game->player.dir_x + game->plane_x * camera_x;
		game->ray.y = game->player.dir_y + game->plane_y * camera_x;
		if (game->ray.x == 0)
			game->ray.delta_x = 1e30; // increment which sums up to distance to the wall
		else
			game->ray.delta_x = fabs(1 / game->ray.x); // increment
		if (game->ray.y == 0)
			game->ray.delta_y = 1e30; // increment
		else
			game->ray.delta_y = fabs(1 / game->ray.y); // increment
		distance = dda(game);
		if (game->wall.side == EA || game->wall.side == WE)
			// here distance.x is distance to vertical grid-line, i.e. hor distance
			// draw_lineof_texture(game, i, distance.x);
			draw_lineof_texture(game, i, distance.x - game->ray.delta_x);
		else
			// here distance.y is distance to horizontal grid-line, i.e. vert distance
			// draw_lineof_texture(game, i, distance.y);
			draw_lineof_texture(game, i, distance.y - game->ray.delta_y);
	}
}

 */


