/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_buffer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 11:22:59 by malluin           #+#    #+#             */
/*   Updated: 2019/02/19 12:29:17 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#import "lem_in.h"

void	ft_print_buffer(t_s *s, char *str)
{
	while (*str)
	{
		s->buff[s->idx++] = *(str++);
		if (s->idx == BUFF_SIZE)
		{
			write(1, s->buff, BUFF_SIZE);
			s->idx = 0;
			ft_bzero(s->buff, BUFF_SIZE);
		}
	}
}

void	ft_putnbr_buffer(t_s *s, int n)
{
	char tmp;

	if (n == -2147483648)
	{
		ft_print_buffer(s, "-214748364");
		n = 8;
	}
	if (n < 0)
	{
		ft_print_buffer(s, "-");
		n = -n;
	}
	if (n / 10 > 0)
		ft_putnbr_buffer(s, n / 10);
	tmp = n % 10 + 48;
	s->buff[s->idx++] = tmp;
	if (s->idx == BUFF_SIZE)
	{
		write(1, s->buff, BUFF_SIZE);
		s->idx = 0;
		ft_bzero(s->buff, BUFF_SIZE);
	}
}
