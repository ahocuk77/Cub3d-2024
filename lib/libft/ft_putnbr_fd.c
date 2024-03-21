/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocuk <ahocuk@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 16:07:00 by ahocuk            #+#    #+#             */
/*   Updated: 2022/11/01 17:10:30 by ahocuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		s;
	char	c;

	s = 1;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		s = -1;
	}
	if (n / 10)
		ft_putnbr_fd(n / 10 * s, fd);
	c = '0' + n % 10 * s;
	ft_putchar_fd(c, fd);
}
