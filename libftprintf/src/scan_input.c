/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnussbau <fnussbau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 15:39:54 by fnussbau          #+#    #+#             */
/*   Updated: 2019/01/08 11:39:16 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

static int		parse_c(const char *str, t_keys *lst, t_ref *ref, int k)
{
	if (is_size(str[k], ref))
		while (str[k] && is_size(str[k], ref))
			lst->size = ft_strncat(lst->size, &str[k++], 1);
	else if (is_options(str[k], ref))
		while (str[k] && is_options(str[k], ref))
			lst->options = ft_strncat(lst->options, &str[k++], 1);
	else if (str[k] == '.')
	{
		lst->options = ft_strncat(lst->options, ".", 1);
		++k;
		free(lst->prec);
		lst->prec = ft_itoa(ft_atoi(&str[k]));
		while (ft_isdigit(str[k]))
			k++;
	}
	else if (ft_isdigit(str[k]))
	{
		lst->length = ft_atoi(&str[k]);
		while (ft_isdigit(str[k]))
			k++;
	}
	return (k);
}

t_keys			*scan_input(const char *str, t_keys *lst, t_ref *ref)
{
	int		k;
	int		j;
	t_keys	*tmp;

	k = -1;
	while (str[++k] != '\0')
		if (str[k] == '%')
		{
			j = 1;
			while (is_option(str[k + j++]))
				;
			tmp = lst_new_elem(j + 1);
			j = 1;
			while (is_option(str[k + j]))
				j += parse_c(&str[k + j], tmp, ref, 0);
			tmp->conv = str[k + j];
			k += j;
			lst = lst_add_end(lst, tmp);
			if (str[k] == '\0')
				break ;
		}
	return (lst);
}
