/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:44:07 by musenov           #+#    #+#             */
/*   Updated: 2024/05/02 22:09:57 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"

int	get_sign(float f)
{
	if (f < -0.001f)
		return (-1);
	else if (f > 0.001f)
		return (1);
	else
		return (0);
}

int	rgba_to_color(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	print_map(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (game->map.map[i])
	{
		j = 0;
		while (game->map.map[i][j])
		{
			ft_putchar_fd(game->map.map[i][j], 1);
			j++;
		}
		printf("\n");
		i++;
	}
}
