/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bytes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 18:45:00 by malluin           #+#    #+#             */
/*   Updated: 2019/01/07 19:44:54 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_double		*calc_exp(t_double *doub)
{
	int i;

	i = 0;
	i = ft_strlen(doub->mantbin);
	while (i > 0 && doub->mantbin[i - 1] != '1')
		i--;
	doub->dot = i;
	return (doub);
}

unsigned char	*conv_bytes_double(double f)
{
	unsigned char	*byte;
	unsigned char	*p;
	int				i;

	if (!(byte = (unsigned char *)malloc(sizeof(unsigned char) * 65)))
		exit(-1);
	i = 0;
	p = (unsigned char *)&f;
	while (i < 64)
	{
		byte[i] = (p[7 - i / 8] >> (7 - i % 8)) & 1 ? '1' : '0';
		i++;
	}
	byte[i] = '\0';
	return (byte);
}

unsigned char	*conv_bytes_ldouble(long double f)
{
	unsigned char	*byte;
	unsigned char	*p;
	int				i;

	if (!(byte = (unsigned char *)malloc(sizeof(unsigned char) * 81)))
		exit(-1);
	i = 0;
	p = (unsigned char *)&f;
	while (i < 80)
	{
		byte[i] = (p[9 - i / 8] >> (7 - i % 8)) & 1 ? '1' : '0';
		i++;
	}
	byte[i] = '\0';
	return (byte);
}

t_double		*double_convert_pos(t_double *doub, int z)
{
	if (z == 1)
		doub->mantbin = ft_insert(&doub->mantbin, doub->mantbin, "1");
	doub = calc_exp(doub);
	doub->mantbin[doub->dot] = '\0';
	doub->result = bin_to_dec(doub->mantbin);
	if (doub->dot - doub->expnb - 1 > 0)
		doub->result = ft_strnegpower(&doub->result, doub->dot -
			doub->expnb - 1);
	else
		doub->result = ft_strpower(&doub->result, doub->expnb - doub->dot + 1);
	if (doub->sign == 1)
		doub->result = ft_insert(&doub->result, doub->result, "-");
	return (doub);
}

t_double		*double_convert_neg(t_double *doub, int z)
{
	if (z == 1)
		doub->mantbin = ft_insert(&doub->mantbin, doub->mantbin, "1");
	doub = calc_exp(doub);
	doub->mantbin[doub->dot] = '\0';
	doub->result = bin_to_dec(doub->mantbin);
	doub->result = ft_strnegpower(&doub->result, doub->dot - doub->expnb - 1);
	if (doub->result[0] == '.')
		doub->result = ft_insert(&doub->result, doub->result, "0");
	if (doub->sign == 1)
		doub->result = ft_insert(&doub->result, doub->result, "-");
	return (doub);
}
