/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:18:22 by musenov           #+#    #+#             */
/*   Updated: 2024/04/15 19:43:37 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

int	ft_sign(float f)
{
	if (f < 0.0f)
	{
		if (f > -0.000001)
			return (0);
		else
			return (-1);
	}
	else
	{
		if (f < 0.000001f)
			return (0);
		else
			return (1);
	}
}

void	ft_ray_initial_calculations(t_game *game, t_ray *r, float v)
{
	r->dx = cos(v);
	r->dy = -sin(v);
	r->sx = ft_sign(r->dx);
	r->sy = ft_sign(r->dy);
	r->vert_x = (int) game->player.pos_x;
	if (r->sx > 0)
		r->vert_x += 1.0f;
	r->hor_y = (int) game->player.pos_y;
	if (r->sy > 0)
		r->hor_y += 1.0f;
}

void	ft_ray_next_step_calculation(t_game *game, t_ray *r)
{
	if (r->sx != 0)
	{
		r->vert_y = game->player.pos_y + r->dy / r->dx * (r->vert_x - game->player.pos_x);
		r->vert_dist = sqrt(pow(game->player.pos_x - r->vert_x, 2.0)
				+ pow(game->player.pos_y - r->vert_y, 2.0));
		r->vert_w = r->vert_y - (int) r->vert_y;
		if (r->sx > 0)
			r->vert_w = 1 - r->vert_w;
	}
	else
		r->vert_dist = INFINITY;
	if (r->sy != 0)
	{
		r->hor_x = game->player.pos_x + r->dx / r->dy * (r->hor_y - game->player.pos_y);
		r->hor_dist = sqrt(pow(game->player.pos_x - r->hor_x, 2.0)
				+ pow(game->player.pos_y - r->hor_y, 2.0));
		r->hor_w = r->hor_x - (int) r->hor_x;
		if (r->sy < 0)
			r->hor_w = 1 - r->hor_w;
	}
	else
		r->hor_dist = INFINITY;
}

static float	ft_save_color(t_game *game, float dist, int color_idx, float w)
{
	game->wall.txt_idx = color_idx;
	game->wall.txt_w = w;
	return (dist);
}

float	cast_ray(t_game *game, float v)
{
	t_ray	r;

	ft_ray_initial_calculations(game, &r, v);
	while (1)
	{
		ft_ray_next_step_calculation(game, &r);
		if (r.vert_dist < r.hor_dist)
		{
			if (game->map.map[(int)r.vert_y][(int)r.vert_x + (r.sx - 1) / 2] == '1')
				return (ft_save_color(game, r.vert_dist, r.sx + 1, r.vert_w));
				// here u indicate which wall is hit
				// return (r.vert_dist);
			else
				r.vert_x += r.sx;
		}
		else
		{
			if (game->map.map[(int)r.hor_y + (r.sy - 1) / 2][(int)r.hor_x] == '1')
				return (ft_save_color(game, r.hor_dist, r.sy + 2, r.hor_w));
				// here u indicate which wall is hit
				// return (r.hor_dist);
			else
				r.hor_y += r.sy;
		}
	}
}




/*


void	draw_line(t_game *game, int col, float dist)
{
	t_draw			draw;
	unsigned int	color;
	int				h;

	draw.line_height = (int)(WIN_H / dist);
	draw.start = (WIN_H / 2) - (draw.line_height / 2);
	draw.end = (draw.line_height / 2) + (WIN_H / 2);

	color = rgba_to_color(205, 127, 50, 255);
	h = 0;
	while (h < WIN_H)
	{
		if (h >= draw.start && h <= draw.end)
			mlx_put_pixel(game->img, col, h, color);
		h++;
	}
}


*/





void	draw_line(t_game *game, int col, float dist)
{
	t_draw			draw;
	unsigned int	color;
	int				h;
	// uint8_t			*pixel;
	unsigned int	*pixel;
	// int				num;
	unsigned int	*src;
	float			src_f;
	float			d_shift;
	
	
	draw.line_height = (int)(WIN_H / dist);
	draw.start = (WIN_H / 2) - (draw.line_height / 2);
	draw.end = (draw.line_height / 2) + (WIN_H / 2);


	src_f = 0.0f;
	d_shift = (float) game->wall.texture[game->wall.txt_idx].height / draw.line_height;
	if (draw.line_height > WIN_H)
	{
		src_f = 0.5f * (draw.line_height - WIN_H) / draw.line_height * game->wall.texture[game->wall.txt_idx].height;
		draw.line_height = WIN_H;
	}


	// color = rgba_to_color(205, 127, 50, 255);
	
	// continue from here and look at data structure t_wall

	src = (unsigned int *) &game->wall.texture[game->wall.txt_idx];
	src += (int)((float) game->wall.txt_w * game->wall.texture[game->wall.txt_idx].width);
	// *dst = *(src + ((int)src_f) * game->txt[game->txt_idx].width);
	h = 0;
	while (h < WIN_H)
	{
		if (h >= draw.start && h <= draw.end)
		{
			// pixel = &game->wall.texture[game->wall.side].pixels[num];
			pixel = src + ((int)src_f) * game->wall.texture[game->wall.txt_idx].width;
			color = rgba_to_color(pixel[0], pixel[1], pixel[2], pixel[3]);
			mlx_put_pixel(game->img, col, h, color);
			src_f += d_shift;

			// num = game->wall.texture[game->wall.side].width * 4 * \
			// (int)draw->text_y + (int)draw->text_x * 4;
			// pixel = &game->wall.texture[game->wall.side].pixels[num];
			// color = ft_pixel(pixel[0], pixel[1], pixel[2], pixel[3]);
			// mlx_put_pixel(game->img, col, h, color);
			// // mlx_put_pixel(game->img, col, t, color);
			// draw->text_y += draw->text_step;
		}
		h++;
	}
}






/* 


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


/* 
void	ft_line(t_game *game, int w, float dist)
{
	unsigned int	*dst;
	unsigned int	*src;
	unsigned int	h;
	float			src_f;
	float			d_shift;

	h = (float) WINDOW_H / dist;
	src_f = 0.0f;
	d_shift = (float) game->txt[game->txt_idx].height / h;
	if (h > WINDOW_H)
	{
		src_f = 0.5f * (h - WINDOW_H) / h * game->txt[game->txt_idx].height;
		h = WINDOW_H;
	}
	src = (unsigned int *) game->txt[game->txt_idx].addr;
	src += (int)((float) game->txt_w * game->txt[game->txt_idx].width);
	dst = (unsigned int *) game->img.addr + w + (WINDOW_H - h) / 2 * WINDOW_W;
	while (h-- > 0)
	{
		*dst = *(src + ((int)src_f) * game->txt[game->txt_idx].width);
		// *dst = game->txt_idx * 255 + (1 - game->txt_idx) * (255 << 8);
		dst += WINDOW_W;
		src_f += d_shift;
	}
}

 */


/* 

void	ft_ray_casting(t_game *game)
{
	int		x;
	float	dv;
	float	v;

	// v = game->view - FOV / 2;
	v = game->view + FOV / 2;
	dv = FOV / (WINDOW_W - 1);
	x = -1;
	while (++x < WINDOW_W)
	{
		ft_line(game, x, ft_ray(game, v) * cos(game->view - v)); // cos is for fish eye effect removal
		// v += dv;
		v -= dv;
	}
}
 */




/*

void	set_texture_values(t_game *game, char *str, char *path)
{
	if (ft_strncmp(str, "NO", 2) == 0)
	{
		game->wall.xpm[NO] = mlx_load_xpm42(path);
		game->wall.texture[NO] = game->wall.xpm[NO]->texture;
	}
	else if (ft_strncmp(str, "SO", 2) == 0)
	{
		game->wall.xpm[SO] = mlx_load_xpm42(path);
		game->wall.texture[SO] = game->wall.xpm[SO]->texture;
	}
	else if (ft_strncmp(str, "WE", 2) == 0)
	{
		game->wall.xpm[WE] = mlx_load_xpm42(path);
		game->wall.texture[WE] = game->wall.xpm[WE]->texture;
	}
	else
	{
		game->wall.xpm[EA] = mlx_load_xpm42(path);
		game->wall.texture[EA] = game->wall.xpm[EA]->texture;
	}
}

*/