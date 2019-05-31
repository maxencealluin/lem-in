/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bits.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnussbau <fnussbau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 17:49:18 by fnussbau          #+#    #+#             */
/*   Updated: 2018/12/20 17:49:43 by fnussbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <unistd.h>
#include "libft.h"

void	ft_printbit(unsigned int n)
{
	int count;

	count = 32;
	while (--count >= 0)
	{
		ft_putnbr(1 & (n >> count));
		if (count % 8 == 0)
			ft_putchar('\n');
	}
}

void	ft_printbitchar(unsigned char n)
{
	int count;

	count = 8;
	while (--count >= 0)
	{
		ft_putnbr(1 & (n >> count));
		if (count % 8 == 0)
			ft_putchar('\n');
	}
}

int		numbit(unsigned int c)
{
	int num;

	num = 0;
	while (c)
	{
		c >>= 1;
		num++;
	}
	return (num);
}
