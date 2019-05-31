/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nnlst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 15:24:23 by malluin           #+#    #+#             */
/*   Updated: 2019/03/04 16:57:09 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_cmp_opt(const char *s1, const char *s2)
{
	while (*s1 == *s2)
	{
		s1++;
		s2++;
		if (*s1 == '\0')
			return ((unsigned char)(*s1) - (unsigned char)(*s2));
	}
	return ((unsigned char)(*s1) - (unsigned char)(*s2));
}

int			add_edge_barr(char *e1, char *e2, t_s *s)
{
	int		i;
	int		j;

	if (e1[0] == e2[0] && ft_cmp_opt(e1, e2) == 0)
		return (0);
	i = 0;
	j = 0;
	while (i < s->room_count)
		if (s->barr[i].name[0] == e1[0] && ft_cmp_opt(s->barr[i].name, e1) == 0)
			break ;
		else
			i++;
	while (j < s->room_count)
		if (s->barr[j].name[0] == e2[0] && ft_cmp_opt(s->barr[j].name, e2) == 0)
			break ;
		else
			j++;
	if (i == s->room_count || j == s->room_count)
		return (0);
	nnlst_new_back(j, &(s->barr[i].nn));
	nnlst_new_back(i, &(s->barr[j].nn));
	return (1);
}

t_nn		*nnlst_new_node(int content)
{
	t_nn *tmp;

	if (!(tmp = (t_nn *)malloc(sizeof(t_nn))))
		return (NULL);
	tmp->idx = content;
	tmp->flux = 0;
	tmp->visited = 0;
	tmp->next = NULL;
	return (tmp);
}

t_nn		*nnlst_new_front(int idx, t_nn **lst)
{
	t_nn	*tmp;

	tmp = nnlst_new_node(idx);
	tmp->next = *lst;
	*lst = tmp;
	return (tmp);
}

t_nn		*nnlst_new_back(int idx, t_nn **lst)
{
	t_nn	*node;

	node = *lst;
	if (!*lst)
	{
		*lst = nnlst_new_node(idx);
		return (*lst);
	}
	else
	{
		while (node->next)
		{
			if (node->idx == idx)
				return (0);
			node = node->next;
		}
		if (node->idx == idx)
			return (0);
		node->next = nnlst_new_node(idx);
	}
	return (node->next);
}
