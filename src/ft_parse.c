/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 14:23:45 by malluin           #+#    #+#             */
/*   Updated: 2019/03/20 14:56:53 by fnussbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_verify(char *str)
{
	long	nb;
	int		i;

	i = str[0] == '-' ? 1 : 0;
	if (str[i] == '\0')
		ft_error();
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i++]))
			ft_error();
	}
	if (ft_strlen(str) > 11)
		ft_error();
	nb = ft_atol(str);
	if (nb <= 0 || nb > 2147483647)
		ft_error();
	return (nb);
}

int		parse_str(char *str, t_s *s_lem)
{
	static int		edge = 0;

	if (edge == 0 && is_room(str, 0) == 1)
	{
		if (parse_room(str, s_lem) == 1)
			s_lem->room_count++;
		else
			return (0);
	}
	else if (is_edge(str) == 1)
	{
		edge = 1;
		if (parse_edge(str, s_lem) == 0)
			return (0);
	}
	else
		return (0);
	return (1);
}

char	*extract_str(t_s *s_lem, int max, char *str, char *str2)
{
	static t_lst	*read_lst = NULL;
	static int		idx = 0;

	read_lst = read_lst == NULL ? s_lem->read_lst : read_lst;
	if (read_lst->next == NULL && idx >= s_lem->idx)
		return (0);
	max = read_lst->next != NULL ? BUFF_SIZE : s_lem->idx;
	str = ft_strdup_to_count(read_lst->str + idx, '\n', &idx);
	if (idx >= max)
		go_next(&idx, &read_lst);
	while (idx <= max && (read_lst->str[idx] != '\n'))
	{
		str2 = ft_strdup_to_count(read_lst->str + idx, '\n', &idx);
		str = ft_insert(&str, str + ft_strlen(str), str2);
		free(str2);
		if (idx >= max && read_lst->next)
			go_next(&idx, &read_lst);
		else
			break ;
	}
	idx++;
	return (str);
}

void	ft_treat_lst(t_s *s_lem)
{
	char	*str;
	int		i;

	i = 0;
	while ((str = extract_str(s_lem, 0, NULL, NULL)) != NULL)
	{
		if (str[0] == '#')
		{
			if (ft_strcmp(str, "##start") == 0)
				s_lem->next_start = 1;
			else if (ft_strcmp(str, "##end") == 0)
				s_lem->next_end = 1;
			ft_memdel((void **)&str);
			continue ;
		}
		if (i++ == 0)
			s_lem->nb_ants = ft_verify(str);
		else
		{
			if (str[0] == '\0' || str[0] == 'L' || parse_str(str, s_lem) == 0)
				break ;
		}
		ft_memdel((void **)&str);
	}
	ft_memdel((void **)&str);
}

void	ft_parse(t_s *s_lem)
{
	char	*str;
	int		i;

	i = 0;
	str = NULL;
	while (get_next_line(0, &str) > 0)
	{
		save_str(s_lem, str, 1);
		if (is_room(str, 0) == 1)
			s_lem->room_max++;
		ft_memdel((void **)&str);
	}
	ft_memdel((void **)&str);
	save_str(s_lem, str, 0);
	if (!(s_lem->barr = (t_barr *)malloc(sizeof(t_barr) * s_lem->room_max)))
		exit(-1);
	ft_treat_lst(s_lem);
}
