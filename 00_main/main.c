/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:20:30 by ahocuk            #+#    #+#             */
/*   Updated: 2024/03/25 21:07:19 by musenov          ###   ########.fr       */
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
	parser(&game, fd);
	if (game.texture_check || game.color_check || game.map_check)
	{
		free_all(&game);
		return (1);
	}
	game.mlx = mlx_init(WIN_W, WIN_H, "cub3D", false);
	game.img = mlx_new_image(game.mlx, WIN_W, WIN_H);
	mlx_image_to_window(game.mlx, game.img, 0, 0);
	draw_background(&game);
	printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
	print_map(&game);
	printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
	player_position(&game);
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


