/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocuk <ahocuk@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:06:33 by ahocuk            #+#    #+#             */
/*   Updated: 2024/05/03 21:10:33 by ahocuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*trimreplace(char *str, char *set)
{
	char	*ret;

	ret = ft_strtrim(str, set);
	if (ret == NULL)
	{
		return (NULL);
	}
	free(str);
	return (ret);
}

int	is_numeric(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (-1);
		str++;
	}
	return (0);
}

char	*handle_color_num_error(t_game *game, int j)
{
	if (game->color.total_color_num > 3 || game->color.total_color_num < 3)
	{
		while (j < game->color.total_color_num)
			free(game->color.color_numb[j++]);
		return (NULL);
	}
	return ("");
}

size_t	ft_strlen2(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

int	path_check(char *path)
{
	int	fd;
	int	len;

	len = 0;
	while (path[len] != '\0')
		len++;
	if (path[len - 1] != '2' || path[len - 2] != '4' || path[len - 3] != 'm'
		|| path[len - 4] != 'p' || path[len - 5] != 'x' || path[len - 6] != '.')
	{
		ft_putendl_fd("wrong path!1\n", 2);
		return (-1);
	}
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_putendl_fd("wrong path!\n", 2);
		return (-1);
	}
	close(fd);
	return (0);
}
