/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocuk <ahocuk@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 23:35:34 by ahocuk            #+#    #+#             */
/*   Updated: 2022/11/24 22:19:28 by ahocuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ub;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	ub = ft_lstlast(*lst);
	if (ub != NULL)
		ub ->next = new;
	else
		return ;
}
