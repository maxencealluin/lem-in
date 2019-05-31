/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnussbau <fnussbau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 11:16:01 by fnussbau          #+#    #+#             */
/*   Updated: 2019/01/09 11:28:41 by fnussbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <unistd.h>
#include "libft.h"

static void	ft_red(unsigned char *m, unsigned char *c, unsigned char tmp)
{
	unsigned char	tmp2;

	tmp = c[0] >> 6;
	c[0] = c[0] << 2;
	c[0] = c[0] >> 2;
	c[0] = c[0] | m[0];
	tmp2 = c[1] >> 4;
	c[1] = c[1] << 4;
	c[1] = c[1] >> 2;
	c[1] = c[1] | tmp;
	c[1] = c[1] | m[1];
	c[2] = c[2] << 4;
	c[2] = c[2] | tmp2;
	c[2] = c[2] | m[2];
}

static void	ft_red2(unsigned char *m, unsigned char *c, unsigned char tmp)
{
	unsigned char	tmp2;

	tmp = c[0] >> 6;
	c[0] = c[0] << 2;
	c[0] = c[0] >> 2;
	c[0] = c[0] | m[0];
	tmp2 = c[1] >> 4;
	c[1] = c[1] << 4;
	c[1] = c[1] >> 2;
	c[1] = c[1] | tmp;
	c[1] = c[1] | m[1];
	tmp = c[2] >> 2;
	c[2] = c[2] << 6;
	c[2] = c[2] >> 2;
	c[2] = c[2] | tmp2;
	c[2] = c[2] | m[2];
	c[3] = c[3] | tmp;
	c[3] = c[3] | m[3];
}

void		ft_apply_mask(unsigned char *m, unsigned char *c, int count)
{
	unsigned char	tmp;
	int				k;

	k = 0;
	if (count == 1)
		c[k] = c[k] | m[k];
	else if (count == 2)
	{
		tmp = c[0] >> 6;
		c[0] = c[0] << 2;
		c[0] = c[0] >> 2;
		c[0] = c[0] | m[0];
		c[1] = c[1] << 2;
		c[1] = c[1] | tmp;
		c[1] = c[1] | m[1];
	}
	else if (count == 3 && (tmp = c[0]))
		ft_red(m, c, tmp);
	else
	{
		tmp = c[0];
		ft_red2(m, c, tmp);
	}
	return ;
}

int			make_mask(unsigned int c, int *count)
{
	unsigned int mask;

	mask = 0;
	if (numbit(c) <= 7 && (*count = 1))
		mask = 0;
	else if (numbit(c) <= 11 && (*count = 2))
		mask = ft_power(2, 15) + ft_power(2, 14) + ft_power(2, 7);
	else if (numbit(c) <= 16 && (*count = 3))
		mask = ft_power(2, 23) + ft_power(2, 22) + ft_power(2, 21)
		+ ft_power(2, 15) + ft_power(2, 7);
	else
	{
		mask = ft_power(2, 31) + ft_power(2, 30) + ft_power(2, 29)
		+ ft_power(2, 28) + ft_power(2, 23) + ft_power(2, 15)
		+ ft_power(2, 7);
		*count = 4;
	}
	return (mask);
}

char		*ft_wchar(unsigned int c)
{
	unsigned int	mask;
	unsigned char	*m;
	unsigned char	*ch;
	int				count;
	char			*out;

	if (!(out = (char *)malloc(sizeof(char) * (numbit(c) + 1))))
		return (NULL);
	out[numbit(c)] = '\0';
	count = 1;
	mask = 0;
	mask = make_mask(c, &count);
	m = (unsigned char *)&mask;
	ch = (unsigned char *)&c;
	ft_apply_mask(m, ch, count);
	mask = 0;
	while (count)
	{
		out[mask] = (char)ch[--count];
		mask++;
	}
	out[mask] = '\0';
	return (out);
}
