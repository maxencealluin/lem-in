/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 14:18:12 by malluin           #+#    #+#             */
/*   Updated: 2019/03/20 15:32:20 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		all_ants_arrived(t_s *s)
{
	int		i;

	i = 0;
	while (i < s->nb_ants)
	{
		if (s->ants[i++].arrived == 0)
			return (0);
	}
	return (1);
}

void	path_ek(t_s *s)
{
	int		launched;
	int		flow;

	launched = 0;
	ft_edmond_karp(s, 0);
	flow = s->nb_paths;
	while (all_ants_arrived(s) != 1 && s->nb_paths > 0 && s->paths != NULL)
	{
		ft_one_step(s, launched);
		if (launched < s->nb_ants)
			launched = ft_launch(s, flow, 0, 0);
		write(1, "\n", 1);
	}
}

int		main(void)
{
	t_s	*s_lem;

	s_lem = initialize_struct();
	ft_parse(s_lem);
	if (s_lem->nb_ants <= 0 || s_lem->room_count <= 0 || s_lem->state_io != 3)
	{
		free_struct_parsing(s_lem);
		ft_error();
	}
	ft_check_way(s_lem, s_lem->start_idx, 0);
	reset_visited(s_lem);
	ft_initialize_ants(s_lem);
	print_out(s_lem);
	path_ek(s_lem);
	free_struct_parsing(s_lem);
	free_struct_resolve(s_lem);
	return (0);
}
