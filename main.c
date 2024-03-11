/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocuk <ahocuk@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:20:30 by ahocuk            #+#    #+#             */
/*   Updated: 2024/03/11 20:56:50 by ahocuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_init(t_game *game)
{
	game->texture_num[NO] = 0;
	game->texture_num[SO] = 0;
	game->texture_num[WE] = 0;
	game->texture_num[EA] = 0;
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
int main(int argc, char **argv)
{
	t_game game;
	int fd;	
	
	atexit(&leaks);
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
	//game.mlx = mlx_init(WIN_W, WIN_H, "cub3D", false);
	//game.img = mlx_new_image(game.mlx, WIN_W, WIN_H);
	mlx_delete_xpm42(game.wall.xpm[0]);
	mlx_delete_xpm42(game.wall.xpm[1]);
	mlx_delete_xpm42(game.wall.xpm[2]);
	mlx_delete_xpm42(game.wall.xpm[3]);
	printf("%s\n", "cub3d closed");
	return (0);
}