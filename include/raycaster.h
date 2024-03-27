/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:19:38 by musenov           #+#    #+#             */
/*   Updated: 2024/03/27 15:11:13 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTER_H
# define RAYCASTER_H

# include "common.h"

// rc.c
int		rgba_to_color(int32_t r, int32_t g, int32_t b, int32_t a);
void	draw_background(t_game *game);
void	print_map(t_game *game);
void	find_view_angle(t_game *game, const char c);
void	init_player(t_game *game);

// rc1.c



#endif
