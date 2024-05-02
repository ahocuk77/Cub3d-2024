/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:19:38 by musenov           #+#    #+#             */
/*   Updated: 2024/05/02 21:35:39 by musenov          ###   ########.fr       */
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

// utils.c

int		get_sign(float f);
int		rgba_to_color(int32_t r, int32_t g, int32_t b, int32_t a);
void	print_map(t_game *game);

#endif




/* void	draw_lineof_texture(t_game *game, int col, double wall_distance)
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