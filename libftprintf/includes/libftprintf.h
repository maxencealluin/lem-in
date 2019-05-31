/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 11:20:29 by malluin           #+#    #+#             */
/*   Updated: 2019/02/14 18:52:50 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include "libft.h"
# include "get_next_line.h"

typedef struct				s_double
{
	int						sign;
	char					*mantbin;
	int						expnb;
	int						dot;
	char					*result;
}							t_double;

typedef struct				s_ref
{
	char					*options;
	char					*size;
	char					*conv;
}							t_ref;

typedef union				u_type
{
	int						d;
	long					l;
	long long				ll;
	short					h;
	double					f;
	long double				lf;
	unsigned int			x;
	unsigned long			ul;
	unsigned long long		ull;
	unsigned short			uh;
	char					c;
	unsigned int			wchar;
	wchar_t					*wstr;
	long					p;
	char					*s;
}							t_type;

typedef struct				s_keys
{
	char					*options;
	int						length;
	char					*prec;
	char					*size;
	char					conv;
	char					*origin;
	t_type					content;
	char					*res;
	short					indice;
	short					is_blank;
	struct s_keys			*next;

}							t_keys;

struct s_func;

typedef struct				s_output
{
	t_keys					*lst;
	char					*fmt;
	char					*result;
	t_ref					*ref;
	struct s_func			*size;
	struct s_func			*conv;
	struct s_func			*opt;
}							t_output;

typedef struct				s_func
{
	char					key[12];
	void					(*func)(t_output *out, t_keys *lst, va_list *ap);
}							t_func;

typedef struct				s_color
{
	char					ref[20];
	char					code[20];
}							t_color;

int							ft_printf(const char *format, ...);
void						conv_args(t_output *out, t_keys *lst, va_list *ap);
char						*ft_color(char *str, t_color *color);
int							count_s(char *fmt);
int							is_options(char c, t_ref *ref);
int							is_size(char c, t_ref *ref);
int							is_conv(char c, t_ref *ref);
t_keys						*lst_new_elem(int size);
t_keys						*lst_add_end(t_keys *alst, t_keys *new);
char						*fac_opt(t_keys *lst, t_ref *ref);
t_keys						*scan_input(const char *str, t_keys *lst_key,
							t_ref *ref);
t_ref						*set_refs(void);
char						*skip_to_per(char *fmt);
int							is_option(char c);
int							is_type(char c);
void						ft_int(t_output *out, t_keys *lst, va_list *ap);
void						ft_l(t_output *out, t_keys *lst, va_list *ap);
void						ft_ll(t_output *out, t_keys *lst, va_list *ap);
void						ft_sh(t_output *out, t_keys *lst, va_list *ap);
void						ft_shsh(t_output *out, t_keys *lst, va_list *ap);
void						ft_j(t_output *out, t_keys *lst, va_list *ap);
void						ft_float(t_output *out, t_keys *lst, va_list *ap);
long						ft_atol(const char *nptr);
void						ft_diouxx(t_output *out, t_keys *lst, va_list *ap);
void						ft_string(t_output *out, t_keys *lst, va_list *ap);
void						ft_char(t_output *out, t_keys *lst, va_list *ap);
void						ft_adr(t_output *out, t_keys *lst, va_list *ap);
void						ft_bin(t_output *out, t_keys *lst, va_list *ap);
void						assemble_res(t_output *out);
void						print_args(t_output *out);
void						ft_align(t_keys *lst);
char						*zero_padding(char **str, int length);
void						ft_diese(t_keys *lst);
void						ft_precision(t_keys *lst);
char						*ft_lltoa_base(long long value, int base);
unsigned char				*conv_bytes_double(double f);
unsigned char				*conv_bytes_ldouble(long double f);
t_double					*double_byte(double f, t_double *doub);
t_double					*ldouble_byte(long double f, t_double *doub);
t_double					*double_convert_pos(t_double *doub, int z);
t_double					*double_convert_neg(t_double *doub, int z);
t_double					*calc_exp(t_double *doub);
char						*ft_stradd(char *s1, char *s2, int base);
char						*ft_strmul(char *s1, char *s2, int base);
char						*bin_to_dec(char *nb);
char						*ft_strdecdivtwo(char *s1, size_t i, int carry,
							int calc);
char						*ft_strnegpower(char **s, int nb);
char						*ft_strpower(char **s, int nb);
t_double					*converge_exp_neg(t_double *doub);
char						*ft_strnegpower(char **s, int nb);
char						*ft_strpower(char **s, int nb);
char						*ft_wstr(wchar_t *str);
char						*ft_wchar(unsigned int c);
char						*make_bit(long long origin);
void						ft_cplt(char *out);
void						ft_fprecision(t_keys *l, short prec);
void						ft_xoprecision(t_keys *l, int b);
char						*ft_ulltoa_base(unsigned long value, int base);
void						ft_putfinal(char *s, t_keys *lst);
int							make_mask(unsigned int c, int *count);
int							numbit(unsigned int c);
void						lst_free_elem(t_keys **lst);
void						ft_strround(char **s, short prec);
char						*ft_nfinsert(char *dest, char *target, char *src);
void						free_all(t_output *out);
int							ft_apply_zero(t_keys *lst);
#endif
