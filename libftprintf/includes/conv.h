/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnussbau <fnussbau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 08:49:11 by fnussbau          #+#    #+#             */
/*   Updated: 2019/01/08 11:11:22 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONV_H
# define CONV_H

t_func	g_size[] =
{
	{"ll", &ft_ll},
	{"j", &ft_ll},
	{"l", &ft_l},
	{"z", &ft_l},
	{"hh", &ft_shsh},
	{"h", &ft_sh},
	{"", &ft_int}
};

t_func	g_conv[] =
{
	{"DdioOuUxX", &ft_diouxx},
	{"cC", &ft_char},
	{"fF", &ft_float},
	{"sS", &ft_string},
	{"p", &ft_adr},
	{"b", &ft_bin}
};

t_color	g_color[] =
{
	{"{eoc}", "\e[0m"},
	{"{black}", "\e[0;30m"},
	{"{red}", "\e[0;31m"},
	{"{green}", "\e[0;32m"},
	{"{yellow}", "\e[0;33m"},
	{"{blue}", "\e[0;34m"},
	{"{magenta}", "\e[0;35m"},
	{"{cyan}", "\e[0;36m"},
	{"{light gray}", "\e[0;37m"},
	{"\0", "\0"}
};

#endif
