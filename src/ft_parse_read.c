/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_read.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 14:25:33 by malluin           #+#    #+#             */
/*   Updated: 2019/03/08 15:30:39 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	lst_new_str(t_lst **read_lst, char *buff, int len)
{
	int		i;
	t_lst	*node;
	t_lst	*tmp;

	if (!(tmp = (t_lst *)malloc(sizeof(t_lst))))
		exit(-1);
	tmp->next = NULL;
	if (!(tmp->str = (char *)malloc(sizeof(char) * (len + 1))))
		exit(-1);
	i = 0;
	while (i < len)
	{
		tmp->str[i] = buff[i];
		i++;
	}
	tmp->str[i] = '\0';
	node = *(read_lst);
	if (!(*read_lst))
		*read_lst = tmp;
	else
	{
		while (node->next)
			node = node->next;
		node->next = tmp;
	}
}

void	add_buffer(t_s *s, char *buff, int *idx)
{
	lst_new_str(&s->read_lst, buff, BUFF_SIZE);
	*idx = 0;
	ft_bzero(buff, BUFF_SIZE);
}

void	save_str(t_s *s, char *str, int mode)
{
	static char	buff[BUFF_SIZE];
	static int	idx = 0;

	if (mode == 1)
	{
		while (*str)
		{
			buff[idx++] = *(str++);
			if (idx == BUFF_SIZE)
				add_buffer(s, buff, &idx);
		}
		buff[idx++] = '\n';
		if (idx == BUFF_SIZE)
			add_buffer(s, buff, &idx);
	}
	else
	{
		s->idx = idx;
		lst_new_str(&s->read_lst, buff, ft_strlen(buff));
	}
}

void	print_out(t_s *s)
{
	t_lst	*read_str;

	read_str = s->read_lst;
	if (!read_str)
		return ;
	while (read_str)
	{
		if (read_str->next)
			write(1, read_str->str, BUFF_SIZE);
		else
			write(1, read_str->str, ft_strlen(read_str->str));
		read_str = read_str->next;
	}
	write(1, "\n", 1);
}
