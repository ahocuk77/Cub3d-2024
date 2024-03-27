/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:40:09 by ahocuk            #+#    #+#             */
/*   Updated: 2024/03/27 15:44:20 by musenov          ###   ########.fr       */
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

# define WIN_W					1920
# define WIN_H					1080

# ifndef PI
#  define PI 3.141592
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



typedef struct s_position
{
	int			x;
	int			y;
}	t_position;

typedef struct s_player
{
	int		pos_x;
	int		pos_y;
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

#endif
