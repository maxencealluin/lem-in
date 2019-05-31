/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:04:59 by malluin           #+#    #+#             */
/*   Updated: 2019/01/03 14:07:09 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*skip_to_per(char *fmt)
{
	while (*fmt && (*fmt != '%' || (*fmt == '%' && *(fmt + 1) == '%')))
	{
		while (*fmt && *fmt != '%')
			fmt++;
		while (*(fmt) == '%' && *(fmt + 1) == '%')
			fmt += 2;
	}
	return (fmt);
}

int		is_option(char c)
{
	if (c == '#' || c == ' ' || c == '+' || c == '-' || c == '0')
		return (1);
	if (c >= '0' && c <= '9')
		return (2);
	if (c == '.')
		return (3);
	if (c == 'l' || c == 'h' || c == 'L' || c == 'j' || c == 'z')
		return (4);
	return (0);
}

int		is_options(char c, t_ref *ref)
{
	int k;
	int count;

	k = 0;
	count = 0;
	while (ref->options[k])
	{
		if (ref->options[k] == c)
			count++;
		k++;
	}
	return (count);
}

int		is_size(char c, t_ref *ref)
{
	int k;
	int count;

	k = 0;
	count = 0;
	while (ref->size[k])
	{
		if (ref->size[k] == c)
			count++;
		k++;
	}
	return (count);
}

int		is_conv(char c, t_ref *ref)
{
	int k;
	int count;

	k = 0;
	count = 0;
	while (ref->conv[k])
	{
		if (ref->conv[k] == c)
			count++;
		k++;
	}
	return (count);
}
