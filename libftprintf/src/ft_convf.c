/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 16:06:00 by malluin           #+#    #+#             */
/*   Updated: 2019/03/20 10:50:44 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	free_double(t_double **doub)
{
	if (doub)
	{
		free((*doub)->mantbin);
		free((*doub)->result);
		free((*doub));
	}
}

void	ft_float(t_output *out, t_keys *lst, va_list *ap)
{
	t_double *doub;

	if (!(doub = (t_double *)malloc(sizeof(t_double))))
		exit(-1);
	(void)out;
	if (ft_strstr(lst->size, "L") == NULL)
		lst->content.f = va_arg(*ap, double);
	else
		lst->content.lf = va_arg(*ap, long double);
	doub = ft_strstr(lst->size, "L") == NULL ? double_byte(lst->content.f, doub)
		: ldouble_byte(lst->content.lf, doub);
	lst->res = ft_strdup(doub->result);
	if (lst->res[0] != 'n' && lst->res[0] != 'i')
		ft_fprecision(lst, 6);
	if ((ft_strstr(lst->options, "#") != NULL
		&& ft_strcmp(lst->res, "inf") != 0) && ft_strcmp(lst->res, "nan") != 0)
		ft_diese(lst);
	if (doub->sign == 1 && (ft_strcmp(lst->res, "inf") == 0))
		lst->res = ft_insert(&lst->res, lst->res, "-");
	ft_align(lst);
	if (lst->conv == 'F' && (ft_strstr(lst->res, "nan") != NULL
		|| ft_strstr(lst->res, "inf") != NULL))
		lst->res = ft_strupcase(lst->res);
	free_double(&doub);
}

int		ft_apply_zero(t_keys *lst)
{
	if (ft_tolower(lst->conv) == 'f' && (ft_strstr(lst->options, "0") != NULL))
	{
		if (ft_strcmp("inf", lst->res) == 0 || ft_strcmp("nan", lst->res)
		== 0 || ft_strcmp(lst->res, "-nan") == 0
		|| ft_strcmp(lst->res, "-inf") == 0)
			return (0);
		return (1);
	}
	if ((ft_strstr(lst->options, "0") != NULL
		&& ((ft_strstr(lst->options, ".") == NULL || lst->conv == 'c'
		|| lst->conv == 's') || !ft_strchr("cCspDdioOuUxXfFb", lst->conv))))
		return (1);
	return (0);
}
