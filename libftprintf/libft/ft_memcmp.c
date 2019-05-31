/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 14:44:48 by malluin           #+#    #+#             */
/*   Updated: 2018/11/14 11:07:45 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*str1;
	const char	*str2;
	size_t		i;

	str1 = (const char *)(s1);
	str2 = (const char *)(s2);
	i = 0;
	while (i < n)
	{
		if ((unsigned char)(str1[i]) != (unsigned char)(str2[i]))
			return ((unsigned char)(str1[i]) - (unsigned char)(str2[i]));
		i++;
	}
	return (0);
}
