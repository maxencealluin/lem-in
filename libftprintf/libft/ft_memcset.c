/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 10:32:38 by malluin           #+#    #+#             */
/*   Updated: 2018/12/20 18:01:32 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memcset(int nb, char c)
{
	char	*cpy;
	int		i;

	i = 0;
	if (!(cpy = (char *)malloc(sizeof(char) * (nb + 1))))
		return (NULL);
	cpy[nb] = '\0';
	while (i < nb)
		cpy[i++] = c;
	return (cpy);
}
