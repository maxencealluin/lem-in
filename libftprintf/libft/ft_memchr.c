/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 14:26:15 by malluin           #+#    #+#             */
/*   Updated: 2018/11/14 11:07:32 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char		*str;
	size_t			i;
	void			*ptr;

	i = 0;
	str = (const char *)(s);
	while (i < n)
	{
		if ((unsigned char)(str[i]) == (unsigned char)(c))
		{
			ptr = (void *)(s + i);
			return (ptr);
		}
		i++;
	}
	return (NULL);
}
