/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:42:05 by malluin           #+#    #+#             */
/*   Updated: 2018/11/12 16:00:33 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*blist;
	t_list	*plist;
	t_list	*node;

	if (lst && f)
	{
		blist = f(lst);
		plist = blist;
		while (lst->next)
		{
			lst = lst->next;
			node = f(lst);
			plist->next = node;
			plist = node;
		}
	}
	else
		blist = NULL;
	return (blist);
}
