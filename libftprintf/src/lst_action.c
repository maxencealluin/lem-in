/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnussbau <fnussbau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 17:09:36 by fnussbau          #+#    #+#             */
/*   Updated: 2019/01/03 19:40:47 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

t_keys	*lst_new_elem(int size)
{
	t_keys *tmp;

	if (!(tmp = (t_keys *)malloc(sizeof(t_keys))))
		return (0);
	if (!(tmp->options = (char *)ft_memalloc(sizeof(char) * (size + 1))))
		return (0);
	if (!(tmp->size = (char *)ft_memalloc(sizeof(char) * (size + 1))))
		return (0);
	tmp->length = 0;
	tmp->content.ll = 0;
	tmp->origin = NULL;
	tmp->res = NULL;
	tmp->prec = ft_strdup("0");
	tmp->next = NULL;
	tmp->indice = -1;
	tmp->is_blank = 0;
	tmp->conv = '\0';
	return (tmp);
}

void	lst_free_elem(t_keys **lst)
{
	if (!lst)
		return ;
	free((*lst)->options);
	free((*lst)->size);
	free((*lst)->prec);
	free((*lst)->origin);
	free(*lst);
}

t_keys	*lst_add_end(t_keys *alst, t_keys *new)
{
	t_keys *tmp;

	if (new)
	{
		if (alst == NULL)
			alst = new;
		else
		{
			tmp = alst;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new;
		}
		return (alst);
	}
	return (alst);
}
