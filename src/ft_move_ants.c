/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_ants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 11:50:22 by malluin           #+#    #+#             */
/*   Updated: 2019/03/11 18:13:02 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#import "lem_in.h"

t_path	*find_shortest_path(t_s *s, int i, int flow)
{
	t_path	*target;

	target = NULL;
	if (i == 0)
		while (i < flow)
			s->barr[s->paths[i++]->idx].blocked = 0;
	i = -1;
	while (++i < flow)
	{
		if (s->barr[s->paths[i]->idx].blocked == 1)
			continue;
		if (target == NULL || target->w > s->paths[i]->w)
			target = s->paths[i];
	}
	if (target != NULL)
		s->barr[target->idx].blocked = 1;
	return (target);
}

void	write_order(char *target, int nb_ant)
{
	write(1, "L", 1);
	ft_putnbr(nb_ant + 1);
	write(1, "-", 1);
	write(1, target, ft_strlen(target));
	write(1, " ", 1);
}

int		ft_launch(t_s *s, int flow, int i, int flux)
{
	t_nn			*nn;
	static	int		idx = 0;
	t_path			*target;
	int				ants_send;

	nn = s->barr[s->start_idx].nn;
	while (i < flow && idx < s->nb_ants)
	{
		ants_send = s->nb_ants - idx;
		if ((target = find_shortest_path(s, i, flow)) == NULL)
			break ;
		flux += target->w;
		if ((ants_send - ((i + 1) * target->w - flux) <= 0) || target->w == -1)
			break ;
		s->ants[idx].path = target->next;
		s->barr[target->idx].busy = target->idx != s->end_idx ? 1 : 0;
		s->ants[idx].idx_pos = target->idx;
		s->ants[idx].launched = 1;
		s->ants[idx].w++;
		write_order(target->name, idx++);
		if (target->idx == s->end_idx)
			s->ants[idx - 1].arrived = 1;
		i++;
	}
	return (idx);
}

void	reset_moved(t_s *s)
{
	int		i;

	i = -1;
	while (++i < s->nb_ants)
		s->ants[i].moved = 0;
}

void	ft_one_step(t_s *s, int launched)
{
	int		i;
	int		target;

	i = -1;
	while (++i < launched)
	{
		if (s->ants[i].path == NULL)
			continue;
		target = s->ants[i].path->idx;
		s->ants[i].path = s->ants[i].path->next;
		if (target != 2147483647)
		{
			s->barr[s->ants[i].idx_pos].busy = 0;
			s->ants[i].idx_pos = target;
			if (target != s->end_idx)
				s->barr[target].busy = 1;
			if (target == s->end_idx)
				s->ants[i].arrived = 1;
			write_order(s->barr[target].name, i);
			s->ants[i].w++;
		}
	}
	reset_moved(s);
}
