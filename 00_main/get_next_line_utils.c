/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 13:54:58 by musenov           #+#    #+#             */
/*   Updated: 2024/05/03 19:13:35 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	while (size > 0)
		*(str + size--) = '\0';
	*(str + 0) = '\0';
	return (str);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char	*s3;
	size_t	i_s12;
	size_t	i_s3;

	if (!s1 || !s2)
		return (free ((char *)s1), NULL);
	s3 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
		return (free ((char *)s1), NULL);
	i_s3 = 0;
	i_s12 = 0;
	while (*(s1 + i_s12) != '\0')
		*(s3 + i_s3++) = *(s1 + i_s12++);
	i_s12 = 0;
	while (*(s2 + i_s12) != '\0')
		*(s3 + i_s3++) = *(s2 + i_s12++);
	*(s3 + i_s3) = '\0';
	free ((char *)s1);
	return (s3);
}
