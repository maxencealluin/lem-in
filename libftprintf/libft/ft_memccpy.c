/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 13:51:16 by malluin           #+#    #+#             */
/*   Updated: 2018/11/07 18:10:13 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	const char		*src2;
	char			*dst2;

	i = 0;
	src2 = (char *)(src);
	dst2 = (char *)(dst);
	while (i < n)
	{
		dst2[i] = (unsigned char)(src2[i]);
		i++;
		if ((unsigned char)(src2[i - 1]) == (unsigned char)(c))
			return (dst + i);
	}
	return (NULL);
}
