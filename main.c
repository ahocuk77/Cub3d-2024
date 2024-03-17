/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocuk <ahocuk@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:20:30 by ahocuk            #+#    #+#             */
/*   Updated: 2024/03/17 18:30:29 by ahocuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_init(t_game *game)
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

	while(i < game->path_num)
	{
		free(game->path[i]);
		i++;
	}
	mlx_delete_xpm42(game->wall.xpm[0]);
	mlx_delete_xpm42(game->wall.xpm[1]);
	mlx_delete_xpm42(game->wall.xpm[2]);
	mlx_delete_xpm42(game->wall.xpm[3]);
	i = 0;
	while(game->map.map[i] != NULL)
	{
		free(game->map.map[i]);
		i++;
		if(game->map.map[i] == NULL)
			free(game->map.map);
	}

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
	if(game.texture_check == 1 || game.color_check == 1)
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