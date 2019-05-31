/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_paths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 16:00:21 by malluin           #+#    #+#             */
/*   Updated: 2019/03/11 17:13:37 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			add_path(t_s *s, int nn_idx, int p_id, t_way *way)
{
	t_nn	*nn;

	path_new_back(nn_idx, s->barr[nn_idx].name, &(way->paths[p_id]));
	nn = s->barr[nn_idx].nn;
	while (nn)
	{
		if (nn->flux == 1)
		{
			nn_idx = nn->idx;
			path_new_back(nn->idx, s->barr[nn->idx].name, &(way->paths[p_id]));
			nn = s->barr[nn_idx].nn;
			continue;
		}
		nn = nn->next;
	}
	way->paths[p_id]->w = ft_len_path(way->paths[p_id]);
}

void			count_paths(t_nn *nn, t_s *s)
{
	s->nb_paths = 0;
	while (nn)
	{
		if (nn->flux == 1)
			s->nb_paths++;
		nn = nn->next;
	}
}

void			save_paths(t_s *s, int i)
{
	t_nn	*nn;
	t_way	*way;
	int		len;

	nn = s->barr[s->start_idx].nn;
	way = new_way_back(&s->ways);
	count_paths(nn, s);
	if (!(way->paths = (t_path **)malloc(sizeof(t_path *) * (s->nb_paths + 1))))
		exit(-1);
	way->nb_paths = s->nb_paths;
	while (i <= s->nb_paths)
		way->paths[i++] = NULL;
	nn = s->barr[s->start_idx].nn;
	len = 0;
	while (nn)
	{
		if (nn->flux == 1)
			add_path(s, nn->idx, len++, way);
		nn = nn->next;
	}
	way->paths[len] = 0;
}

float			count_turns(t_way *way, int nb_ants)
{
	float		turns;
	int			total_turns;
	int			i;

	i = 0;
	total_turns = 0;
	while (i < way->nb_paths)
		total_turns += way->paths[i++]->w;
	turns = (float)(total_turns + nb_ants) / (float)way->nb_paths;
	return (turns);
}

void			copy_best_path(t_s *s, int i, int best_idx)
{
	float	turns;
	t_way	*tp;

	tp = s->ways;
	turns = -1;
	while (tp)
	{
		if (count_turns(tp, s->nb_ants) < turns || turns == -1)
		{
			best_idx = i;
			turns = count_turns(tp, s->nb_ants);
		}
		tp = tp->next;
		i++;
	}
	tp = s->ways;
	while (best_idx-- > 0)
		tp = tp->next;
	if (!(s->paths = (t_path **)malloc(sizeof(t_path *) * (tp->nb_paths + 1))))
		exit(-1);
	s->nb_paths = tp->nb_paths;
	i = -1;
	while (++i < tp->nb_paths)
		s->paths[i] = tp->paths[i];
	s->paths[i] = 0;
}
