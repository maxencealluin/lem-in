/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_edmond_karp_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 16:47:59 by malluin           #+#    #+#             */
/*   Updated: 2019/03/11 18:14:58 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_way	*way_new_node(void)
{
	t_way *tmp;

	if (!(tmp = (t_way *)malloc(sizeof(t_way))))
		return (NULL);
	tmp->paths = NULL;
	tmp->next = NULL;
	return (tmp);
}

t_way			*new_way_back(t_way **lst)
{
	t_way	*node;

	node = *lst;
	if (!*lst)
	{
		*lst = way_new_node();
		return (*lst);
	}
	else
	{
		while (node->next)
			node = node->next;
		node->next = way_new_node();
	}
	return (node->next);
}

int				doublon(t_s *s, t_queue *q)
{
	t_queue *current;

	current = q;
	while (current)
	{
		if (s->barr[current->idx].blocked >= 2)
			return (1);
		current = current->next;
	}
	return (0);
}
