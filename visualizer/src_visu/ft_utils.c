/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 13:56:28 by malluin           #+#    #+#             */
/*   Updated: 2019/02/26 16:17:17 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	go_next(int *idx, t_lst **read_lst)
{
	*read_lst = (*read_lst)->next;
	*idx = 0;
}

char	*ft_strdup_to_count(char *str, char c, int *z)
{
	int		i;
	int		j;
	char	*cpy;

	i = 0;
	j = 0;
	while (str[i] && str[i] != c)
		i++;
	*z += i;
	if (!(cpy = (char *)malloc(sizeof(char) * (i + 1))))
		exit(-1);
	while (j < i)
	{
		cpy[j] = str[j];
		j++;
	}
	cpy[j] = '\0';
	return (cpy);
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(-1);
}
