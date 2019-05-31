/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:45:22 by malluin           #+#    #+#             */
/*   Updated: 2019/03/03 15:29:50 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_insert(char **dest, char *target, char *src)
{
	char	*cpy;
	int		i;
	int		j;
	char	*begin;

	begin = *dest;
	i = 0;
	j = 0;
	if (!(cpy = (char *)malloc(sizeof(char) * (ft_strlen(src)
		+ ft_strlen(*dest) + 1))))
		return (NULL);
	while (*dest + j < target && (*dest)[j])
		cpy[i++] = (*dest)[j++];
	while (*src)
		cpy[i++] = *src++;
	while ((*dest)[j])
		cpy[i++] = (*dest)[j++];
	cpy[i] = '\0';
	free(begin);
	return (cpy);
}

char	*ft_nfinsert(char *dest, char *target, char *src)
{
	char	*cpy;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(cpy = (char *)malloc(sizeof(char) * (ft_strlen(src)
		+ ft_strlen(dest) + 1))))
		return (NULL);
	while (dest < target && (dest)[j])
		cpy[i++] = (dest)[j++];
	while (*src)
		cpy[i++] = *src++;
	while ((dest)[j])
		cpy[i++] = (dest)[j++];
	cpy[i] = '\0';
	return (cpy);
}
