/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_texture.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocuk <ahocuk@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:52:16 by ahocuk            #+#    #+#             */
/*   Updated: 2024/03/20 20:10:17 by ahocuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int path_number_check(t_game *game, char *path)
{
	int i;
	int len;

	i =  0;
	len = 0;
	game->path[game->path_num] = ft_strdup(path);
	while(i < game->path_num)
	{
		len = ft_strlen(path);
		if(ft_strncmp(game->path[game->path_num], game->path[i], len) == 0)
		{
			game->path_num++;
			return (-1);	
		}
		i++;
	}
	game->path_num++;
	return(0);
}

int path_check(char *path)
{
	int fd;
	int len;

	len = 0;
	while (path[len] != '\0')
		len++;
	if (path[len - 1] != '2' || path[len - 2] != '4' || path[len - 3] != 'm'
		|| path[len - 4] != 'p' || path[len - 5] != 'x' || path[len - 6] != '.')
	{
		ft_putendl_fd("wrong path!1\n", 2);
		return -1;
	}
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_putendl_fd("wrong path!\n", 2);
		return -1;
	}
	close(fd);
	return 0;
}

char	*t_valid_check(t_game *game, char *str)
{
	char *path;

	if(ft_strncmp(str, "NO", 2) == 0)
		game->texture_num[NO]++;
	else if(ft_strncmp(str, "SO", 2) == 0)
		game->texture_num[SO]++;
	else if(ft_strncmp(str, "WE", 2) == 0)
		game->texture_num[WE]++;
	else if(ft_strncmp(str, "EA", 2) == 0)
		game->texture_num[EA]++;
	else
	{
		ft_putendl_fd("wrong direction or missing direction!\n", 2);
		return NULL;
	}
	if(game->texture_num[NO] >1 || game->texture_num[SO] >1 
		||game->texture_num[WE] >1 || game->texture_num[EA] >1)
			return NULL;
	path = str + 2;
	while(*path == ' ' || *path == '\t')
		path++;
	if(path_check(path) != -1)
		return(path);
	return NULL;
}


int put_texture(t_game *game, char *str, char *path)
{
	path = t_valid_check(game, str);
	if(path == NULL)
		return -1;
	if(path == NULL || path_number_check(game, path) == -1)
	{
		if(path == NULL && game->path_num != 0)

			printf("%s\n", "path error");
		return(-1);
	}
	if(ft_strncmp(str, "NO", 2) == 0)
	{
		game->wall.xpm[NO] = mlx_load_xpm42(path);
		game->wall.texture[NO] = game->wall.xpm[NO]->texture;
	}
	else if(ft_strncmp(str, "SO", 2) == 0)
	{
		game->wall.xpm[SO] = mlx_load_xpm42(path);
		game->wall.texture[SO] = game->wall.xpm[SO]->texture;
	}
	else if(ft_strncmp(str, "WE", 2) == 0)
	{
		game->wall.xpm[WE] = mlx_load_xpm42(path);
		game->wall.texture[WE] = game->wall.xpm[WE]->texture;
	}
	else
	{
		game->wall.xpm[EA] = mlx_load_xpm42(path);
		game->wall.texture[EA] = game->wall.xpm[EA]->texture;
	}
	return 0;
}

void	p_texture(t_game *game, int fd)
{
	char *str;
	char *path;

	path = NULL;
	str = NULL;
	free(str);
	while(1)
	{
		str = get_next_line(fd);
		str = trimreplace(str, " \t\n");
		if (ft_strlen(str) != 0 && put_texture(game, str, path) == -1)
		{
			game->texture_check = 1;
			return (free(str));
		}
		if (game->texture_num[NO] == 1 && game->texture_num[SO] == 1 
			&& game->texture_num[WE] == 1 && game->texture_num[EA] == 1)
		{
			free(str);
			break ;
		}
		free(str);
	}
}

