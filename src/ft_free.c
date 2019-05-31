/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 11:51:51 by malluin           #+#    #+#             */
/*   Updated: 2019/03/08 16:06:50 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_queue(t_s *s)
{
	t_queue	*tmp;
	t_queue	*queue;

	queue = s->queue;
	while (queue)
	{
		tmp = queue;
		queue = queue->next;
		ft_memdel((void **)&tmp);
	}
	s->queue = NULL;
}

void	free_path(t_path *path_to_free)
{
	t_path	*tmp;
	t_path	*path;

	path = path_to_free;
	while (path)
	{
		tmp = path;
		path = path->next;
		ft_memdel((void **)&(tmp->name));
		ft_memdel((void **)&tmp);
	}
}

void	free_nn(t_nn *nn)
{
	t_nn	*tmp2;
	t_nn	*tmp1;

	tmp1 = nn;
	while (tmp1)
	{
		tmp2 = tmp1;
		tmp1 = tmp1->next;
		ft_memdel((void **)&tmp2);
	}
}

void	free_struct_parsing(t_s *s)
{
	t_lst	*read_lst;
	t_lst	*read_tmp;
	int		i;

	i = 0;
	read_lst = s->read_lst;
	while (read_lst)
	{
		ft_memdel((void **)&read_lst->str);
		read_tmp = read_lst;
		read_lst = read_lst->next;
		ft_memdel((void **)&read_tmp);
	}
	while (i < s->room_count)
	{
		ft_memdel((void **)&(s->barr[i].name));
		free_nn(s->barr[i++].nn);
	}
	ft_memdel((void **)(&(s->barr)));
}

void	free_struct_resolve(t_s *s)
{
	int		i;
	t_way	*way;
	t_way	*waytmp;

	i = 0;
	free_queue(s);
	while (i < s->nb_ants)
		free_path(s->ants[i++].path);
	ft_memdel((void **)&(s->ants));
	way = s->ways;
	while (way)
	{
		waytmp = way;
		way = way->next;
		i = 0;
		while (i < waytmp->nb_paths)
			free_path(waytmp->paths[i++]);
		ft_memdel((void **)&waytmp->paths);
		ft_memdel((void **)&waytmp);
	}
	i = 0;
	ft_memdel((void **)(&s->paths));
	ft_memdel((void **)(&s));
}
