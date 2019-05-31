/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:34:42 by malluin           #+#    #+#             */
/*   Updated: 2018/11/08 17:14:53 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*ptr;
	size_t	i;

	if (!(ptr = (void *)malloc(size)))
		return (NULL);
	i = 0;
	while (i < size)
		((char*)(ptr))[i++] = 0;
	return (ptr);
}
