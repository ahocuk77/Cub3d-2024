/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocuk <ahocuk@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:55:33 by ahocuk            #+#    #+#             */
/*   Updated: 2024/03/23 14:34:56 by ahocuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
int	m_valid_check(t_game *game, char *str)
{
	int i;

	i = 0;
	if(str[0] == '\n')
	{
		printf("String: %s\n", "empty line");
		return -1;
	}
	while(str[i] != '\n' && str[i] != '\0')
	{
		if(str[i] != '0' && str[i] != '1')
		{
			if(str[i] != 'N' && str[i] != 'S' && str[i] != 'E' && str[i] != 'W'
				&& str[i] != ' ')
				return -1;
			if(str[i] != '\t' && str[i] != ' ')
			{
				if(game->map.player != '\0')
					return -1;
				game->map.player = str[i];
			}
		}
		i++;
	}
	return 0;
}
size_t	ft_strlen2(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0') // maybe we can add \n 
		i++;
	return (i);
}

int put_map(t_game *game, char *str, int line)
{
	int result;
	char **temp;
	// int lastsize;
	int		i;

	result = m_valid_check(game, str);
	if(result == -1)
	{
		return -1;
	}
	temp = game->map.map;
	game->map.map = malloc (sizeof(char *) * (line + 1));
	i = 0;
	while (temp && temp[i])
	{
		game->map.map[i] = temp[i];
		i++;
	}
	game->map.map[i] = ft_strdup(str);
	game->map.map[i + 1] = NULL;
	free(temp);
	return 0;
}	

char	*new_line_checker(t_game *game, int fd)
{
	char *str;

	str = get_next_line(fd);
	if(str[0] == '\n')
	{
		while(str[0] == '\n')
		{
			free(str);
			str = get_next_line(fd);
		}
		game->new_line_checker = true;
	}
	return (str);

}


void print_map(t_game *game) {
    int x, y;
    for (x = 0; x < game->height; x++) {
        for (y = 0; y < game->width; y++) {
            printf("%c", game->map.map[x][y]);
        }
        printf("\n");
    }
}

void	p_map(t_game *game, int fd)
{
	char *str;
	int tmp;

	str = new_line_checker(game, fd);
	game->width = ft_strlen(str);
	while(1)
	{
		if(game->new_line_checker != true)
			str = get_next_line(fd);
		game->new_line_checker = false;
		str = trimreplace(str, "\n");
		printf("%s\n", str);
		//str = ft_strtrim_end(str);
		if(str == NULL)
			break ;
		tmp = ft_strlen2(str);
		if(game->width < tmp)
		{
			game->width = ft_strlen2(str);
			//while(str[])
		}
		game->height++;
		if (ft_strlen(str) != 0 && put_map(game, str, game->height) == -1)
		{
			printf("String: %s\n", "put map error");
			game->map_check = 1;
			free(str);
			break ;
		}
		free(str);
	}
	printf("width: %d\n", game->width);
	printf("\n");
	printf("\n");
	printf("game->map.map[x][y]  %s\n", game->map.map[0] );
	printf("zozooz %c\n", game->map.map[7][40]);
	printf("game->map.map[x][y] %c\n", game->map.map[2][54] );
	printf("\n");
	printf("\n");
	//print_map(game);
	//exit(1);
}
