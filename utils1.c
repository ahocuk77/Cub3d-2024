/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocuk <ahocuk@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:06:33 by ahocuk            #+#    #+#             */
/*   Updated: 2024/03/11 15:13:23 by ahocuk           ###   ########.fr       */
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
