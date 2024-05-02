/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 18:55:04 by musenov           #+#    #+#             */
/*   Updated: 2024/05/02 22:27:35 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"

/* void	move(t_game *game, int direction)
{
	float	dist;
	float	dx;
	float	dy;
	float	angle;

	angle = game->player.view_angle - direction * M_PI / 2;
	dx = LINEAR_STEP_SIDE * cos(angle);
	dy = LINEAR_STEP_SIDE * sin(angle);
	dist = cast_ray(game, get_sign(dy) * M_PI / 2);
	if (dist * dist < dy * dy)
		dy = 0.0f;
	dist = cast_ray(game, (1 - (get_sign(dx) + 1) / 2) * M_PI);
	if (dist * dist < dx * dx)
		dx = 0.0f;
	dist = cast_ray(game, angle);
	if (dist * dist < dy * dy + dx * dx)
		if (get_sign(dy) * get_sign(dx) != 0)
			dy = 0.0f;
	game->player.pos_x += dx;
	game->player.pos_y -= dy;
} */




bool isCollisionAhead(t_game *game, float angle, float dx, float dy) {
	// Collision detection logic.

	// Check direct path.
	float dist = cast_ray(game, angle);
	if (dist * dist < dx * dx + dy * dy) {
		return true;
	}

	// Additional checks can be performed here if needed for walls or obstacles.

	return false;
}





void move(t_game *game, int direction) {
	// Constants for angle adjustment and movement.
	const float angleOffset = direction * M_PI / 2;
	const float stepSize = LINEAR_STEP_SIDE;

	// Calculate the new movement angle.
	float moveAngle = game->player.view_angle - angleOffset;

	// Calculate movement deltas using the movement angle.
	float dx = stepSize * cos(moveAngle);
	float dy = stepSize * sin(moveAngle);

	// Perform collision detection in the movement direction.
	if (isCollisionAhead(game, moveAngle, dx, dy)) {
		dx = 0.0f;
		dy = 0.0f;
	}

	// Update player position.
	game->player.pos_x += dx;
	game->player.pos_y -= dy;  // Note: Consider coordinate system orientation.
}





void	move_forw(t_game *game, int direction)
{
	float	dist;
	float	dx;
	float	dy;
	float	angle;

	angle = game->player.view_angle - direction * M_PI / 2;
	dx = LINEAR_STEP_FORW * cos(angle);
	dy = LINEAR_STEP_FORW * sin(angle);
	dist = cast_ray(game, get_sign(dy) * M_PI / 2);
	if (dist * dist < dy * dy)
		dy = 0.0f;
	dist = cast_ray(game, (1 - (get_sign(dx) + 1) / 2) * M_PI);
	if (dist * dist < dx * dx)
		dx = 0.0f;
	dist = cast_ray(game, angle);
	if (dist * dist < dy * dy + dx * dx)
		if (get_sign(dy) * get_sign(dx) != 0)
			dy = 0.0f;
	game->player.pos_x += dx;
	game->player.pos_y -= dy;
}

void	*cursor_hook(double xpos, double ypos, t_game *game)
{
	(void)ypos;
	game->player.view_angle = - (M_PI * (xpos / WIN_W - 0.35));
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
		move(game, 3);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		move_forw(game, 2);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		move(game, 1);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		move_forw(game, 0);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_UP))
		move_forw(game, 0);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
		move_forw(game, 2);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		game->player.view_angle += ANGLE_STEP * M_PI;
	else if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		game->player.view_angle -= ANGLE_STEP * M_PI;
	else
		return ;
	render(game);
}
