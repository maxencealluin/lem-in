/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_putaddress.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnussbau <fnussbau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 08:10:46 by fnussbau          #+#    #+#             */
/*   Updated: 2018/11/19 08:20:50 by fnussbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_putaddress(t_list *ptr)
{
	long	add;
	char	*base;
	char	*res;
	int		i;
	int		size;

	if (ptr)
	{
		size = 11;
		add = (long)ptr;
		i = size + 1;
		res = ft_strnew(size + 1);
		base = "0123456789abcdef";
		while ((add / 16) >= 0 && --i >= 0)
		{
			res[i] = base[add % 16];
			add = add / 16;
		}
		ft_putstr("0x");
		while (++i <= size && res[i])
			ft_putchar(res[i]);
		ft_putchar('\n');
	}
	else
		ft_putstr("0x0\n");
}
