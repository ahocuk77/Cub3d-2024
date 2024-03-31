/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 19:23:46 by musenov           #+#    #+#             */
/*   Updated: 2024/03/27 19:03:30 by musenov          ###   ########.fr       */
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

# define WIN_W					640
# define WIN_H					480

# ifndef PI
#  define PI 3.141592
# endif

# ifndef FOV
#  define FOV 1.0471975512f
# endif






/////////////////////////// TEXTURES ///////////////////////////


typedef enum e_direction
{
	NO,
	SO,
	WE,
	EA,
}	t_direction;

typedef struct s_wall
{
	mlx_texture_t	texture[4];
	xpm_t			*xpm[4];
	int				texture_num[4];
	char			*path[4];
	int				path_num;
	int				texture_check;
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
	t_rgb				floor; // meder uses
	t_rgb				ceiling; // meder uses
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
	char	**map; // meder uses
	int		height; // meder uses
	int		width; // meder uses
	char	player; // player's direction - meder uses
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


/////////////////////////// GAME DATA ///////////////////////////


typedef struct s_game
{
	mlx_t				*mlx;
	mlx_image_t			*img;
	t_wall				wall;
	t_color				color;
	t_map				map;
	t_player			player;
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




/*


typedef enum e_dir
{
	NO,
	SO,
	WE,
	EA,
}	t_direction;

typedef struct s_wall
{
	mlx_texture_t	texture[4];
	xpm_t			*xpm[4];
}	t_wall;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_map
{
	char	**map;
	char	player;
	int		size;

}	t_map;

typedef struct s_player
{
	float	pos_x;
	float	pos_y;
	float	view_angle;
}	t_player;

typedef struct s_game
{
	int					height;
	int					width;
	int					len_width;
	int					len_height;
	mlx_image_t			*img;
	mlx_t				*mlx;
	int					texture_num[4];
	t_wall				wall;
	int					color_num;
	char				*path[4];
	int					path_num;
	t_rgb				f_color;
	t_rgb				c_color;
	int					f_color_num;
	int					c_color_num;
	int					total_color_num;
	char				*color_numb[3];
	int					color_check;
	int					texture_check;
	int					map_check;
	t_map				map;
	bool				new_line_checker;

	t_player			player;
}	t_game;


*/

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

#endif
