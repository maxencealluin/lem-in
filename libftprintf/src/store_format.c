/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnussbau <fnussbau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 10:20:10 by fnussbau          #+#    #+#             */
/*   Updated: 2019/01/08 16:00:40 by fnussbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_diouxx(t_output *out, t_keys *lst, va_list *ap)
{
	int i;

	i = 0;
	if (lst->conv == 'U' || lst->conv == 'O' || lst->conv == 'D')
	{
		lst->conv = ft_tolower(lst->conv);
		out->size[3].func(out, lst, ap);
		return ;
	}
	if (ft_strcmp(lst->size, "") == 0)
	{
		out->size[6].func(out, lst, ap);
		return ;
	}
	while (ft_strstr(lst->size, out->size[i].key) == 0 && i < 7)
		i++;
	if (i == 7)
	{
		out->size[6].func(out, lst, ap);
		return ;
	}
	out->size[i].func(out, lst, ap);
}

void	ft_string(t_output *out, t_keys *lst, va_list *ap)
{
	(void)out;
	if (ft_strcmp(lst->size, "l") == 0 || lst->conv == 'S')
	{
		lst->content.wstr = va_arg(*ap, wchar_t *);
		if (lst->content.wstr == NULL)
			lst->res = ft_strdup("(null)");
		else
			lst->res = ft_wstr(lst->content.wstr);
	}
	else
	{
		lst->conv = ft_tolower(lst->conv);
		lst->content.s = va_arg(*ap, char *);
		if (lst->content.s == NULL)
			lst->res = ft_strdup("(null)");
		else
			lst->res = ft_strdup(lst->content.s);
	}
	if (ft_strstr(lst->options, ".") != NULL)
		ft_precision(lst);
	ft_align(lst);
}

void	ft_char(t_output *out, t_keys *lst, va_list *ap)
{
	(void)out;
	if (ft_strcmp(lst->size, "l") == 0 || lst->conv == 'C')
	{
		lst->content.wchar = (unsigned int)va_arg(*ap, unsigned int);
		lst->res = ft_wchar(lst->content.wchar);
		lst->is_blank = lst->content.wchar == 0 ? 1 : 0;
		ft_align(lst);
		return ;
	}
	lst->conv = ft_tolower(lst->conv);
	lst->content.c = (char)va_arg(*ap, unsigned int);
	if (lst->content.c == 0)
	{
		lst->res = ft_strdup("\0");
		lst->is_blank = 1;
	}
	else
		lst->res = ft_memcset(1, lst->content.c);
	ft_align(lst);
}

void	ft_adr(t_output *out, t_keys *lst, va_list *ap)
{
	char	*tmp;

	(void)out;
	lst->content.p = va_arg(*ap, long);
	tmp = ft_ulltoa_base(lst->content.p, 16);
	lst->res = ft_strjoin("0x", ft_strlowcase(tmp));
	free(tmp);
	if (ft_strstr(lst->options, ".") != NULL)
		ft_xoprecision(lst, 0);
	ft_align(lst);
}

void	ft_bin(t_output *out, t_keys *lst, va_list *ap)
{
	char	*tmp;

	(void)out;
	lst->content.ll = va_arg(*ap, long);
	tmp = ft_lltoa_base(lst->content.ll, 2);
	lst->res = ft_strdup(tmp);
	free(tmp);
	ft_align(lst);
}
