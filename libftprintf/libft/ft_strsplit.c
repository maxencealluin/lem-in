/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:50:31 by malluin           #+#    #+#             */
/*   Updated: 2018/11/12 16:35:14 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	count_w(char const *s, char c)
{
	int l;

	l = 1;
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			break ;
		l++;
		while (*s && *s != c)
			s++;
	}
	l = l == 0 ? 1 : l;
	return (l);
}

static	int	count_let(int i, char c, char const *s)
{
	int len;

	len = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		len++;
	}
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		w;
	int		j;

	i = 0;
	w = 0;
	if (!s || !(tab = (char **)malloc(sizeof(char *) * ((count_w(s, c) + 1)))))
		return (0);
	while (s[i])
	{
		j = 0;
		while (s[i] && s[i] == c)
			i++;
		if (!(tab[w] = (char *)malloc(sizeof(char) * (count_let(i, c, s) + 1))))
			return (0);
		while (s[i] && s[i] != c)
			tab[w][j++] = s[i++];
		tab[w++][j] = '\0';
		tab[w - 1] = j == 0 ? 0 : tab[w - 1];
		while (s[i] && s[i] == c)
			i++;
	}
	tab[w] = 0;
	return (tab);
}
