/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcalc2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 15:54:52 by malluin           #+#    #+#             */
/*   Updated: 2019/01/07 19:20:52 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strnegpower(char **s, int nb)
{
	int		i;
	char	*tmp;
	int		len;

	tmp = *s;
	i = 0;
	while (i++ < nb)
	{
		tmp = *s;
		*s = ft_strdecdivtwo(*s, 0, 0, 0);
		free(tmp);
	}
	i = 0;
	while ((*s)[i] == '0')
		i++;
	len = ft_strlen((*s) + i);
	ft_memmove(*s, (*s) + i, len);
	(*s)[len] = '\0';
	return (*s);
}

char	*ft_strpower(char **s, int nb)
{
	int		i;
	int		pwr;
	char	*tmp;
	char	*str;

	i = 0;
	while (i < nb)
	{
		tmp = *s;
		pwr = nb - i >= 62 ? 62 : nb - i;
		str = ft_lltoa(ft_llpower((long long)2, pwr));
		*s = ft_strmul(*s, str, 10);
		i += pwr;
		free(str);
		free(tmp);
	}
	tmp = *s;
	*s = ft_strjoin(*s, ".");
	free(tmp);
	return (*s);
}
