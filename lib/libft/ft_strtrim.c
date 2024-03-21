/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocuk <ahocuk@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:24:25 by ahocuk            #+#    #+#             */
/*   Updated: 2024/03/19 21:29:07 by ahocuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char c, const char *set)
{
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*ab;
	char	*start;
	char	*end;

	if (!s1 || !set)
		return (0);
	start = (char *)s1;
	end = start + ft_strlen(s1);
	while (*start && ft_isset(*start, set))
		++start;
	while (start < end && ft_isset(*(end -1), set))
		--end;
	ab = ft_substr(start, 0, end - start);
	return (ab);
}

char *ft_strtrim_end(const char *s1)
{
    if (!s1)
        return NULL;

    char *end = (char *)s1 + ft_strlen(s1) - 1;
    
    while (end >= s1 && (*end == ' '))
        --end;

    return ft_substr(s1, 0, end - s1 + 1);
}
