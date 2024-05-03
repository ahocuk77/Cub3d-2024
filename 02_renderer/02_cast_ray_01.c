/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_cast_ray_01.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:39:33 by musenov           #+#    #+#             */
/*   Updated: 2024/05/03 15:20:28 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"

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
			r->vert_dist = 1e20;
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
			r->vert_dist = 1e20;
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
			r->hor_dist = 1e20;
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
			r->hor_dist = 1e20;
			break ;
		}
	}
}
