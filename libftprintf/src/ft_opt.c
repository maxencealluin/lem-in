/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 13:41:21 by malluin           #+#    #+#             */
/*   Updated: 2019/03/03 15:37:31 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*plus_opt(char **str)
{
	if (!str)
		return (NULL);
	if (**str == '-' || ft_strcmp(*str, "nan") == 0
	|| ft_strcmp(*str, "inf") == 0 || ft_strcmp(*str, "-nan") == 0
	|| ft_strcmp(*str, "-inf") == 0)
		return (*str);
	*str = ft_insert(str, *str, "+");
	return (*str);
}

char	*space_opt(char **str)
{
	if (!str)
		return (NULL);
	if (**str == '-' || ft_strcmp(*str, "nan") == 0
	|| ft_strcmp(*str, "inf") == 0 || ft_strcmp(*str, "-nan") == 0
	|| ft_strcmp(*str, "-inf") == 0)
		return (*str);
	*str = ft_insert(str, *str, " ");
	return (*str);
}

char	*minus_padding(char **str, int length)
{
	char	*cat;
	int		i;
	int		len;
	int		padding;

	i = 0;
	len = ft_strlen(*str);
	padding = length - len;
	if (!(cat = (char *)malloc(sizeof(char) * (padding + 1))))
		return (NULL);
	while (i < padding)
		cat[i++] = ' ';
	cat[i] = '\0';
	*str = ft_insert(str, *str + len, cat);
	free(cat);
	return (*str);
}

char	*simple_padding(char **str, int length)
{
	char	*cat;
	int		i;
	int		padding;

	i = 0;
	padding = length - ft_strlen(*str);
	if (!(cat = (char *)malloc(sizeof(char) * (padding + 1))))
		return (NULL);
	while (i < padding)
		cat[i++] = ' ';
	cat[i] = '\0';
	*str = ft_insert(str, *str, cat);
	free(cat);
	return (*str);
}

void	ft_align(t_keys *lst)
{
	int		length;
	char	*str;

	length = lst->length;
	str = lst->res;
	if (!str)
		return ;
	if (lst->conv == 'd' || lst->conv == 'i' || lst->conv == 'f'
		|| lst->conv == 'F')
	{
		if (ft_strstr(lst->options, "+") != NULL)
			lst->res = plus_opt(&str);
		else if (ft_strstr(lst->options, " ") != NULL)
			lst->res = space_opt(&str);
	}
	if (ft_strlen(str) < (size_t)length)
	{
		if (ft_strstr(lst->options, "-") != NULL)
			lst->res = minus_padding(&str, length - lst->is_blank);
		else if (ft_apply_zero(lst))
			lst->res = zero_padding(&str, length - lst->is_blank);
		else
			lst->res = simple_padding(&str, length - lst->is_blank);
	}
}
