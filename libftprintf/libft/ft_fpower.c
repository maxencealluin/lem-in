/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fpower.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:52:21 by malluin           #+#    #+#             */
/*   Updated: 2018/12/17 13:53:27 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_fpower(double nb, int power)
{
	if (power == 0.)
		return (1.);
	else if (power == 1.)
		return (nb);
	return (nb * ft_fpower(nb, power - 1.));
}
