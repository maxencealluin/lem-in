/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 19:07:54 by malluin           #+#    #+#             */
/*   Updated: 2019/03/03 15:34:34 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_int(t_output *out, t_keys *lst, va_list *ap)
{
	(void)out;
	if (lst->conv == 'd' || lst->conv == 'i')
	{
		lst->content.d = va_arg(*ap, int);
		lst->res = ft_lltoa_base(lst->content.d, 10);
	}
	else
		lst->content.x = va_arg(*ap, unsigned int);
	if (lst->conv == 'o' || lst->conv == 'O')
		lst->res = ft_ulltoa_base(lst->content.x, 8);
	else if (lst->conv == 'u')
		lst->res = ft_ulltoa_base(lst->content.x, 10);
	else if (lst->conv == 'x')
		lst->res = ft_strlowcase(ft_ulltoa_base(lst->content.x, 16));
	else if (lst->conv == 'X')
		lst->res = ft_ulltoa_base(lst->content.x, 16);
	if ((lst->conv == 'o' || lst->conv == 'X' || lst->conv == 'x')
			&& ft_strstr(lst->options, "#") != NULL)
		ft_diese(lst);
	if (ft_strstr(lst->options, ".") != NULL && lst->conv != 'x'
			&& lst->conv != 'X')
		ft_precision(lst);
	else if (ft_strstr(lst->options, ".") != NULL)
		ft_xoprecision(lst, 0);
	ft_align(lst);
}

void	ft_l(t_output *out, t_keys *lst, va_list *ap)
{
	(void)out;
	if (lst->conv == 'd' || lst->conv == 'i')
	{
		lst->content.l = va_arg(*ap, long);
		lst->res = ft_lltoa_base(lst->content.l, 10);
	}
	else
		lst->content.ul = va_arg(*ap, unsigned long);
	if (lst->conv == 'o' || lst->conv == 'O')
		lst->res = ft_ulltoa_base(lst->content.ul, 8);
	else if (lst->conv == 'u')
		lst->res = ft_ulltoa_base(lst->content.ul, 10);
	else if (lst->conv == 'x')
		lst->res = ft_strlowcase(ft_ulltoa_base(lst->content.ul, 16));
	else if (lst->conv == 'X')
		lst->res = ft_ulltoa_base(lst->content.ul, 16);
	if ((lst->conv == 'o' || lst->conv == 'O' || lst->conv == 'X'
	|| lst->conv == 'x') && ft_strstr(lst->options, "#") != NULL)
		ft_diese(lst);
	if (ft_strstr(lst->options, ".") != NULL && lst->conv != 'x'
				&& lst->conv != 'X')
		ft_precision(lst);
	else if (ft_strstr(lst->options, ".") != NULL)
		ft_xoprecision(lst, 0);
	ft_align(lst);
}

void	ft_ll(t_output *out, t_keys *lst, va_list *ap)
{
	(void)out;
	if (lst->conv == 'd' || lst->conv == 'i')
	{
		lst->content.ll = va_arg(*ap, long long);
		lst->res = ft_lltoa_base(lst->content.ll, 10);
	}
	else
		lst->content.ull = va_arg(*ap, unsigned long long);
	if (lst->conv == 'o' || lst->conv == 'O')
		lst->res = ft_ulltoa_base(lst->content.ull, 8);
	else if (lst->conv == 'u')
		lst->res = ft_ulltoa_base(lst->content.ull, 10);
	else if (lst->conv == 'x')
		lst->res = ft_strlowcase(ft_ulltoa_base(lst->content.ull, 16));
	else if (lst->conv == 'X')
		lst->res = ft_ulltoa_base(lst->content.ull, 16);
	if ((lst->conv == 'o' || lst->conv == 'O' || lst->conv == 'X'
	|| lst->conv == 'x') && ft_strstr(lst->options, "#") != NULL)
		ft_diese(lst);
	if (ft_strstr(lst->options, ".") != NULL && lst->conv != 'x'
				&& lst->conv != 'X')
		ft_precision(lst);
	else if (ft_strstr(lst->options, ".") != NULL)
		ft_xoprecision(lst, 0);
	ft_align(lst);
}

void	ft_sh(t_output *out, t_keys *lst, va_list *ap)
{
	(void)out;
	if (lst->conv == 'd' || lst->conv == 'i')
	{
		lst->content.h = (short)va_arg(*ap, int);
		lst->res = ft_lltoa_base(lst->content.h, 10);
	}
	else
		lst->content.uh = (unsigned short)va_arg(*ap, unsigned int);
	if (lst->conv == 'o' || lst->conv == 'O')
		lst->res = ft_ulltoa_base(lst->content.uh, 8);
	else if (lst->conv == 'u')
		lst->res = ft_ulltoa_base(lst->content.uh, 10);
	else if (lst->conv == 'x')
		lst->res = ft_strlowcase(ft_ulltoa_base(lst->content.uh, 16));
	else if (lst->conv == 'X')
		lst->res = ft_ulltoa_base(lst->content.uh, 16);
	if ((lst->conv == 'o' || lst->conv == 'O' || lst->conv == 'X'
	|| lst->conv == 'x') && ft_strstr(lst->options, "#") != NULL)
		ft_diese(lst);
	if (ft_strstr(lst->options, ".") != NULL && lst->conv != 'x'
				&& lst->conv != 'X')
		ft_precision(lst);
	else if (ft_strstr(lst->options, ".") != NULL)
		ft_xoprecision(lst, 0);
	ft_align(lst);
}

void	ft_shsh(t_output *out, t_keys *lst, va_list *ap)
{
	(void)out;
	if (lst->conv == 'd' || lst->conv == 'i')
	{
		lst->content.h = (char)va_arg(*ap, int);
		lst->res = ft_lltoa_base(lst->content.h, 10);
	}
	else
		lst->content.uh = (unsigned char)va_arg(*ap, unsigned int);
	if (lst->conv == 'o' || lst->conv == 'O')
		lst->res = ft_ulltoa_base(lst->content.uh, 8);
	else if (lst->conv == 'u')
		lst->res = ft_ulltoa_base(lst->content.uh, 10);
	else if (lst->conv == 'x')
		lst->res = ft_strlowcase(ft_ulltoa_base(lst->content.uh, 16));
	else if (lst->conv == 'X')
		lst->res = ft_ulltoa_base(lst->content.uh, 16);
	if ((lst->conv == 'o' || lst->conv == 'O' || lst->conv == 'X'
	|| lst->conv == 'x') && ft_strstr(lst->options, "#") != NULL)
		ft_diese(lst);
	if (ft_strstr(lst->options, ".") != NULL && lst->conv != 'x'
				&& lst->conv != 'X')
		ft_precision(lst);
	else if (ft_strstr(lst->options, ".") != NULL)
		ft_xoprecision(lst, 0);
	ft_align(lst);
}
