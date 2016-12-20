/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convarg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 11:15:28 by cbinet            #+#    #+#             */
/*   Updated: 2016/12/19 20:26:26 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	g_tab[16] = {
	's',
	'S',
	'p',
	'd',
	'D',
	'i',
	'o',
	'O',
	'u',
	'U',
	'x',
	'X',
	'c',
	'C',
	'{',
	'%'
};

char	g_fltab[10] = {
	'#',
	'0',
	'-',
	'+',
	' ',
	'h',
	'l',
	'j',
	'z',
	'.'
};
void	*g_ftab[16] = {
	&ft_getstr,
	&ft_getsstr,
	&ft_getptr,
	&ft_getnbr,
	&ft_getlnbr,
	&ft_getnbr,
	&ft_getoctal,
	&ft_getloctal,
	&ft_getunbr,
	&ft_getlunbr,
	&ft_gethexa,
	&ft_getlhexa,
	&ft_getchar,
	&ft_getwchar,	
	&ft_getcolor,	
	&ft_getpercent	
};
bool	ft_isconv(char c)
{
	int		i;

	i = 0;
	while (i < 16)
	{
		if (g_tab[i] == c)
			return (true);
		i++;
	}
	return (false);
}
bool	ft_isflag(char c)
{
	int		i;

	i = 0;
	while (i < 10)
	{
		if (g_fltab[i] == c)
			return (true);
		i++;
	}
	return (false);
}
void	*getconv(char c)
{
	int		i;

	i = 0;
	while (i < 16)
	{
		if (g_tab[i] == c)
			return (g_ftab[i]);
		i++;
	}
	return (NULL);
}
void	ft_setflags(t_buf_f *buffer, char *c)
{
	if (*c == '#')
		buffer->flags.sharp=true;
	if (*c == '0')
		buffer->flags.zero=true;
	if (*c == '-')
		buffer->flags.m=true;
	if (*c == '+')
		buffer->flags.p=true;
	if (*c == 'h' && buffer->flags.h == true)
		buffer->flags.hh=true;
	if (*c == 'h')
		buffer->flags.h=!buffer->flags.h;
	if (*c == 'l' && buffer->flags.l == true)
		buffer->flags.ll=true;
	if (*c == 'l')
		buffer->flags.l=!buffer->flags.l;
	if (*c == 'j')
		buffer->flags.j=true;
	if (*c == 'z')
		buffer->flags.z=true;
	if (*c == ' ')
		buffer->flags.space=true;
	if (*c == '.')
	{
		buffer->flags.isprecision = true;
		buffer->flags.precision = ft_atoi(c + 1);
	}
}


char	*convarg(t_buf_f *buffer, va_list ap, char *format)
{
	int		i;
	char	*(*conv)();

	i = 0;
	ft_initbufferf(buffer);
	while (!ft_isconv(format[i]))
	{
		if (format[i] > '0' && format[i] <= '9')
		{
			if (format[i - 1] != '.')
				buffer->flags.minimum = ft_atoi(format + i);
			while (format[i + 1] >= '0' && format[i + 1] <= '9')
				i++;
		}
		if (!format[i] || (!ft_isconv(format[i]) && !ft_isflag(format[i]) &&
					!ft_isdigit(format[i])))
		{
			if (!format[i])
			ft_buffit(buffer, format, i);
			return (format + i);
		}
		ft_setflags(buffer,&format[i]);
		i++;
	}
	conv = getconv(format[i]);
	format = conv(buffer, ap, format + i);

	return (format + 1);

}

/*
char	*convarg(t_buf_f *buffer, va_list ap, char *format)
{
	int		i;
	void	(*conv)();

	i = 0;
	ft_initbufferf(buffer);
	while (!ft_isconv(format[i]))
	{
		if (format[i] > '0' && format[i] <= '9')
		{
			if (format[i - 1] != '.')
				buffer->flags.minimum = ft_atoi(format + i);
			while (format[i + 1] >= '0' && format[i + 1] <= '9')
				i++;
		}
		if (!format[i])
		{
			ft_buffit(buffer, format, i);
			return ("\0");
		}
		ft_setflags(buffer,&format[i]);
		i++;
	}
	conv = getconv(format[i]);
	conv(buffer, ap, format);
	if (format[i] == '{')
		while (format[i] != '}' && format[i])
			i++;
	if (format[i])
		format += i + 1;
	return (format);
}
*/
