/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:20:30 by ahocuk            #+#    #+#             */
/*   Updated: 2024/03/25 13:24:21 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init(t_game *game)
{
	game->c_color_num = 0;
	game->f_color_num = 0;
	game->total_color_num = 0;
	game->path_num = 0;
	game->texture_num[NO] = 0;
	game->texture_num[SO] = 0;
	game->texture_num[WE] = 0;
	game->texture_num[EA] = 0;
	game->map.size = 0;
	game->new_line_checker = false;
	game->height = 0;
}

int	ft_cubcheck(char *map)
{
	int	len;

	len = ft_strlen(map);
	if (map[len - 1] != 'b' || map[len - 2] != 'u'
		|| map[len - 3] != 'c' || map[len - 4] != '.')
		return (1);
	else
		return (0);
}

void	leaks(void)
{
	system("leaks cub3D");
}

void	free_all(t_game *game)
{
	int i;

	i = 0;

	printf("%s\n", "memory free start");
	while(i < game->path_num)
	{
		printf("%s\n", game->path[i]);
		free(game->path[i]);
		i++;
	}
	i = 0;
	if(game->path_num < 4 && game->path_num != 0)
	{
		while(i < game->path_num -1)
		{
			mlx_delete_xpm42(game->wall.xpm[i]);
			i++;
		}
		mlx_delete_xpm42(game->wall.xpm[i]);
	}
	else
	{
		while(i < game->path_num)
		{
			mlx_delete_xpm42(game->wall.xpm[i]);
			i++;
		}
	}
	printf("%s\n", "walls deleted");
	i = 0;
	if(game->map.map == NULL)
		return;
	while(game->map.map[i] != NULL)
	{
		free(game->map.map[i]);
		i++;

		printf("%s\n", "map deleted");
		if(game->map.map[i] == NULL)
			free(game->map.map);
	}

}

/*

int main(int argc, char **argv)
{
	t_game game;
	int fd;	
	
	//atexit(&leaks);
	if(argc != 2 || ft_cubcheck(argv[1]) == 1)
	{
		ft_putstr_fd("ERROR\n", 2);
		return 1;
	}
	ft_init(&game);
	fd = open(argv[1], O_RDONLY);
	if(fd < 0)
	{
		ft_putstr_fd("Wrong file\n", 2);
		return 1;
	}
	parser(&game, fd);
	if(game.texture_check == 1 || game.color_check == 1)
	{
		free_all(&game);
		return 1;
	}

	free_all(&game);
	printf("%s\n", "cub3d closed");
	return (0);
}

*/

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
			// printf ("%d", game->map.map[i][j]);
			ft_putchar_fd(game->map.map[i][j], 1);
			j++;
		}
		printf("\n");
		i++;
	}
}

int main(int argc, char **argv)
{
	t_game				game;
	int					fd;

	if(argc != 2 || ft_cubcheck(argv[1]) == 1)
	{
		ft_putstr_fd("ERROR\n", 2);
		return 1;
	}
	ft_init(&game);
	fd = open(argv[1], O_RDONLY);
	if(fd < 0)
	{
		ft_putstr_fd("Wrong file\n", 2);
		return 1;
	}
	parser(&game, fd);
	if(game.texture_check == 1 || game.color_check == 1)
	{
		free_all(&game);
		return 1;
	}
	game.mlx = mlx_init(WIN_W, WIN_H, "cub3D", false);
	game.img = mlx_new_image(game.mlx, WIN_W, WIN_H);
	mlx_image_to_window(game.mlx, game.img, 0, 0);
	draw_background(&game);
	print_map(&game);
	// open_map_file(&game, check_argv(argv));
	// player_position(&game);
	// init_player_direction(&game);
	// draw(game);
	// mlx_loop_hook(game.mlx, (void (*)(void *))ft_hooks0, &game);
	// mlx_scroll_hook(game.mlx, (mlx_scrollfunc)ft_scroll, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	free_all(&game);
	printf("%s\n", "cub3d closed");
	return (0);
}

/*

t_render_exit_code	start_render(t_cub *data)
{
	data->mlx = mlx_init(WIDTH, HEIGHT, "Cub21", true);
	if (!data->mlx)
		return (render_error_print(MLX_CANNOT_INIT));
	if (wall_texture_load(data->wall_tex, data->map_data.wall))
		return (render_error_print(TEXTURE_CANNOT_LOAD));
	if (wall_is_square(data->wall_tex))
		return (render_error_print(TEXTURE_NOT_SQUARE));
	if (wall_larger_than_tile(data->wall_tex))
		return (render_error_print(TEXTURE_SMALLER_THAN_TILE));
	data->g_img_full = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->g_img_full)
		return (render_error_print(IMG_CANNOT_CREATE));
	if (mlx_image_to_window(data->mlx, data->g_img_full, 0, 0))
		return (render_error_print(IMG_CANNOT_DISPLAY));
	render(data->g_img_full, data, 0);
	mlx_loop_hook(data->mlx, (void (*)(void *))hook, data);
	mlx_loop(data->mlx);
	return (RENDER_SUCCESS);
}

*/

/*

void	ft_hooks0(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		default_map(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		default_map(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		default_map(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		default_map(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP))
		game->shift_y -= 20;
	if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
		game->shift_y += 20;
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		game->shift_x -= 20;
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		game->shift_x += 20;
	ft_memset(game->img->pixels, 0, WIN_W * WIN_H * BPP);
	draw(game);
}

*/

/*

int	main(int argc, char **argv)
{
	t_fdf		*data;
	int			fd;

	check_file(argc, argv[1], &fd);
	data = (t_fdf *)malloc(sizeof(t_fdf));
	data->mlx = mlx_init(WIDTH, HEIGHT, argv[1], true); ////////
	read_file(argv[1], data, fd);
	mem_alloc(data);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT); //////////////
	mlx_image_to_window(data->mlx, data->img, 0, 0); /////////////////
	print_map(data);
	default_map(data);
	draw(data); /////////////////////////////////
	mlx_loop_hook(data->mlx, (void (*)(void *))ft_hooks0, data); ////////
	mlx_loop_hook(data->mlx, (void (*)(void *))ft_hooks1, data);
	mlx_loop_hook(data->mlx, (void (*)(void *))ft_hooks2, data);
	mlx_scroll_hook(data->mlx, (mlx_scrollfunc)ft_scroll, data); /////////
	mlx_loop(data->mlx); ////////////////////
	mlx_terminate(data->mlx); ///////////////
	free_all(data);
	system("leaks fdf");
	return (0);
}

*/
