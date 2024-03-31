/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:19:38 by musenov           #+#    #+#             */
/*   Updated: 2024/03/31 18:46:52 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTER_H
# define RAYCASTER_H

# include "common.h"

// rc.c

int		rgba_to_color(int32_t r, int32_t g, int32_t b, int32_t a);
void	print_map(t_game *game);
void	find_view_angle(t_game *game, const char c);
void	init_player(t_game *game);

// rc1.c

int		ft_sign(float f);
void	ft_ray_initial_calculations(t_game *game, t_ray *r, float v);
void	ft_ray_next_step_calculation(t_game *game, t_ray *r);
float	cast_ray(t_game *game, float v);
void	draw_line(t_game *game, int col, float dist);

// rc2.c

void	draw_background(t_game *game);
void	draw_lines(t_game *game);
void	render(t_game *game);





#endif
