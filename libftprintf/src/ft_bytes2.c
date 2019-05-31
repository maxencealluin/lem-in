/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bytes2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 15:47:31 by malluin           #+#    #+#             */
/*   Updated: 2019/03/03 15:34:07 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static t_double	*inf_nan(t_double *doub)
{
	int i;

	i = 0;
	doub = calc_exp(doub);
	doub->result = ft_strdup("inf");
	while (doub->mantbin[i])
		if (doub->mantbin[i++] == '1')
		{
			free(doub->result);
			doub->result = ft_strdup("nan");
			return (doub);
		}
	return (doub);
}

static t_double	*inf_nan_ldbl(t_double *doub)
{
	int i;

	i = 1;
	doub = calc_exp(doub);
	doub->result = ft_strdup("inf");
	while (doub->mantbin[i])
		if (doub->mantbin[i++] == '1')
		{
			free(doub->result);
			doub->result = ft_strdup("nan");
			return (doub);
		}
	return (doub);
}

t_double		*double_byte(double f, t_double *doub)
{
	unsigned char	*byte;
	char			*tmp;
	char			*tmp2;

	byte = conv_bytes_double(f);
	doub->sign = byte[0] == '1' ? 1 : 0;
	tmp = ft_strdup((char *)&byte[1]);
	tmp[11] = '\0';
	tmp2 = ft_convert_base(tmp, "01", "0123456789");
	doub->expnb = ft_atoi(tmp2);
	free(tmp2);
	doub->expnb -= ft_power(2, ft_strlen(tmp) - 1) - 1;
	ft_strdel(&tmp);
	doub->mantbin = ft_strdup((char *)&byte[12]);
	if (ft_strchr((const char *)byte, '1') == NULL)
		doub->result = ft_strdup("0.");
	else if (doub->expnb >= 1024)
		doub = inf_nan(doub);
	else
		doub = (doub->expnb >= 0) ? double_convert_pos(doub, 1)
			: double_convert_neg(doub, 1);
	free(byte);
	return (doub);
}

t_double		*ldouble_byte(long double f, t_double *doub)
{
	unsigned char	*byte;
	char			*tmp;
	char			*tmp2;

	byte = conv_bytes_ldouble(f);
	doub->sign = byte[0] == '1' ? 1 : 0;
	tmp = ft_strdup((char *)&byte[1]);
	tmp[15] = '\0';
	tmp2 = ft_convert_base(tmp, "01", "0123456789");
	doub->expnb = ft_atoi(tmp2);
	free(tmp2);
	doub->expnb -= ft_power(2, ft_strlen(tmp) - 1) - 1;
	ft_strdel(&tmp);
	doub->mantbin = ft_strdup((char *)&byte[16]);
	if (ft_strchr((const char *)byte, '1') == NULL)
		doub->result = ft_strdup("0.");
	else if (doub->expnb >= 16384)
		doub = inf_nan_ldbl(doub);
	else
		doub = (doub->expnb >= 0) ? double_convert_pos(doub, 0)
		: double_convert_neg(doub, 0);
	free(byte);
	return (doub);
}

void			ft_strround(char **s, short prec)
{
	int		i;
	int		carry;
	short	save;

	save = prec;
	carry = 0;
	i = ft_strstr(*s, ".") - *s + 1;
	if ((*s)[i + prec] >= '5' && (*s)[i + prec] <= '9')
		carry = 1;
	while (carry == 1)
	{
		prec = (*s)[i + --prec] == '.' ? prec - 1 : prec;
		(*s)[i + prec] += carry;
		carry = 0;
		if ((*s)[i + prec] == ':')
		{
			(*s)[i + prec] = '0';
			carry = 1;
		}
	}
	if (save == 0)
		(*s)[i + save - 1] = '\0';
	else
		(*s)[i + save] = '\0';
}
