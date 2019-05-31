/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:23:16 by malluin           #+#    #+#             */
/*   Updated: 2018/11/12 16:32:43 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	char	*cpy;
	int		i;
	int		j;
	int		k;

	if (!s)
		return (NULL);
	i = 0;
	k = 0;
	j = 0;
	while (s[i] == 32 || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[j])
		j++;
	j--;
	while (s[j] == 32 || s[j] == '\n' || s[j] == '\t')
		j--;
	j = (j - i + 2) < 1 ? i : j;
	if (!(cpy = (char *)malloc(sizeof(char) * (j - i + 2))))
		return (0);
	while (i <= j)
		cpy[k++] = s[i++];
	cpy[k] = '\0';
	return (cpy);
}
