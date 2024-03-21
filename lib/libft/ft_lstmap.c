/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocuk <ahocuk@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 23:35:50 by ahocuk            #+#    #+#             */
/*   Updated: 2022/11/24 22:30:04 by ahocuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*abb;
	t_list	*zuu;

	if (lst == 0 || f == 0)
		return (NULL);
	abb = ft_lstnew((*f)(lst->content));
	if (!abb)
		return (NULL);
	zuu = abb;
	lst = lst->next;
	while (lst)
	{
		zuu->next = ft_lstnew((*f)(lst->content));
		if (!zuu->next)
		{
			ft_lstclear(&abb, del);
			return (NULL);
		}
		zuu = zuu->next;
		lst = lst->next;
	}
	return (abb);
}
