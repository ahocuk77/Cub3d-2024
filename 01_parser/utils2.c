/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocuk <ahocuk@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:49:48 by ahocuk            #+#    #+#             */
/*   Updated: 2024/03/13 14:50:27 by ahocuk           ###   ########.fr       */
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