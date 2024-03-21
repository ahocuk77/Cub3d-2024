/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocuk <ahocuk@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 16:06:04 by ahocuk            #+#    #+#             */
/*   Updated: 2022/11/08 02:03:23 by ahocuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ab;
	unsigned int	ub;

	if (!s)
		return (0);
	ab = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!ab)
		return (0);
	ub = 0;
	while (s[ub])
	{
		ab[ub] = f(ub, s[ub]);
		++ub;
	}
	ab[ub] = 0;
	return (ab);
}
