/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fac_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnussbau <fnussbau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 15:37:41 by fnussbau          #+#    #+#             */
/*   Updated: 2018/12/12 15:37:44 by fnussbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

char	*fac_opt(t_keys *lst, t_ref *ref)
{
	int		k;
	int		j;
	char	opt[6];

	k = 0;
	j = 0;
	while (ref->options[k])
	{
		if (ft_strchr(lst->options, ref->options[k]))
		{
			opt[j] = ref->options[k];
			j++;
		}
		k++;
	}
	opt[j] = '\0';
	lst->options = ft_strcpy(lst->options, opt);
	return (lst->options);
}
