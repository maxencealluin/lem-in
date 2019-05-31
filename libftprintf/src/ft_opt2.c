/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 11:33:13 by malluin           #+#    #+#             */
/*   Updated: 2019/03/20 10:51:31 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*zero_padding(char **str, int length)
{
	char	*cat;
	int		i;
	int		b;
	int		padding;

	i = 0;
	b = 0;
	padding = length - ft_strlen(*str);
	cat = ft_memcset(padding, '0');
	b = (**str == '-' || **str == '+' || **str == ' ') ? b + 1 : b;
	b = (**str == '0' && ft_tolower(*(*str + 1)) == 'x') ? b + 2 : b;
	*str = ft_insert(str, *str + b, cat);
	free(cat);
	return (*str);
}

void	ft_diese(t_keys *lst)
{
	if (lst->conv == 'o')
	{
		if (lst->res && lst->res[0] != '0')
			lst->res = ft_insert(&lst->res, lst->res, "0");
	}
	else if (lst->conv == 'x')
	{
		if (lst->res && lst->res[0] != '0')
			lst->res = ft_insert(&lst->res, lst->res, "0x");
	}
	else if (lst->conv == 'X')
	{
		if (lst->res && lst->res[0] != '0')
			lst->res = ft_insert(&lst->res, lst->res, "0X");
	}
	else if (lst->conv == 'f' || lst->conv == 'F')
	{
		if (ft_strchr(lst->res, '.') == NULL)
			lst->res = ft_insert(&lst->res, lst->res
				+ ft_strlen(lst->res), ".");
	}
}

void	ft_xoprecision(t_keys *l, int b)
{
	int		len;
	int		prec;
	char	*fill;

	if (ft_strchr(l->options, '#') != NULL)
		b = (l->conv == 'x' || l->conv == 'X')
			&& ft_strcmp("0", l->res) != 0 ? b + 2 : b;
	if (l->conv == 'p')
		b = 2;
	len = ft_strlen(l->res) - b - (ft_strcmp(l->res, "0x0") == 0);
	if (ft_strlen(l->res) >= 3)
		l->res[2] = (ft_strcmp(l->res, "0x0") == 0)
		&& (l->conv == 'p') ? '\0' : l->res[2];
	if (l->prec[0] == '\0')
		return ;
	prec = ft_atoi(l->prec);
	l->res[0] = (l->res[0] == '0' && l->res[1] == '\0') && prec == 0
		&& l->conv != 'p' ? '\0' : l->res[0];
	if (l->conv != 's')
		if (prec > len)
		{
			fill = ft_memcset(prec - len, '0');
			l->res = ft_insert(&l->res, l->res + b, fill);
			free(fill);
		}
}

void	ft_precision(t_keys *l)
{
	int		len;
	int		prec;
	int		b;
	char	*fill;

	b = 0;
	len = ft_strlen(l->res);
	if (l->prec[0] == '\0')
		return ;
	prec = ft_atoi(l->prec);
	if (ft_tolower(l->conv) == 's')
		if (len > prec)
			l->res[prec] = '\0';
	len = l->res[0] == '-' ? len - 1 : len;
	l->res[0] = l->res[0] == '0' && prec == 0
		&& l->conv != 'o' ? '\0' : l->res[0];
	l->res[0] = l->res[0] == '0' && prec == 0 && l->conv == 'o'
		&& ft_strstr(l->options, "#") == NULL ? '\0' : l->res[0];
	if (ft_tolower(l->conv) != 's')
		if (prec > len)
		{
			fill = ft_memcset(prec - len, '0');
			l->res = ft_insert(&l->res, l->res + (l->res[0] == '-'), fill);
			free(fill);
		}
}

void	ft_fprecision(t_keys *l, short prec)
{
	char	*fill;
	int		i;
	char	*tmp;

	i = 0;
	if (ft_strchr(l->options, '.') != NULL)
		prec = ft_atoi(l->prec);
	if (!ft_strchr(l->res, '.'))
	{
		fill = ft_memcset(prec, '0');
		l->res = ft_insert(&l->res, l->res + ft_strlen(l->res), fill);
		free(fill);
		return ;
	}
	fill = ft_strchr(l->res, '.') + 1;
	while (fill[i])
		i++;
	if (i >= prec)
		ft_strround(&l->res, prec);
	else
	{
		tmp = ft_memcset(prec - i, '0');
		l->res = ft_insert(&l->res, fill + i, tmp);
		free(tmp);
	}
}
