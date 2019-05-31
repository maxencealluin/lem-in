/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <exam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 10:03:56 by exam              #+#    #+#             */
/*   Updated: 2019/01/03 18:52:59 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "libftprintf.h"

void	ft_cplt(char *out)
{
	int k;

	k = 0;
	while (out[k])
	{
		if (out[k] == '0')
			out[k] = '1';
		else
			out[k] = '0';
		k++;
	}
}

char	*make_bit(long long origin)
{
	int		count;
	int		k;
	char	*tmp;
	char	*tmp2;

	if (!(tmp = (char *)malloc(sizeof(char) * (32 + 1))))
		return (NULL);
	if (origin < 0)
	{
		origin = -origin - 1;
		k = 0;
		count = 32;
		while (--count >= 0)
		{
			tmp2 = ft_lltoa(1 & (origin >> count));
			tmp[k] = *tmp2;
			free(tmp2);
			k++;
		}
		tmp[k] = '\0';
		ft_cplt(tmp);
	}
	return (tmp);
}

char	*right_print(long long value, char *out, int base)
{
	char	*tmp;

	tmp = NULL;
	if (base == 8)
		tmp = ft_convert_base(make_bit(value), "01", "01234567");
	else if (base == 16)
		tmp = ft_convert_base(make_bit(value), "01", "0123456789ABCDEF");
	free(out);
	return (tmp);
}

char	*ft_reduce(long long value, int base, char *out, int size)
{
	char	*b;
	int		sign;

	b = ft_strdup("0123456789ABCDEF");
	sign = 0;
	if (value < 0 && base == 10)
		sign = 1;
	out[size] = '\0';
	if (value < 0 && base == 10)
		out[0] = '-';
	else if (value < 0)
	{
		free(b);
		return (right_print(value, out, base));
	}
	size--;
	while (value && size >= sign)
	{
		out[size] = b[ft_iabs(value % base)];
		size--;
		value = value / base;
	}
	free(b);
	return (out);
}

char	*ft_lltoa_base(long long value, int base)
{
	long long	m;
	int			size;
	char		*out;
	char		*zero;

	size = 0;
	m = value;
	if (base < 2 || base > 16)
		return (NULL);
	else if (value == 0)
	{
		zero = ft_strdup("0");
		return (zero);
	}
	if (value < 0 && base == 10)
		size++;
	while (m != 0)
		m = (++size) ? m / base : m / base;
	if (!(out = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	out = ft_reduce(value, base, out, size);
	return (out);
}
