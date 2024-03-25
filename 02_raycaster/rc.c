/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:15:33 by musenov           #+#    #+#             */
/*   Updated: 2024/03/25 20:56:40 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

int	rgba_to_color(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	draw_background(t_game *game)
{
	int			x;
	int			y;
	int			color;

	color = rgba_to_color(39, 181, 245, 200);
	y = 0;
	while (y < WIN_H / 2)
	{
		x = 0;
		while (x < WIN_W)
		{
			mlx_put_pixel(game->img, x++, y, color);
		}
		y++;
	}
	color = rgba_to_color(6, 170, 85, 200);
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			mlx_put_pixel(game->img, x++, y, color);
		}
		y++;
	}
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

void	player_position(t_game *game) // rewrite
{
	int	x;
	int	y;
	int	len;

	y = -1;
	while (++y < game->height)
	{
		x = -1;
		len = ft_strlen(game->map.map[y]);
		while (++x < len)
		{
			if (game->map.map[y][x] == 'N' || game->map.map[y][x] == 'E' \
			|| game->map.map[y][x] == 'S' || game->map.map[y][x] == 'W')
			{
				game->player.pos.x = x;
				game->player.pos.y = y;
				return ;
			}
		}
	}
}

void	init_player_direction(t_game *game)
{
	if (game->dir == WE || game->dir == EA)
	{
		game->player.dir_y = 0.0;
		game->plane_x = 0.0;
		game->player.dir_x = -1.0;
		game->plane_y = -0.66;
		if (game->dir == EA)
		{
			game->player.dir_x = 1.0;
			game->plane_y = 0.66;
		}
	}
	else if (game->dir == NO || game->dir == SO)
	{
		game->player.dir_x = 0.0;
		game->plane_y = 0.0;
		game->player.dir_y = -1.0;
		game->plane_x = 0.66;
		if (game->dir == SO)
		{
			game->player.dir_y = 1.0;
			game->plane_x = -0.66;
		}
	}
	keypress_right_rotate(game);
}
