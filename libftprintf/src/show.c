/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 11:02:28 by malluin           #+#    #+#             */
/*   Updated: 2019/03/20 13:23:43 by fnussbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

char	*clean_fmt(char *fmt, t_keys *lst, int i)
{
	char	*dest;
	int		j;
	int		c;

	dest = ft_strdup(fmt);
	while (lst)
		if (dest[++i] == '%')
		{
			j = 1;
			while (is_option(dest[i + j]))
				j++;
			j = dest[i + j] == '\0' ? j : j + 1;
			c = ft_strlen(dest + i + j);
			ft_memmove(dest + i, dest + i + j, c);
			(dest + i)[c] = '\0';
			if (lst->conv == '\0')
				break ;
			if (lst->is_blank == 1 && ft_tolower(lst->conv) == 'c')
				lst->indice = i + ((lst->length - 1 * (lst->length != 0))
							* (ft_strstr(lst->options, "-") == NULL));
			dest = ft_insert(&dest, (dest + i), lst->res);
			i += ft_strlen(lst->res) - 1;
			lst = lst->next;
		}
	return (dest);
}

void	assemble_res(t_output *out)
{
	t_keys	*tmp;
	int		c;

	c = 0;
	if (out->fmt)
		c = ft_strlen(out->fmt);
	tmp = out->lst;
	while (tmp)
	{
		if (tmp->res)
			c += ft_strlen(tmp->res);
		if (out->lst->res
			&& ft_strcmp(out->lst->res, "\0") == 0 && tmp->conv == 'c')
			c++;
		tmp = tmp->next;
	}
	if (c != 0)
		out->result = clean_fmt(out->fmt, out->lst, -1);
	else
		out->result = ft_strdup("");
}
