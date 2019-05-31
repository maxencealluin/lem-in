/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:55:59 by malluin           #+#    #+#             */
/*   Updated: 2019/03/20 14:56:55 by fnussbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdlib.h>

int		findeol(char *buff, int sens)
{
	int j;

	j = 0;
	if (sens == 0)
	{
		while (buff[j] == '\0' && j < BUFF_SIZE_GNL)
			j++;
		return (j);
	}
	else if (sens == 1)
	{
		while (j < BUFF_SIZE_GNL)
			if (buff[j++] == '\n')
				return (j - 1);
		return (BUFF_SIZE_GNL);
	}
	else if (sens == 2)
	{
		while (j < BUFF_SIZE_GNL)
			if (buff[j++] != '\0')
				return (1);
		return (0);
	}
	return (-1);
}

char	*allocate(char *buff, char *tmp2, int b, int e)
{
	char	*tmp;

	if (!(tmp = (char *)malloc(sizeof(char) * (e - b + 1 + ft_strlen(tmp2)))))
		return (0);
	ft_memmove(tmp, tmp2, ft_strlen(tmp2));
	ft_memmove((tmp + ft_strlen(tmp2)), buff + b, (e - b));
	(tmp + ft_strlen(tmp2))[e - b] = '\0';
	free(tmp2);
	tmp2 = ft_strdup(tmp);
	free(tmp);
	return (tmp2);
}

int		read_next(const int fd, char **line, t_blist *lst, int out)
{
	int				b;
	int				e;
	char			*tmp2;

	tmp2 = ft_strdup("");
	while (out == 0)
	{
		if (findeol(lst->buff, 2) == 0)
			if (((lst->ret = read(fd, lst->buff, BUFF_SIZE_GNL)) == -1)
				|| lst->buff[0] == '\0')
				return (ft_del_return(&tmp2));
		b = findeol(lst->buff, 0);
		e = findeol(lst->buff, 1) > lst->ret ? lst->ret : findeol(lst->buff, 1);
		if (lst->ret == 0)
			break ;
		if (lst->buff[e] == '\n' || (lst->ret == e && lst->ret < BUFF_SIZE_GNL))
			out = 1;
		tmp2 = allocate(lst->buff, tmp2, b, e);
		ft_bzero(lst->buff + b, e - b + (lst->buff[e] == '\n'));
	}
	*line = ft_strdup(tmp2);
	ft_memdel((void **)&tmp2);
	return (lst->ret);
}

t_blist	*new_node(const int fd)
{
	t_blist	*lst;

	if (!(lst = (t_blist *)malloc(sizeof(t_blist))))
		return (0);
	lst->fd = fd;
	ft_bzero(lst->buff, BUFF_SIZE_GNL);
	lst->next = NULL;
	return (lst);
}

int		get_next_line(const int fd, char **line)
{
	static	t_blist	*blst;
	t_blist			*lst;
	t_blist			*tmp;
	int				res;

	if (fd == -1 || BUFF_SIZE_GNL <= 0)
		return (-1);
	if (!blst)
		blst = new_node(fd);
	lst = blst;
	while (lst->fd != fd)
	{
		tmp = lst;
		lst = lst->next;
		if (!lst)
		{
			lst = new_node(fd);
			tmp->next = lst;
		}
	}
	res = read_next(fd, line, lst, 0);
	if (res > 0 || (res == 0 && **line))
		return (1);
	res = (res == -1) ? res : 0;
	return (res);
}
