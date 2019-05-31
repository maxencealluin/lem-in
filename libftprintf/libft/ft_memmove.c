/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 14:06:53 by malluin           #+#    #+#             */
/*   Updated: 2018/11/14 11:08:36 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst2;
	const char	*src2;
	size_t		i;

	i = 0;
	dst2 = (char *)dst;
	src2 = (const char *)src;
	if (dst2 < src2)
	{
		ft_memcpy(dst, src, len);
	}
	else
	{
		while (len > 0)
		{
			dst2[len - 1] = (unsigned char)(src2[len - 1]);
			len--;
		}
	}
	return (dst);
}
