/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocuk <ahocuk@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:03:16 by ahocuk            #+#    #+#             */
/*   Updated: 2022/10/31 00:49:43 by ahocuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t n)
{
	size_t	a;

	a = 0;
	while (a < n)
	{
		if (*(unsigned char *)(ptr1 + a) != *(unsigned char *)(ptr2 + a))
			return (*(unsigned char *)(ptr1 + a)
			- *(unsigned char *)(ptr2 + a));
		a++;
	}
	return (0);
}
