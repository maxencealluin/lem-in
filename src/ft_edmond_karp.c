/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_edmond_karp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 11:10:44 by malluin           #+#    #+#             */
/*   Updated: 2019/03/11 18:14:13 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		find_flux(t_s *s, int box_1, int box_2)
{
	t_nn	*nn_box_1;

	nn_box_1 = s->barr[box_1].nn;
	while (nn_box_1)
	{
		if (nn_box_1->idx == box_2)
			return (nn_box_1->flux);
		nn_box_1 = nn_box_1->next;
	}
	return (-5);
}

void	add_blocked(t_s *s)
{
	int		i;
	t_queue	*queue;
	t_queue	*parent_queue;

	queue = s->queue;
	i = 0;
	while (queue)
	{
		if (s->barr[queue->idx].end == 1)
			break ;
		queue = queue->next;
	}
	while (s->barr[queue->idx].start != 1)
	{
		parent_queue = find_index(s->queue, queue->idx_parent);
		if (queue->idx != s->start_idx && queue->idx != s->end_idx)
			s->barr[queue->idx].blocked += 1;
		if (find_flux(s, queue->idx, parent_queue->idx) == 1)
		{
			s->barr[parent_queue->idx].blocked -= 1;
			s->barr[queue->idx].blocked -= 1;
		}
		queue = parent_queue;
	}
}

int		log_queue(t_s *s, t_nn *nn, int i)
{
	int		out;

	out = 0;
	if (s->barr[nn->idx].visited == 0 && nn->flux < 1
		&& nn->idx != s->start_idx)
	{
		if (nn->flux == -1 || (nn->flux == 0 && s->barr[i].blocked == 0)
		|| (nn->flux == 0 && s->barr[i].blocked == 1
		&& find_flux(s, find_index(s->queue, i)->idx_parent, i) == -1))
			queue_new_back(nn->idx, i, &s->queue);
	}
	if (nn->flux < 1)
		out = (nn->idx == s->end_idx) ? 1 : 0;
	return (out);
}

int		ft_bfs(t_s *s, int i, int out)
{
	t_queue	*node;
	t_nn	*nn;

	queue_new_back(i, s->start_idx, &(s->queue));
	node = s->queue;
	while (s->barr[i].end != 1)
	{
		nn = s->barr[i].nn;
		s->barr[i].visited = 1;
		while (nn && out == 0)
		{
			log_queue(s, nn, i);
			nn = nn->next;
		}
		if (out == 1)
			break ;
		if (node->next)
			node = node->next;
		else
			return (-1);
		i = node->idx;
	}
	return (1);
}

void	ft_edmond_karp(t_s *s, int i)
{
	t_nn	*nn;

	nn = s->barr[s->start_idx].nn;
	while (nn)
	{
		if (ft_bfs(s, s->start_idx, 0) == -1)
		{
			free_queue(s);
			break ;
		}
		reset_visited(s);
		if (s->queue != NULL)
		{
			add_blocked(s);
			if (doublon(s, s->queue) == 0)
				show_way(s->queue, s);
			else
				unblock_path(s, s->queue);
		}
		free_queue(s);
		nn = nn->next;
		i++;
		save_paths(s, 0);
	}
	copy_best_path(s, 0, -1);
}
