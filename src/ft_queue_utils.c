/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 11:22:55 by malluin           #+#    #+#             */
/*   Updated: 2019/03/08 16:11:52 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		queue_del_first(t_queue **q)
{
	t_queue	*current;
	t_queue	*tmp;

	if (!*q)
		return ;
	current = (*q)->next;
	tmp = *q;
	tmp->next = NULL;
	*q = current;
	ft_memdel((void **)&tmp);
}

t_queue		*find_index(t_queue *q_ptr, int idx)
{
	while (q_ptr->next && q_ptr->idx != idx)
		q_ptr = q_ptr->next;
	return (q_ptr);
}

t_queue		*queue_new_node(int idx, int idx_parent)
{
	t_queue *tmp;

	if (!(tmp = (t_queue *)malloc(sizeof(t_queue))))
		return (NULL);
	tmp->idx = idx;
	tmp->idx_parent = idx_parent;
	tmp->next = NULL;
	return (tmp);
}

t_queue		*queue_new_back(int idx, int idx_parent, t_queue **lst)
{
	t_queue	*node;

	node = *lst;
	if (!*lst)
	{
		*lst = queue_new_node(idx, idx_parent);
		return (*lst);
	}
	else
	{
		while (node->next)
		{
			if (idx == node->idx)
				return (0);
			node = node->next;
		}
		if (idx == node->idx)
			return (0);
		node->next = queue_new_node(idx, idx_parent);
	}
	return (node->next);
}
