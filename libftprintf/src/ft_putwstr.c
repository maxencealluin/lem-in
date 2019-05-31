/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnussbau <fnussbau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 11:46:29 by fnussbau          #+#    #+#             */
/*   Updated: 2018/12/19 12:31:08 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <unistd.h>
#include "libft.h"

void	ft_putwstr(char *s)
{
	int k;

	k = 0;
	if (s)
	{
		while (s[k] != '\0')
		{
			ft_putwchar((unsigned int)s[k]);
			k++;
		}
	}
}
