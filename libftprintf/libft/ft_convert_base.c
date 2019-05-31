/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 14:20:42 by malluin           #+#    #+#             */
/*   Updated: 2018/12/21 16:38:18 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		r_index(char *base_from, char nbr, int type)
{
	int index;

	index = 0;
	if (type == 0)
	{
		while (base_from[index] != '\0')
		{
			if (base_from[index] == (nbr))
				return (index);
			index++;
		}
		return (0);
	}
	else
	{
		while (base_from[index] != '\0')
			index++;
		return (index);
	}
}

long	ft_base_atoi(char *str, char *base_from, int base_power)
{
	long	nb;
	int		i;
	int		sign;

	sign = 1;
	i = 0;
	nb = 0;
	if (str[i] == 45 || str[i] == '+')
	{
		if (str[i++] == 45)
			sign = -1;
	}
	while (str[i] != '\0')
	{
		nb = nb * base_power + (r_index(base_from, str[i], 0)) * sign;
		i++;
	}
	return (nb);
}

int		check_base(char *nbr, char *base_from)
{
	int i;
	int j;
	int check;

	i = 0;
	j = 0;
	while (nbr[i] != '\0')
	{
		check = 0;
		while (base_from[j] != '\0' && check == 0)
		{
			if (nbr[i] == base_from[j] || nbr[i] == '-')
				check = 1;
			j++;
		}
		if (check == 0)
			return (0);
		i++;
		j = 0;
	}
	return (1);
}

char	*convert_base(long numb, char *base_to, char *nbr_conv, int k)
{
	int base_power;

	base_power = 0;
	while (base_to[base_power] != '\0')
		base_power++;
	if (numb < 0)
	{
		nbr_conv[0] = '-';
		numb = -numb;
		k++;
	}
	nbr_conv[k] = base_to[(numb % base_power)];
	if (numb / base_power > 0)
		nbr_conv = convert_base(numb / base_power, base_to, nbr_conv, k - 1);
	return (nbr_conv);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	numb;
	long	doub;
	char	*nb_conv;
	int		k;

	k = 0;
	if (!check_base(nbr, base_from))
		return (0);
	numb = ft_base_atoi(nbr, base_from, r_index(base_from, nbr[0], 1));
	doub = numb;
	while (doub / r_index(base_to, nbr[0], 1) != 0)
	{
		doub = doub / r_index(base_to, nbr[0], 1);
		k++;
	}
	if (!(nb_conv = (char *)malloc(sizeof(char) * (k + 2))))
		return (NULL);
	nb_conv[k + 1] = '\0';
	nb_conv = convert_base(numb, base_to, nb_conv, k);
	if (numb < 0)
		nb_conv[k + 2] = '\0';
	return (nb_conv);
}
