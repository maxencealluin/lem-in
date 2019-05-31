/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 15:59:59 by malluin           #+#    #+#             */
/*   Updated: 2019/01/29 10:57:47 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	free_lst(t_keys *lst)
{
	free(lst->options);
	free(lst->prec);
	free(lst->size);
	free(lst->origin);
	free(lst->res);
	free(lst);
}

void		free_all(t_output *out)
{
	t_keys	*lst;
	t_keys	*tmp;

	lst = out->lst;
	tmp = lst;
	while (lst)
	{
		tmp = lst->next;
		free_lst(lst);
		lst = tmp;
	}
	free(out->fmt);
	free(out->result);
	free(out->ref->options);
	free(out->ref->size);
	free(out->ref->conv);
	free(out->ref);
	free(out);
}
