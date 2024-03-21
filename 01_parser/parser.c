/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocuk <ahocuk@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:00:34 by ahocuk            #+#    #+#             */
/*   Updated: 2024/03/21 21:16:22 by ahocuk           ###   ########.fr       */
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
	printf("color%s\n", "enter");
	p_color(game, fd);
	if(game->color_check == 1)
	{
		close(fd);
		return ;
	}
	printf("color%s\n", "exit");
	p_map(game, fd);
	printf("map%s\n", "exit");
	if(game->map_check == 1)
	{
		close(fd);
		return ;
	}
	close(fd);
	//map_check(game);
}