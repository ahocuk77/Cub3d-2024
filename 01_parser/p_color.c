/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_color.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocuk <ahocuk@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:06:47 by ahocuk            #+#    #+#             */
/*   Updated: 2024/03/21 13:44:41 by ahocuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int is_numeric(char *str)
{
    while (*str)
	{
        if (*str < '0' || *str > '9')
            return -1;
        str++;
    }
    return 0;
}

char *take_color(t_game *game, char *str)
{
	char **str_new;
	char *first;
	int 	j;

	j = 0;
	str = str + 2;
	while(*str == ' ' || *str == '\t')
		str++;
	str_new = ft_split_custom(str);
	while(str_new[game->total_color_num] != NULL)
	{
		first = str_new[game->total_color_num];
		if(is_numeric(first) == -1 || ft_atoi(first) == 0)
			game->total_color_num = 10000;
		if(game->total_color_num < 3)
			game->color_numb[game->total_color_num] = ft_strdup(first); 
		game->total_color_num++;
	}
	while (str_new[j] != NULL)
		free (str_new[j++]);
	free (str_new);
	j = 0;
	if(game->total_color_num > 3 || game->total_color_num < 3) // updated
	{
		while(j < game->total_color_num)
			free(game->color_numb[j++]);
		return NULL;
	}
	game->total_color_num = 0;
	return (str);
}

char	*c_valid_check(t_game *game, char *str)
{
	int i;

	i = 0;
	if(ft_strncmp(str, "F", 1) == 0)
		game->f_color_num++;
	else if(ft_strncmp(str, "C", 1) == 0)
		game->c_color_num++;
	else
	{
		ft_putendl_fd("ERROR\n", 2);
		return NULL;
	}
    if (str[1] != ' ' && str[1] != '\t')
    {
        ft_putendl_fd("ERROR: Invalid format\n", 2);
        return NULL;
    }
	printf("test0: %s\n", str);
	if(game->c_color_num > 1 || game->f_color_num > 1)
		return NULL;
	if (take_color(game, str) == NULL)
		return NULL;
	printf("test1: %s\n", str);
	while(game->color_numb[i] != NULL)
		if(ft_atoi(game->color_numb[i++]) > 255)
		{
			printf("test: %s\n", str);
			return (str + 2);
		}
	return (str);
}

int put_color(t_game *game, char *str)
{
	char *result;

	result = c_valid_check(game, str);
	if(result == NULL)
		return -1;
	else if (result == str + 2)
	{
		free(game->color_numb[0]);
		free(game->color_numb[1]);
		free(game->color_numb[2]);
		return -1;
	}
	if(ft_strncmp(str, "F", 1) == 0)
	{
		game->f_color.r = ft_atoi(game->color_numb[0]);
		game->f_color.g = ft_atoi(game->color_numb[1]);
		game->f_color.b = ft_atoi(game->color_numb[2]);
	}
	else
	{
		game->c_color.r = ft_atoi(game->color_numb[0]);
		game->c_color.g = ft_atoi(game->color_numb[1]);
		game->c_color.b = ft_atoi(game->color_numb[2]);
	}
	free(game->color_numb[0]);
	free(game->color_numb[1]);
	free(game->color_numb[2]);
	return 0;
}

void	p_color(t_game *game, int fd)
{
	char *str;

	str = NULL;
	free(str);
	while(1)
	{
		str = get_next_line(fd);
		str = trimreplace(str, " \t\n");
		if (ft_strlen(str) != 0 && put_color(game, str) == -1)
		{
			printf("String: %s\n", str);
			printf("String: %s\n", "put color error");
			game->color_check = 1;
			free(str);
			break ;
		}
		printf("String: %s\n", str);
		if (game->c_color_num == 1 && game->f_color_num == 1)
		{
			free(str);
			break ;
		}
		free(str);
	}
}