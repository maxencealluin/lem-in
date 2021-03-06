/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atbl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 15:24:23 by malluin           #+#    #+#             */
/*   Updated: 2019/03/08 10:53:51 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static	void	assign_start_end(t_s *s, int i)
{
	if (s->next_start == 1 && s->next_end == 1)
		ft_error();
	if (s->next_start == 1 && (s->state_io == 0 || s->state_io == 2))
	{
		s->barr[i].start = 1;
		s->state_io += 1;
		s->start_idx = i;
	}
	else
		s->barr[i].start = 0;
	if (s->next_end == 1 && (s->state_io == 0 || s->state_io == 1))
	{
		s->barr[i].end = 1;
		s->state_io += 2;
		s->end_idx = i;
	}
	else
		s->barr[i].end = 0;
}

void			barr_append(t_s *s, char *name, t_xy xy)
{
	static int		i = 0;

	s->barr[i].x = xy.x;
	s->barr[i].y = xy.y;
	s->barr[i].idx = i;
	assign_start_end(s, i);
	s->next_start = 0;
	s->next_end = 0;
	s->barr[i].busy = 0;
	s->barr[i].nn = NULL;
	s->barr[i].visited = 0;
	s->barr[i].w = -1;
	s->barr[i].blocked = 0;
	s->barr[i++].name = ft_strdup(name);
}
