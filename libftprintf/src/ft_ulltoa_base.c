/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <exam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 10:03:56 by exam              #+#    #+#             */
/*   Updated: 2018/12/20 19:43:30 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "libftprintf.h"

static char	*ft_reduce(unsigned long value, int base, char *out, int size)
{
	char	*b;

	b = ft_strdup("0123456789ABCDEF");
	out[size] = '\0';
	size--;
	while (value && size >= 0)
	{
		out[size] = b[ft_iabs(value % base)];
		size--;
		value = value / base;
	}
	free(b);
	return (out);
}

char		*ft_ulltoa_base(unsigned long value, int base)
{
	unsigned long	m;
	int				size;
	char			*out;
	char			*zero;

	size = 0;
	m = value;
	if (base < 2 || base > 16)
		return (NULL);
	else if (value == 0)
	{
		zero = ft_strdup("0");
		return (zero);
	}
	while (m != 0)
		m = (++size) ? m / base : m / base;
	if (!(out = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	out = ft_reduce(value, base, out, size);
	return (out);
}
