/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:19:38 by musenov           #+#    #+#             */
/*   Updated: 2024/05/03 18:31:39 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include "common.h"

// 00_init_player.c

void	init_player(t_game *game);
void	init_direction(t_game *game, char c);

// 01_render.c

void	draw_background(t_game *game);
void	preliminary_calcs(t_draw *draw, t_game *game, float dist);
void	draw_line_norminette_25_lines_requirement(t_game *game, int col, \
													t_draw *draw, int *h);
void	draw_line(t_game *game, int col, float dist);
void	draw_lines(t_game *game);

// 02_cast_ray_00.c

float	get_color(t_game *game, float dist, int color_idx, float w);
void	initialize_ray_direction_and_position(t_game *game, t_ray *r, float v);
float	cast_ray(t_game *game, float v);

// 02_cast_ray_01.c

void	dist_to_hor_grid_lines(t_game *game, t_ray *r);
void	calculate_dist_to_hor_grid_line(t_game *game, t_ray *r);
void	dist_to_vert_grid_lines(t_game *game, t_ray *r);
void	calculate_dist_to_vert_grid_line(t_game *game, t_ray *r);

// 03_hooks.c

bool	collision_ahead(t_game *game, float angle, float dx, float dy);
void	move(t_game *game, int direction, bool forwd);
void	*cursor_hook(double xpos, double ypos, t_game *game);
void	keyboard_hooks(t_game *game);

// utils.c

int		get_sign(float f);
int		rgba_to_color(int32_t r, int32_t g, int32_t b, int32_t a);
void	print_map(t_game *game);

// main.c

void	render(t_game *game);

#endif
