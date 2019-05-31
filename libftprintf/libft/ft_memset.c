/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 12:24:52 by malluin           #+#    #+#             */
/*   Updated: 2018/11/14 11:09:32 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len)
{
	char			*str;
	size_t			i;
	unsigned char	d;

	i = 0;
	d = (unsigned char)(c);
	str = (char *)(b);
	while (i < len)
		str[i++] = d;
	return (b);
}
