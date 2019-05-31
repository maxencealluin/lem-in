/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 12:16:59 by malluin           #+#    #+#             */
/*   Updated: 2018/11/14 11:17:27 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	if (!(*needle))
		return ((char *)(haystack));
	while (haystack[j] && j < len)
	{
		i = 0;
		while (haystack[j + i] == needle[i] && (i + j) < len)
		{
			i++;
			if (needle[i] == '\0')
				return ((char *)(haystack + j));
		}
		j++;
	}
	return (NULL);
}
