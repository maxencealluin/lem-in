/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 10:32:38 by malluin           #+#    #+#             */
/*   Updated: 2019/03/20 10:50:19 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_to(char *str, char c)
{
	int		i;
	int		j;
	char	*cpy;

	i = 0;
	j = 0;
	while (str[i] && str[i] != c)
		i++;
	if (!(cpy = (char *)malloc(sizeof(char) * (i + 1))))
		exit(-1);
	while (j < i)
	{
		cpy[j] = str[j];
		j++;
	}
	cpy[j] = '\0';
	return (cpy);
}

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	int		i;

	i = 0;
	if (!(cpy = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	while (s1[i] != '\0')
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
