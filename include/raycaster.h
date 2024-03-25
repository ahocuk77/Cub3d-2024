/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:19:38 by musenov           #+#    #+#             */
/*   Updated: 2024/03/25 20:24:44 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTER_H
# define RAYCASTER_H

# include "common.h"

int		rgba_to_color(int32_t r, int32_t g, int32_t b, int32_t a);
void	draw_background(t_game *game);
void	print_map(t_game *game);
void	player_position(t_game *game);

#endif
