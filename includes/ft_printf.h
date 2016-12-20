/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 13:08:37 by cbinet            #+#    #+#             */
/*   Updated: 2016/12/19 20:26:26 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ft_printf_h
# define ft_printf_h
#include "../srcs/libft/libft.h"
#include <stdarg.h>
#include <limits.h>
#define BUFF_SIZE 1024

typedef struct		s_flags_f
{
	bool	sharp;
	bool	zero;
	bool	m;
	bool	p;
	bool	hh;
	bool	h;
	bool	l;
	bool	ll;
	bool	j;
	bool	z;
	bool	space;
	bool	isprecision;
	int		precision;
	int		minimum;
	bool	string;
}					t_flags_f;

typedef struct		s_buf_f
{
	char		buf[BUFF_SIZE];
	int			cursor;
	int			total;
	t_flags_f	flags;
}					t_buf_f;

char	*ft_getcolor(t_buf_f *buffer, va_list ap, char *format);
void	ft_colorize(t_buf_f *buffer, char *format);
void	ft_bufwcharfour(t_buf_f *buffer, int c);
void	ft_bufwcharthree(t_buf_f *buffer, int c);
void	ft_bufwchartwo(t_buf_f *buffer, int c);
void	ft_bufwchar(t_buf_f *buffer, int c);
char	*ft_flagit(t_buf_f *buffer, char *str);
char	*ft_getpercent(t_buf_f *buffer, va_list ap, char *format);
char	*ft_getstr(t_buf_f *buffer, va_list ap, char *format);
char	*ft_getsstr(t_buf_f *buffer, va_list ap, char *format);
char	*ft_getptr(t_buf_f *buffer, va_list ap, char *format);
char	*ft_getnbr(t_buf_f *buffer, va_list ap, char *format);
char	*ft_getlnbr(t_buf_f *buffer, va_list ap, char *format);
char	*ft_getmnbr(t_buf_f *buffer, va_list ap, char *format);
char	*ft_getllnbr(t_buf_f *buffer, va_list ap, char *format);
char	*ft_getnbr(t_buf_f *buffer, va_list ap, char *format);
char	*ft_getoctal(t_buf_f *buffer, va_list ap, char *format);
char	*ft_getloctal(t_buf_f *buffer, va_list ap, char *format);
char	*ft_getunbr(t_buf_f *buffer, va_list ap, char *format);
char	*ft_getlunbr(t_buf_f *buffer, va_list ap, char *format);
char	*ft_gethexa(t_buf_f *buffer, va_list ap, char *format);
char	*ft_getlhexa(t_buf_f *buffer, va_list ap, char *format);
char	*ft_getllhexa(t_buf_f *buffer, va_list ap, char *format);
char	*ft_getchar(t_buf_f *buffer, va_list ap, char *format);
char	*ft_getwchar(t_buf_f *buffer, va_list ap, char *format);
void	ft_initbufferf(t_buf_f *buffer);
void	ft_putbuf(t_buf_f *buffer);
void	ft_buffit(t_buf_f *buffer, char *str, int size);
void	ft_getf(t_buf_f *buffer, va_list ap, char *format);
bool	ft_isconv(char c);
void	*getconv(char c);
char	*convarg(t_buf_f *buffer, va_list ap, char *format);
int		ft_printf(const char *format, ...);
#endif
