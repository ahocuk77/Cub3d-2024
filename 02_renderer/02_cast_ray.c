/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_cast_ray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:18:22 by musenov           #+#    #+#             */
/*   Updated: 2024/04/18 20:34:21 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"

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

float	ft_save_color(t_game *game, float dist, int color_idx, float w)
{
	game->wall.txt_idx = color_idx;
	if (game->wall.txt_idx == 0)
		printf("direction: NO, %d\n", NO);
	else if (game->wall.txt_idx == 1)
		printf("direction: SO, %d\n", SO);
	else if (game->wall.txt_idx == 2)
		printf("direction: WE, %d\n", WE);
	else if (game->wall.txt_idx == 3)
		printf("direction: EA, %d\n", EA);
	game->wall.txt_w = w;
	return (dist);
}

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
				// here u indicate which wall is hit
				// return (r.vert_dist);
			else
				r.vert_x += r.sx;
		}
		else
		{
			if (game->map.map[(int)r.hor_y + (r.sy - 1) / 2][(int)r.hor_x] == '1')
				return (ft_save_color(game, r.hor_dist, r.sy + 2, r.hor_w));
				// here u indicate which wall is hit
				// return (r.hor_dist);
			else
				r.hor_y += r.sy;
		}
	}
}








