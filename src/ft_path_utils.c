/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 11:22:55 by malluin           #+#    #+#             */
/*   Updated: 2019/03/08 16:49:16 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path		*path_new_node(int idx, char *name)
{
	t_path *tmp;

	if (!(tmp = (t_path *)malloc(sizeof(t_path))))
		return (NULL);
	tmp->idx = idx;
	tmp->w = 2147483647;
	tmp->name = ft_strdup(name);
	tmp->next = NULL;
	return (tmp);
}

t_path		*path_new_front(int idx, char *name, t_path **lst)
{
	t_path	*node;

	if (!*lst)
	{
		*lst = path_new_node(idx, name);
		return (*lst);
	}
	else
	{
		node = path_new_node(idx, name);
		node->next = *lst;
		*lst = node;
	}
	return (node->next);
}

t_path		*path_new_back(int idx, char *name, t_path **lst)
{
	t_path	*node;

	node = *lst;
	if (!*lst)
	{
		*lst = path_new_node(idx, name);
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
		node->next = path_new_node(idx, name);
	}
	return (node->next);
}

int			ft_len_path(t_path *path)
{
	int		i;

	i = 0;
	if (!path)
		return (0);
	while (path)
	{
		i++;
		path = path->next;
	}
	return (i);
}
