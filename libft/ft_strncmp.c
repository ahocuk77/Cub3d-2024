/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocuk <ahocuk@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 14:55:26 by ahocuk            #+#    #+#             */
/*   Updated: 2022/10/31 00:44:27 by ahocuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	a;

	if (n == 0)
		return (0);
	a = 0;
	while (str1[a] == str2[a] && str1[a] != '\0')
	{
		if (a < (n -1))
			a++;
		else
			return (0);
	}
	return ((unsigned char)(str1[a]) - (unsigned char)(str2[a]));
}
