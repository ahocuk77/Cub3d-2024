/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocuk <ahocuk@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:20:30 by ahocuk            #+#    #+#             */
/*   Updated: 2024/03/25 14:17:06 by ahocuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char **argv)
{
	t_game game;
	int fd;	
	
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
	if(game.texture_check == 1 || game.color_check == 1 || game.map_check == 1)
	{
		free_all(&game);
		return 1;
	}
	//game.mlx = mlx_init(WIN_W, WIN_H, "cub3D", false);
	//game.img = mlx_new_image(game.mlx, WIN_W, WIN_H);

	free_all(&game);
	printf("%s\n", "cub3d closed");
	return (0);
}
