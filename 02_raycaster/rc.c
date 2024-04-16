/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:15:33 by musenov           #+#    #+#             */
/*   Updated: 2024/04/16 20:21:53 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

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

void	find_view_angle(t_game *game, const char c)
{
	if (c == 'E')
		game->player.view_angle = 0.0f * M_PI;
	else if (c == 'N')
		game->player.view_angle = 0.5f * M_PI;
	else if (c == 'W')
		game->player.view_angle = 1.0f * M_PI;
	else if (c == 'S')
		game->player.view_angle = -0.5f * M_PI;
}

void	init_player(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.height)
	{
		j = -1;
		while (game->map.map[i][++j])
		{
			if (ft_strchr("NSWE", game->map.map[i][j]))
			{
				game->player.pos_x = (float) j + 0.5f;
				game->player.pos_y = (float) i + 0.5f;
				find_view_angle(game, game->map.map[i][j]);
				return ;
			}
		}
	}
}




/*


void	draw_lineof_texture(t_game *game, int col, double wall_distance)
{
	t_draw	draw;

	draw.line_height = (int)(SCREEN_HEIGHT / wall_distance);
	draw.start = (SCREEN_HEIGHT / 2) - (draw.line_height / 2);
	draw.end = (draw.line_height / 2) + (SCREEN_HEIGHT / 2);
	
	if (game->wall.side == WE || game->wall.side == EA)
		draw.wall_x = game->player.y + wall_distance * game->ray.y;
	else
		draw.wall_x = game->player.x + wall_distance * game->ray.x;
	
	draw.wall_x -= floor(draw.wall_x);
	draw.text_x = (int)(draw.wall_x * \
	(double)game->wall.texture[game->wall.side].width);
	draw.text_y = 0;
	draw.text_step = (double)game->wall.texture[game->wall.side].height / \
	(double)draw.line_height;
	if (draw.start < 0)
		draw.text_y = fabs((double)draw.start) * draw.text_step;
	draw_column(game, &draw, col);
}





void	draw_column(t_game *game, t_draw *draw, int col)
{
	unsigned int	color;
	int				t;
	uint8_t			*pixel;
	int				num;

	t = -1;
	while (++t < SCREEN_HEIGHT)
	{
		if (t >= draw->start && t <= draw->end && \
		draw->text_y < game->wall.texture[game->wall.side].height)
		{
			num = game->wall.texture[game->wall.side].width * 4 * \
			(int)draw->text_y + (int)draw->text_x * 4;
			pixel = &game->wall.texture[game->wall.side].pixels[num];
			color = ft_pixel(pixel[0], pixel[1], pixel[2], pixel[3]);
			mlx_put_pixel(game->img, col, t, color);
			draw->text_y += draw->text_step;
		}
		else if (t < draw->start)
			mlx_put_pixel(game->img, col, t, \
			ft_pixel(game->c_color.r, game->c_color.g, game->c_color.b, 255));
		else if (t > draw->end)
			mlx_put_pixel(game->img, col, t, \
			ft_pixel(game->f_color.r, game->f_color.g, game->f_color.b, 255));
	}
}



*/
