/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:40:37 by malluin           #+#    #+#             */
/*   Updated: 2019/03/08 17:49:51 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_check_way(t_s *s, int i, int out)
{
	t_queue	*node;
	t_nn	*nn;

	queue_new_back(s->start_idx, s->start_idx, &(s->queue));
	node = s->queue;
	while (s->barr[i].end != 1)
	{
		nn = s->barr[i].nn;
		s->barr[i].visited = 1;
		while (nn && out == 0)
		{
			if (s->barr[nn->idx].visited == 0)
				queue_new_back(nn->idx, i, &s->queue);
			out = s->barr[nn->idx].end == 1 ? 1 : 0;
			nn = nn->next;
		}
		if (out == 1)
			break ;
		if (node->next)
			node = node->next;
		else
			ft_error();
		i = node->idx;
	}
	free_queue(s);
}

static void	flow_nn(t_queue *target, t_queue *src, t_s *s, int f)
{
	t_nn *nn;

	nn = s->barr[src->idx].nn;
	while (nn)
	{
		if (nn->idx == target->idx)
		{
			nn->flux += f;
			break ;
		}
		nn = nn->next;
	}
}

void		show_way(t_queue *queue, t_s *s)
{
	t_queue		*parent;
	t_queue		*child;

	child = find_index(queue, s->end_idx);
	parent = find_index(queue, child->idx_parent);
	while (parent->idx != s->start_idx)
	{
		flow_nn(child, parent, s, 1);
		flow_nn(parent, child, s, -1);
		child = parent;
		parent = find_index(queue, parent->idx_parent);
	}
	if (parent->idx == s->start_idx)
	{
		flow_nn(child, parent, s, 1);
		flow_nn(parent, child, s, -1);
	}
}

void		unblock_path(t_s *s, t_queue *queue)
{
	t_queue		*current;

	current = find_index(queue, s->end_idx);
	while (current->idx != s->start_idx)
	{
		s->barr[current->idx].blocked -= 1;
		current = find_index(queue, current->idx_parent);
	}
}
