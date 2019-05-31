/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnussbau <fnussbau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 17:51:58 by fnussbau          #+#    #+#             */
/*   Updated: 2018/11/19 08:17:36 by fnussbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_at(t_list *begin_list, size_t nb)
{
	size_t	k;
	t_list	*current;

	current = begin_list;
	k = 0;
	while (k < nb && current)
	{
		current = current->next;
		k++;
	}
	return (current);
}
