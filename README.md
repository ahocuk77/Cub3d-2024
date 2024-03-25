void	add_line_to_map(t_game *game, char *str, int line)
{
	char	**temp;
	int		i;

	temp = game->map.map;
	game->map.map = malloc (sizeof(char *) * (line + 1));
	i = 0;
	while (temp && temp[i])
	{
		game->map.map[i] = temp[i];
		i++;
	}
	game->map.map[i] = str;
	game->map.map[i + 1] = NULL;
	free(temp);
}

void	read_the_map(t_game *game, int fd, char *first_str)
{
	char	*str;
	int		i;
	int		line;

	str = first_str;
	if (!str)
		error_handler(game, NO_MAP);
	while (str)
	{
		i = 0;
		skip_spaces(str, &i);
		if (str[i] != '\n' && str[i] != '\0')
			break ;
		else
			free(str);
		str = get_next_line(fd);
	}
	line = 0;
	while (str)
	{
		line++;
		add_line_to_map(game, delete_slash_n(str), line);
		str = get_next_line(fd);
	}
}