/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:09:50 by malluin           #+#    #+#             */
/*   Updated: 2019/01/07 15:33:19 by fnussbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*cont;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	while (s1 && s1[i])
		i++;
	while (s2 && s2[j++])
		i++;
	if (!(cont = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	j = 0;
	i = 0;
	while (s1 && s1[j++])
		cont[i++] = s1[j - 1];
	j = 0;
	while (s2 && s2[j++])
		cont[i++] = s2[j - 1];
	cont[i] = '\0';
	return (cont);
}
