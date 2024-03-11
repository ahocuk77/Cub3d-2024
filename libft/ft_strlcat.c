/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocuk <ahocuk@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:22:00 by ahocuk            #+#    #+#             */
/*   Updated: 2022/11/08 22:59:31 by ahocuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len_dst;
	size_t	len_src;

	len_dst = 0;
	if (dst)
		len_dst = (size_t)ft_strlen(dst);
	len_src = (size_t)ft_strlen(src);
	i = 0;
	if (dstsize == 0 || dstsize <= len_dst)
		return (dstsize + len_src);
	while ((i < dstsize - len_dst - 1) && src[i] != '\0')
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	return (len_dst + len_src);
}
