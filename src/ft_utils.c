/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 13:56:28 by malluin           #+#    #+#             */
/*   Updated: 2019/03/08 16:37:07 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_s		*initialize_struct(void)
{
	t_s	*s_lem;

	if (!(s_lem = (t_s *)malloc(sizeof(t_s))))
		exit(-1);
	s_lem->barr = NULL;
	s_lem->nb_ants = 0;
	s_lem->next_start = 0;
	s_lem->next_end = 0;
	s_lem->read_lst = 0;
	s_lem->room_count = 0;
	s_lem->room_max = 0;
	ft_bzero(s_lem->buff, BUFF_SIZE);
	s_lem->idx = 0;
	s_lem->state_io = 0;
	s_lem->queue = NULL;
	s_lem->paths = NULL;
	s_lem->start_idx = -1;
	s_lem->end_idx = -1;
	s_lem->ants = NULL;
	s_lem->nb_paths = 0;
	s_lem->ways = NULL;
	return (s_lem);
}

void	ft_initialize_ants(t_s *s)
{
	int		i;

	if (!(s->ants = (t_ant *)malloc(sizeof(t_ant) * s->nb_ants)))
		exit(-1);
	i = 0;
	while (i < s->nb_ants)
	{
		s->ants[i].ant_idx = i;
		s->ants[i].launched = 0;
		s->ants[i].idx_pos = 0;
		s->ants[i].arrived = 0;
		s->ants[i].moved = 0;
		s->ants[i].w = 0;
		s->ants[i].path = NULL;
		i++;
	}
}

void	go_next(int *idx, t_lst **read_lst)
{
	*read_lst = (*read_lst)->next;
	*idx = 0;
}

char	*ft_strdup_to_count(char *str, char c, int *z)
{
	int		i;
	int		j;
	char	*cpy;

	i = 0;
	j = 0;
	while (str[i] && str[i] != c)
		i++;
	*z += i;
	if (!(cpy = (char *)malloc(sizeof(char) * (i + 1))))
		exit(-1);
	while (j < i)
	{
		cpy[j] = str[j];
		j++;
	}
	cpy[j] = '\0';
	return (cpy);
}

void	reset_visited(t_s *s)
{
	int		i;

	i = 0;
	while (i < s->room_count)
		s->barr[i++].visited = 0;
}
