/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnussbau <fnussbau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 09:24:41 by fnussbau          #+#    #+#             */
/*   Updated: 2018/12/12 09:28:53 by fnussbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_atol(const char *nptr)
{
	long	res;
	int		i;
	int		signe;

	signe = 1;
	i = 0;
	res = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
		if (nptr[i++] == '-')
			signe = -1;
	while (nptr[i] >= 48 && nptr[i] <= 57)
		res = res * 10 + (nptr[i++] - 48) * signe;
	return (res);
}
