/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_color.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocuk <ahocuk@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:06:47 by ahocuk            #+#    #+#             */
/*   Updated: 2024/05/04 19:02:08 by ahocuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*take_color(t_game *game, char *str)
{
	char	**str_new;
	char	*fr;
	int		j;

	j = 0;
	str = str + 2;
	while (*str == ' ' || *str == '\t')
		str++;
	str_new = ft_split_custom(str);
	while (str_new[game->color.total_color_num] != NULL)
	{
		fr = str_new[game->color.total_color_num];
		if (is_numeric(fr) == -1 || ft_atoi(fr) == 0)
			return (handle_color_num_error2(game, j, str_new));
		if (game->color.total_color_num < 3)
			game->color.color_numb[game->color.total_color_num] = ft_strdup(fr);
		game->color.total_color_num++;
	}
	while (str_new[j] != NULL)
		free (str_new[j++]);
	free (str_new);
	j = 0;
	if (handle_color_num_error(game, j) == NULL)
		return (NULL);
	return (str);
}

char	*c_valid_check(t_game *game, char *str)
{
	int	i;

	i = 0;
	if (ft_strncmp(str, "F", 1) == 0)
		game->color.f_color_num++;
	else if (ft_strncmp(str, "C", 1) == 0)
		game->color.c_color_num++;
	else
		return (NULL);
	if (str[1] != ' ' && str[1] != '\t')
	{
		ft_putendl_fd("ERROR: Invalid format\n", 2);
		return (NULL);
	}
	if (game->color.c_color_num > 1 || game->color.f_color_num > 1)
		return (NULL);
	if (take_color(game, str) == NULL)
		return (NULL);
	game->color.total_color_num = 0;
	while (i < 3 && game->color.color_numb[i] != NULL)
		if (ft_atoi(game->color.color_numb[i++]) > 255)
			return (str + 2);
	return (str);
}

void	set_color_values(t_game *game, int dst)
{
	if (dst == 0)
	{
		game->color.floor.r = ft_atoi(game->color.color_numb[0]);
		game->color.floor.g = ft_atoi(game->color.color_numb[1]);
		game->color.floor.b = ft_atoi(game->color.color_numb[2]);
	}
	else
	{
		game->color.ceiling.r = ft_atoi(game->color.color_numb[0]);
		game->color.ceiling.g = ft_atoi(game->color.color_numb[1]);
		game->color.ceiling.b = ft_atoi(game->color.color_numb[2]);
	}
}

int	put_color(t_game *game, char *str)
{
	char	*result;

	result = c_valid_check(game, str);
	if (result == NULL)
		return (-1);
	else if (result == str + 2)
	{
		free(game->color.color_numb[0]);
		free(game->color.color_numb[1]);
		free(game->color.color_numb[2]);
		return (-1);
	}
	if (ft_strncmp(str, "F", 1) == 0)
		set_color_values(game, 0);
	else
		set_color_values(game, 1);
	free(game->color.color_numb[0]);
	free(game->color.color_numb[1]);
	free(game->color.color_numb[2]);
	return (0);
}

void	p_color(t_game *game, int fd)
{
	char	*str;

	str = NULL;
	free(str);
	while (1)
	{
		str = get_next_line(fd);
		str = trimreplace(str, " \t\n");
		if (ft_strlen(str) != 0 && put_color(game, str) == -1)
		{
			printf("String: %s\n", "put color error");
			game->color.color_check = 1;
			free(str);
			break ;
		}
		if (game->color.c_color_num == 1 && game->color.f_color_num == 1)
		{
			free(str);
			break ;
		}
		free(str);
	}
}
