/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnussbau <fnussbau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 11:17:04 by fnussbau          #+#    #+#             */
/*   Updated: 2019/01/08 17:04:16 by fnussbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"
#include <wchar.h>

char	*ft_wstr(wchar_t *str)
{
	int		len;
	char	*out;
	char	*tmp;
	char	*tmp2;

	len = 0;
	out = NULL;
	while (str && str[len])
	{
		tmp2 = out;
		tmp = ft_wchar((unsigned int)str[len]);
		out = ft_strjoin(out, tmp);
		if (tmp2 != NULL)
			ft_strdel(&tmp2);
		ft_strdel(&tmp);
		len++;
	}
	if (out == NULL)
		out = ft_strdup("");
	return (out);
}
