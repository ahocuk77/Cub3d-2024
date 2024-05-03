/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 18:55:04 by musenov           #+#    #+#             */
/*   Updated: 2024/05/03 19:03:31 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"

/* Collision detection logic */
bool	collision_ahead(t_game *game, float angle, float dx, float dy)
{
	float	dist;

	dist = cast_ray(game, angle);
	if (dist * dist < dx * dx + dy * dy)
		return (true);
	return (false);
}

void	move(t_game *game, int direction, bool forwd)
{
	float		dx;
	float		dy;
	float		angle_offset;
	float		step;
	float		move_angle;

	angle_offset = direction * PI / 2;
	move_angle = game->player.view_angle - angle_offset;
	if (forwd)
		step = 0.06f;
	else
		step = 0.04f;
	dx = step * cos(move_angle);
	dy = step * sin(move_angle);
	if (collision_ahead(game, move_angle, dx, dy))
	{
		dx = 0.0f;
		dy = 0.0f;
	}
	game->player.pos_x += dx;
	game->player.pos_y -= dy;
}

void	*cursor_hook(double xpos, double ypos, t_game *game)
{
	(void)ypos;
	game->player.view_angle = - (PI * (xpos / WIN_W - 0.15));
	render(game);
	return (0);
}

void	keyboard_hooks(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(game->mlx);
		return ;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		move(game, 3, false);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		move(game, 2, true);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		move(game, 1, false);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		move(game, 0, true);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_UP))
		move(game, 0, true);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
		move(game, 2, true);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		game->player.view_angle += 0.003f * PI;
	else if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		game->player.view_angle -= 0.003f * PI;
	else
		return ;
	render(game);
}
