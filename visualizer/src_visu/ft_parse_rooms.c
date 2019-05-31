/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_rooms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 14:36:06 by malluin           #+#    #+#             */
/*   Updated: 2019/03/11 18:33:00 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int		is_room(char *str, int i)
{
	if (str[0] == 'L' || str[0] == '#')
		return (0);
	while (str[i] && str[i] != ' ')
	{
		if (str[i] == '-')
			return (0);
		if (str[++i] == '\0')
			return (0);
	}
	if (str[i])
		i++;
	i = str[i] == '-' ? i + 1 : i;
	if (ft_isdigit(str[i]) == 0)
		return (0);
	while (ft_isdigit(str[i++]) == 1)
		if (str[i] == '\0' || (str[i] != '\0' && ft_isdigit(str[i])
			!= 1 && str[i] != ' '))
			return (0);
	i = str[i] == '-' ? i + 1 : i;
	if (ft_isdigit(str[i]) == 0)
		return (0);
	while (ft_isdigit(str[i++]) == 1)
		if (str[i] && ft_isdigit(str[i]) != 1)
			return (0);
	return (1);
}

int		parse_room(char *str, t_s *s_lem)
{
	char	*name;
	t_xy	xy;
	int		i;
	int		j;

	i = 0;
	while (str[i] && str[i] != ' ')
		i++;
	if (!(name = (char *)malloc(sizeof(char) * (i + 1))))
		exit(-1);
	j = 0;
	i = 0;
	while (str[j] && str[j] != ' ')
		name[i++] = str[j++];
	name[i] = '\0';
	if (str[i])
		j = ++i;
	xy.x = ft_atoi(str + i);
	while (ft_isdigit(str[i++]) == 1)
		;
	xy.y = ft_atoi(str + i);
	barr_append(s_lem, name, xy);
	ft_memdel((void **)&name);
	return (1);
}

int		is_edge(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '-')
	{
		i++;
		if (!str[i] || str[i] == ' ')
			return (0);
	}
	if (i < 1)
		return (0);
	if (str[i])
		j++;
	if (str[i + j] == '\0')
		return (0);
	while (str[i + j])
	{
		if (str[i + j++] == ' ')
			return (0);
	}
	return (1);
}

int		parse_edge(char *str, t_s *s_lem)
{
	char	*e1;
	char	*e2;
	int		i;

	i = 0;
	if (str)
		e1 = ft_strdup_to(str, '-');
	while (str[i] && str[i] != '-')
		i++;
	if (i == 0)
		return (0);
	if (str[i])
		i++;
	e2 = str[i] != '\0' ? ft_strdup_to(str + i, ' ') : 0;
	if (add_edge_barr(e1, e2, s_lem) == 0)
		return (0);
	ft_memdel((void **)&e1);
	ft_memdel((void **)&e2);
	return (1);
}

void	lst_new_order(t_order **order_lst, int idx, char **target, char stop)
{
	int		i;
	t_order	*node;
	t_order	*tmp;

	if (!(tmp = (t_order *)malloc(sizeof(t_order))))
		exit(-1);
	tmp->next = NULL;
	tmp->ant = idx;
	tmp->target = *target;
	tmp->stop = stop;
	node = *(order_lst);
	if (!(*order_lst))
		*order_lst = tmp;
	else
	{
		while (node->next)
			node = node->next;
		node->next = tmp;
	}
}

int		parse_order(char *str, t_s *s_lem)
{
	char	*target;
	int		idx;

	idx = 0;
	while (*str)
	{
		if (*str == 'L')
			str++;
		else
			return (0);
		idx = ft_atoi(str);
		while (*str && *str != '-')
			str++;
		target = ft_strdup_to((++str), ' ');
		while (*str && *str != 'L')
			str++;
		if (target && *str && *str == 'L')
			lst_new_order(&s_lem->read_orders, idx, &target, 0);
		else if (target)
			lst_new_order(&s_lem->read_orders, idx, &target, 1);
	}
	return (1);
}
