/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:19:38 by musenov           #+#    #+#             */
/*   Updated: 2024/05/02 22:27:54 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include "common.h"

// 00_init_player.c

void	find_view_angle(t_game *game, const char c);
void	init_player(t_game *game);

// 01_render.c

void	draw_background(t_game *game);
void	draw_line(t_game *game, int col, float dist);
void	draw_lines(t_game *game);
void	render(t_game *game);

void	preliminary_calcs(t_draw *draw, t_game *game, float dist);

// 02_cast_ray.c

// void	ft_ray_initial_calculations(t_game *game, t_ray *r, float v);
void	ray_start_calcs(t_game *game, t_ray *r, float v);
// void	ft_ray_next_step_calculation(t_game *game, t_ray *r);
float	get_color(t_game *game, float dist, int color_idx, float w);
void	dist_to_vert_grid_lines(t_game *game, t_ray *r);
void	dist_to_hor_grid_lines(t_game *game, t_ray *r);
float	cast_ray(t_game *game, float v);

void	calculate_dist_to_hor_grid_line(t_game *game, t_ray *r);
void	calculate_dist_to_vert_grid_line(t_game *game, t_ray *r);

// 03_hooks.c

void	move(t_game *game, int direction);
void	move_forw(t_game *game, int direction);
void	*cursor_hook(double xpos, double ypos, t_game *game);
void	keyboard_hooks(t_game *game);

bool	isCollisionAhead(t_game *game, float angle, float dx, float dy);

// utils.c

int		get_sign(float f);
int		rgba_to_color(int32_t r, int32_t g, int32_t b, int32_t a);
void	print_map(t_game *game);

#endif
