/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocuk <ahocuk@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:20:43 by ahocuk            #+#    #+#             */
/*   Updated: 2024/03/13 15:29:39 by ahocuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <sys/time.h>
# include <fcntl.h>

# define WIN_W					1920
# define WIN_H					1080

typedef enum e_dir
{
	NO,
	SO,
	WE,
	EA,
}t_dir;

typedef struct s_wall
{
	mlx_texture_t	texture[4];
	xpm_t			*xpm[4];
}t_wall;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}t_rgb;


typedef struct s_game 
{
	mlx_image_t	*img;
	mlx_t		*mlx;
	int			texture_num[4];
	t_wall		wall;
	int			color_num;
	char 		*path[4];
	int 		path_num;
	t_rgb		f_color;
	t_rgb		c_color;
	int			f_color_num;
	int			c_color_num;
	int			total_color_num;
	char		*color_numb[3];
	int			color_check;
	int			texture_check;
	

}				t_game;

int	ft_cubcheck(char *map);
int main(int argc, char **argv);
void	parser(t_game *game, int fd);
void	p_texture(t_game *game, int fd);
char	*trimreplace(char *str, char *set);
void	p_color(t_game *game, int fd);
char	**ft_split_custom(char *s);

#endif