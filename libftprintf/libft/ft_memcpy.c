/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 12:54:57 by malluin           #+#    #+#             */
/*   Updated: 2018/11/14 11:09:14 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*src2;
	char		*dst2;
	size_t		i;

	src2 = (const char *)(src);
	dst2 = (char *)(dst);
	i = 0;
	while (i < n)
	{
		dst2[i] = (unsigned char)(src2[i]);
		i++;
	}
	return (dst);
}
