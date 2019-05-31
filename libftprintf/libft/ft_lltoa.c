/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 10:36:35 by malluin           #+#    #+#             */
/*   Updated: 2018/12/20 18:05:55 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static long long	ft_abs(long long nb)
{
	nb = nb < 0 ? -nb : nb;
	return (nb);
}

char				*ft_lltoa(long long n)
{
	char		*str;
	long long	i;
	short		len;

	len = 1;
	i = n;
	while (i / 10 != 0)
	{
		len++;
		i /= 10;
	}
	len = n < 0 ? len + 1 : len;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	str[len] = '\0';
	if (n < 0)
		str[0] = '-';
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		str[len-- - 1] = ft_abs(n % 10) + 48;
		n /= 10;
	}
	return (str);
}
