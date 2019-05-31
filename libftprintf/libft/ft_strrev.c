/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnussbau <fnussbau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 17:20:40 by fnussbau          #+#    #+#             */
/*   Updated: 2018/11/16 17:37:40 by fnussbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		length;
	int		k;
	char	tmp;

	length = 0;
	while (str[length] != '\0')
	{
		++length;
	}
	length = length - 1;
	k = 0;
	while (k <= (length - 1) / 2)
	{
		tmp = str[k];
		str[k] = str[length - k];
		str[length - k] = tmp;
		++k;
	}
	return (str);
}
