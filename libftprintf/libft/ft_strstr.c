/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 12:11:39 by malluin           #+#    #+#             */
/*   Updated: 2018/11/14 11:18:26 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;

	if (!(*needle))
		return ((char *)(haystack));
	while (*haystack)
	{
		i = 0;
		while (haystack[i] == needle[i])
		{
			i++;
			if (needle[i] == '\0')
				return ((char *)(haystack));
		}
		haystack++;
	}
	return (NULL);
}
