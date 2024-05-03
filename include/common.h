/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 19:23:46 by musenov           #+#    #+#             */
/*   Updated: 2024/05/03 19:09:40 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include "../lib/libft/libft.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"

# include <stdbool.h>
# include <math.h>
# include <fcntl.h>

# include <sys/time.h>

# define WIN_W					1200
# define WIN_H					500

# ifndef PI
#  define PI 3.141592
# endif

# ifndef FOV
#  define FOV 1.0472f
# endif

/////////////////////////// TEXTURES ///////////////////////////

typedef enum e_direction
{
	WE,
	NO,
	EA,
	SO,
}	t_direction;

typedef struct s_wall
{
	mlx_texture_t	texture[4];
	xpm_t			*xpm[4];
	int				texture_num[4];
	char			*path[4];
	int				path_num;
	int				texture_check;
	float			txt_w;
	int				txt_idx;

}	t_wall;

/////////////////////////// COLORS ///////////////////////////

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_color
{
	t_rgb				floor;
	t_rgb				ceiling;
	int					color_num;
	int					f_color_num;
	int					c_color_num;
	int					total_color_num;
	char				*color_numb[3];
	int					color_check;
}	t_color;

///////////////////////////    MAP    ///////////////////////////

typedef struct s_map
{
	char	**map;
	int		height;
	int		width;
	char	player;
	int		size;
	int		len_width;
	int		len_height;
	int		map_check;
	bool	new_line_checker;
}	t_map;

/////////////////////////// PLAYER DATA ///////////////////////////

typedef struct s_player
{
	float	pos_x;
	float	pos_y;
	float	view_angle;
}	t_player;

/////////////////////////// RAY DATA ///////////////////////////

typedef struct s_ray
{
	float	dx;
	float	dy;
	int		sx;
	int		sy;
	float	hor_x;
	float	hor_y;
	float	vert_x;
	float	vert_y;
	float	vert_dist;
	float	hor_dist;
	float	vert_w;
	float	hor_w;
}	t_ray;

/////////////////////////// GAME DATA ///////////////////////////

typedef struct s_game
{
	mlx_t				*mlx;
	mlx_image_t			*img;
	t_wall				wall;
	t_color				color;
	t_map				map;
	t_player			player;
	t_ray				ray;
}	t_game;

typedef struct s_draw
{
	int		line_height;
	int		start;
	int		end;
	int		text_x;
	double	text_y;
	double	wall_x;
	double	text_step;
}	t_draw;

#endif
