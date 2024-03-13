/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocuk <ahocuk@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:00:34 by ahocuk            #+#    #+#             */
/*   Updated: 2024/03/13 20:52:38 by ahocuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	parser(t_game *game, int fd)
{
	p_texture(game, fd);
	if(game->texture_check == 1)
	{
		close(fd);
		return ;
	}
	p_color(game, fd);
	if(game->color_check == 1)
	{
		close(fd);
		return ;
	}	
	close(fd);
}