/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_refs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnussbau <fnussbau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 12:07:08 by fnussbau          #+#    #+#             */
/*   Updated: 2019/01/03 15:38:53 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

t_ref	*set_refs(void)
{
	t_ref *ref;

	if (!(ref = (t_ref *)malloc(sizeof(t_ref))))
		return (NULL);
	if (!(ref->options = ft_strdup("+-#0 ")))
		return (NULL);
	if (!(ref->size = ft_strdup("hlLzj")))
	{
		free(ref->options);
		return (NULL);
	}
	if (!(ref->conv = ft_strdup("cCsSpDdioOuUxXfFb")))
	{
		free(ref->options);
		free(ref->size);
		return (NULL);
	}
	return (ref);
}
