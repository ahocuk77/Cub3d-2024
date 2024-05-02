/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:20:30 by ahocuk            #+#    #+#             */
/*   Updated: 2024/05/02 20:55:24 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;
	int		fd;

	if (argc != 2 || ft_cubcheck(argv[1]) == 1)
	{
		ft_putstr_fd("ERROR\n", 2);
		return (1);
	}
	ft_init(&game);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Wrong file\n", 2);
		return (1);
	}

	map_w(&game, fd);
	close(fd);
	fd = open(argv[1], O_RDONLY);

	parser(&game, fd);
	if (game.wall.texture_check == 1 || game.color.color_check == 1 \
									|| game.map.map_check == 1)
	{
		free_all(&game);
		return (1);
	}

	game.mlx = mlx_init(WIN_W, WIN_H, "cub3D", false);
	game.img = mlx_new_image(game.mlx, WIN_W, WIN_H);
	mlx_image_to_window(game.mlx, game.img, 0, 0);
	printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
	print_map(&game);
	printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");

	init_player(&game);
	render(&game);

	mlx_loop_hook(game.mlx, (void (*)(void *))keyboard_hooks, &game);
	mlx_cursor_hook(game.mlx, (void *)cursor_hook, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	free_all(&game);
	printf("%s\n", "cub3d closed");
	return (0);
}
