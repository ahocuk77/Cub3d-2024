/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocuk <ahocuk@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 15:18:24 by ahocuk            #+#    #+#             */
/*   Updated: 2024/03/19 13:55:56 by ahocuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int c, size_t n)
{
	size_t	a;

	a = 0;
	while (a < n)
	{
		if (((unsigned char *)ptr)[a] == (unsigned char)c)
			return ((void *)(ptr + a));
		a++;
	}
	return (0);
}
