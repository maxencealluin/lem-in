/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llpower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:52:21 by malluin           #+#    #+#             */
/*   Updated: 2019/01/07 14:00:01 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long	ft_llpower(long long nb, int power)
{
	if (power == 0)
		return (1);
	else if (power == 1)
		return (nb);
	return (nb * ft_llpower(nb, power - 1));
}
