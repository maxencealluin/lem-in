/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnussbau <fnussbau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 14:24:09 by fnussbau          #+#    #+#             */
/*   Updated: 2019/01/08 17:06:39 by fnussbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char				*ft_color(char *str, t_color *color)
{
	int		k;
	char	*tmp;
	char	*tmp2;
	int		len;

	k = 0;
	while (color[k].ref[0] != '\0')
	{
		while (ft_strstr(str, color[k].ref) != NULL)
		{
			str = ft_insert(&str, ft_strstr(str, color[k].ref), color[k].code);
			tmp = ft_strstr(str, color[k].ref) + ft_strlen(color[k].ref);
			len = ft_strlen(tmp);
			tmp2 = ft_strstr(str, color[k].ref);
			ft_memmove(tmp2, tmp, len);
			tmp2[len] = '\0';
		}
		k++;
	}
	return (str);
}
