/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 11:18:06 by malluin           #+#    #+#             */
/*   Updated: 2019/01/08 15:50:38 by fnussbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "conv.h"

static t_keys	*initialize(const char *format, t_output *out)
{
	if (!format)
		return (NULL);
	out->lst = NULL;
	out->fmt = ft_strdup(format);
	out->ref = set_refs();
	out->lst = scan_input(format, out->lst, out->ref);
	out->result = NULL;
	return (out->lst);
}

void			conv_args(t_output *out, t_keys *lst, va_list *ap)
{
	int			i;
	t_keys		*tmp;

	tmp = lst;
	while (tmp)
	{
		i = 0;
		while (i < 6)
		{
			if (ft_strchr(out->conv[i].key, tmp->conv) != NULL)
			{
				out->conv[i].func(out, tmp, ap);
				break ;
			}
			i++;
		}
		if (i == 6)
		{
			tmp->res = ft_strnew(2);
			tmp->res[0] = tmp->conv;
			tmp->res[1] = '\0';
			ft_align(tmp);
		}
		tmp = tmp->next;
	}
}

int				sum_blanks(t_keys *lst)
{
	int c;

	c = 0;
	while (lst)
	{
		c += lst->is_blank;
		lst = lst->next;
	}
	return (c);
}

int				ft_printf(const char *format, ...)
{
	t_output	*out;
	t_keys		*lst;
	va_list		ap;
	t_color		*color;
	int			ret;

	if (ft_strcmp(format, "%") == 0)
		return (0);
	if (!(out = (t_output *)malloc(sizeof(t_output))))
		return (0);
	lst = initialize(format, out);
	out->conv = g_conv;
	out->size = g_size;
	color = g_color;
	va_start(ap, format);
	conv_args(out, lst, &ap);
	assemble_res(out);
	out->result = ft_color(out->result, color);
	ft_putfinal(out->result, out->lst);
	ret = ft_strlen(out->result) + sum_blanks(lst);
	va_end(ap);
	free_all(out);
	return (ret);
}
