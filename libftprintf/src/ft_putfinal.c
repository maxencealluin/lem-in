/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfinal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:00:30 by malluin           #+#    #+#             */
/*   Updated: 2019/01/29 18:32:06 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_putscreen(char *s, short count, short *idx)
{
	int		j;
	int		i;

	j = 0;
	i = 0;
	while (s[i] != '\0' || j < count)
	{
		while (j < count && idx[j] == i)
		{
			fwrite("\0", 1, 1, stdout);
			j++;
		}
		if (s[i] != '\0')
			fwrite(&s[i], 1, 1, stdout);
		i++;
		while (j < count && idx[j] == i)
		{
			fwrite("\0", 1, 1, stdout);
			j++;
		}
		if (s[i - 1] == '\0')
			break ;
	}
}

void		ft_putfinal(char *s, t_keys *lst)
{
	int		i;
	short	*idx;
	short	count;
	t_keys	*tmp;

	count = 0;
	tmp = lst;
	while (tmp)
	{
		count = tmp->indice >= 0 ? count + 1 : count;
		tmp = tmp->next;
	}
	tmp = lst;
	if (!(idx = (short *)ft_memalloc(sizeof(short) * count)))
		exit(-1);
	i = 0;
	while (tmp)
	{
		if (tmp->indice >= 0)
			idx[i++] = tmp->indice;
		tmp = tmp->next;
	}
	ft_putscreen(s, count, idx);
	free(idx);
}
