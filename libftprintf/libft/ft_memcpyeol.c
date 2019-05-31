/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpyeol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:37:33 by malluin           #+#    #+#             */
/*   Updated: 2018/12/11 15:39:03 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpyeol(void *dst, const void *src, size_t n)
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
	dst2[i] = '\0';
	return (dst);
}
