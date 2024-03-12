/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_color.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocuk <ahocuk@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:06:47 by ahocuk            #+#    #+#             */
/*   Updated: 2024/03/12 20:33:34 by ahocuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_sep(char c)
{
	return (c == ' ' || c == '\t' || c == ',');
}

static int	count_words(char *s)
{
	int count;

	count = 0;
	while (*s)
	{
		while (*s && is_sep(*s))
			s++;
		if (*s && !is_sep(*s))
		{
			count++;
			while (*s && !is_sep(*s))
				s++;
		}
	}
	return (count);
}

char	**ft_split_custom(char *s)
{
	char	**split;
	int		i;
	int		j;

	split = (char **)malloc(sizeof(char *) * (count_words(s) + 1));
	if (!split)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && is_sep(*s))
			s++;
		if (*s && !is_sep(*s))
		{
			j = 0;
			while (s[j] && !is_sep(s[j]))
				j++;
			split[i] = (char *)malloc(sizeof(char) * (j + 1));
			if (!split[i])
				return (NULL);
			j = 0;
			while (*s && !is_sep(*s))
				split[i][j++] = *s++;
			split[i++][j] = '\0';
		}
	}
	split[i] = NULL;
	return (split);
}

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

char	*c_valid_check(t_game *game, char *str)
{
	char **str_new;
	char *first;
	int 	i;
	int 	j;

	i = 0;
	j = 0;
	if(ft_strncmp(str, "F", 1) == 0)
		game->f_color_num++;
	else if(ft_strncmp(str, "C", 1) == 0)
		game->c_color_num++;
	else
	{
		ft_putendl_fd("ERROR\n", 2);
		return NULL;
	}
	if(game->c_color_num > 1 || game->f_color_num > 1)
		return NULL;
	str = str + 2;
	str_new = ft_split_custom(str);
	while(str_new[game->total_color_num] != NULL)
	{
		first = str_new[game->total_color_num];
		printf("ft_atoi(first) %s\n", first);
		if(is_numeric(first) == -1)
		{	
			printf("error check: %s\n", first);
			exit(1);
		}
		if(ft_atoi(first) == 0)
			exit(1);
		game->total_color_num++;
		i++;
	}
	while (j <= i)
	{
		free(str_new[j]);
		j++;
	}
	free(str_new);
	
	printf("trim sonra11111111: %s\n", first);
	return NULL;
}

int put_color(t_game *game, char *str, char *color)
{
	color = c_valid_check(game, str);
	return 0;
}

void	p_color(t_game *game, int fd)
{
	char *str;
	char *colors;

	colors = NULL;
	str = NULL;
	free(str);
	while(1)
	{
		str = get_next_line(fd);
		str = trimreplace(str, " \t\n");
		if (ft_strlen(str) != 0 && put_color(game, str, colors) == -1)
			return (free(str), exit(1));
		if (game->c_color_num == 1 && game->f_color_num == 1)
		{
			free(str);
			break ;
		}
		printf("String: %s\n", str);
		free(str);
	}
}