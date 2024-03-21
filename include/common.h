/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 19:23:46 by musenov           #+#    #+#             */
/*   Updated: 2024/03/21 20:53:41 by musenov          ###   ########.fr       */
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

typedef enum e_dir
{
	NO,
	SO,
	WE,
	EA,
}	t_dir;

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

typedef struct s_game
{
	int			height;
	int			width;
	int			len;
	int			leng;
	mlx_image_t	*img;
	mlx_t		*mlx;
	int			texture_num[4];
	t_wall		wall;
	int			color_num;
	char		*path[4];
	int			path_num;
	t_rgb		f_color;
	t_rgb		c_color;
	int			f_color_num;
	int			c_color_num;
	int			total_color_num;
	char		*color_numb[3];
	int			color_check;
	int			texture_check;
	int			map_check;
	t_map		map;
	bool		new_line_checker;
}	t_game;

#endif
