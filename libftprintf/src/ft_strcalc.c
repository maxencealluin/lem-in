/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcalc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 18:42:26 by malluin           #+#    #+#             */
/*   Updated: 2019/01/07 14:22:13 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_stradd(char *s1, char *s2, int base)
{
	char	*result;
	short	res;
	short	carry;
	short	i;
	short	j;

	i = ft_imax(ft_strlen(s1), ft_strlen(s2)) - 1;
	j = ft_imin(ft_strlen(s1), ft_strlen(s2)) - 1;
	if (ft_strlen(s2) > ft_strlen(s1))
		ft_pswap(&s2, &s1);
	result = ft_strxdup(s1, i + 2);
	carry = 0;
	while (i >= 0 || carry == 1)
	{
		if (i >= 0)
			res = j >= 0 ? s1[i] - 96 + s2[j] + carry : s1[i] + carry - 48;
		j--;
		carry = res >= base ? 1 : 0;
		res = res >= base ? res - base : res;
		if (i >= 0)
			result[i--] = res + 48;
		else if ((carry = 0) == 0)
			result = ft_insert(&result, result, "1");
	}
	return (result);
}

char	*ft_strmul(char *s1, char *s2, int base)
{
	char	*res;
	char	*tmp;
	short	i;
	short	j;

	i = ft_imax(ft_strlen(s1), ft_strlen(s2)) - 1;
	if (ft_strlen(s2) > ft_strlen(s1))
		ft_pswap(&s2, &s1);
	s2 = ft_strdup(s2);
	if ((s1[0] == '0' && s1[1] == '\0') || (s2[0] == '0' && s2[1] == '\0'))
		return (res = ft_strdup("0"));
	res = ft_strxdup("", ft_strlen(s1) + ft_strlen(s2) + 2);
	while (i-- >= 0)
	{
		j = -1;
		while (++j < (int)(s1[i + 1]) - 48)
		{
			tmp = res;
			res = ft_stradd(s2, res, base);
			free(tmp);
		}
		s2 = ft_insert(&s2, s2 + ft_strlen(s2), "0");
	}
	free(s2);
	return (res);
}

char	*bin_to_dec(char *nb)
{
	char	*mult;
	char	*tmp;
	char	*res;
	short	i;

	i = ft_strlen(nb) - 1;
	mult = ft_strdup("1");
	res = ft_strdup("0");
	while (i >= 0)
	{
		tmp = res;
		if (nb[i--] == '1')
		{
			res = ft_stradd(res, mult, 10);
			free(tmp);
		}
		tmp = mult;
		mult = ft_strmul(mult, "2", 10);
		free(tmp);
	}
	free(mult);
	return (res);
}

char	*ft_strdecdivtwo(char *s1, size_t i, int carry, int calc)
{
	char	*res;
	char	*tmp;
	size_t	len;

	len = ft_strlen(s1);
	res = ft_strdup("");
	while ((i < len || carry != 0) && i < 2000)
	{
		i = s1[i] == '.' ? i + 1 : i;
		if (s1[i] == '.')
			continue ;
		carry = carry * 10;
		calc = i < len ? (s1[i] - 48 + carry) / 2 : carry / 2;
		if ((i == len || (i > 0 && s1[i - 1] == '.')) && !ft_strchr(res, '.'))
			res = ft_insert(&res, res + ft_strlen(res), ".");
		if (!(i == 0 && calc == 0) || res[0] != '.')
		{
			tmp = ft_itoa(calc);
			res = ft_insert(&res, res + ft_strlen(res), tmp);
			free(tmp);
		}
		carry = i < len ? ((s1[i] - 48) + carry) % 2 : carry % 2;
		i++;
	}
	return (res);
}
