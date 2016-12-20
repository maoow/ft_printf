/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 13:41:53 by cbinet            #+#    #+#             */
/*   Updated: 2016/12/19 16:50:31 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_getstr(t_buf_f *buffer, va_list ap, char *format)
{
	char	*str;

	str = ft_strdup(va_arg(ap, char *));
	if (!str)
		str = ft_strdup("(null)");
	buffer->flags.string = true;
	str = ft_flagit(buffer, str);
	ft_buffit(buffer, str, ft_strlen(str));
	free(str);
}

void	ft_getsstr(t_buf_f *buffer, va_list ap, char *format)
{
	int	*str;

	str = va_arg(ap, wchar_t *);
	if (!str)
	{
		str = ft_strdup("(null)");
		ft_buffit(buffer, str, ft_strlen(str));
	}
	else
		while (*str)
		{
			ft_bufwchar(buffer, *str);
			str++;
		}

}

void	ft_getptr(t_buf_f *buffer, va_list ap, char *format)
{
	unsigned long int		nb;
	char	*str;

	nb = va_arg(ap, unsigned long int);
	str = ft_litoabase(nb, "0123456789abcdef");
	buffer->flags.sharp = true;
	str = ft_flagit(buffer, str);
	ft_buffit(buffer, str, ft_strlen(str));
	free(str);
}

void	ft_getnbr(t_buf_f *buffer, va_list ap, char *format)
{
	int		nb;
	char	*str;

	if (!buffer->flags.l && !buffer->flags.ll && !buffer->flags.j)
	{
		nb = va_arg(ap, int);
		str = ft_itoa(nb);

		str = ft_flagit(buffer, str);
		ft_buffit(buffer, str, ft_strlen(str));
		free(str);
	}
	else if(buffer->flags.l)
		ft_getlnbr(buffer, ap, format);
	else if(buffer->flags.ll)
		ft_getllnbr(buffer, ap, format);
	else if(buffer->flags.j)
		ft_getmnbr(buffer, ap, format);
}

void	ft_getmnbr(t_buf_f *buffer, va_list ap, char *format)
{
	intmax_t	nb;
	char		*str;

	nb = va_arg(ap, intmax_t);
	str = ft_mitoa(nb);
	str = ft_flagit(buffer, str);
	ft_buffit(buffer, str, ft_strlen(str));
	free(str);
}

void	ft_getlnbr(t_buf_f *buffer, va_list ap, char *format)
{
	long int		nb;
	char	*str;

	nb = va_arg(ap, long int);
	str = ft_litoa(nb);
	str = ft_flagit(buffer, str);
	ft_buffit(buffer, str, ft_strlen(str));
	free(str);
}
void	ft_getllnbr(t_buf_f *buffer, va_list ap, char *format)
{
	long long int		nb;
	char	*str;

	nb = va_arg(ap, long long int);
	str = ft_llitoa(nb);
	str = ft_flagit(buffer, str);
	ft_buffit(buffer, str, ft_strlen(str));
	free(str);
}

void	ft_getoctal(t_buf_f *buffer, va_list ap, char *format)
{
	unsigned int		nb;
	char	*str;

	nb = va_arg(ap, unsigned int);
	str = ft_itoabase(nb, "01234567");
	str = ft_flagit(buffer, str);
	ft_buffit(buffer, str, ft_strlen(str));
	free(str);
}

void	ft_getloctal(t_buf_f *buffer, va_list ap, char *format)
{
	unsigned long int		nb;
	char	*str;

	nb = va_arg(ap, unsigned long int);
	str = ft_litoabase(nb, "01234567");
	str = ft_flagit(buffer, str);
	ft_buffit(buffer, str, ft_strlen(str));
	free(str);
}

void	ft_getunbr(t_buf_f *buffer, va_list ap, char *format)
{
	unsigned int		nb;
	char	*str;

	nb = va_arg(ap, unsigned int);
	str = ft_uitoa(nb);
	str = ft_flagit(buffer, str);
	ft_buffit(buffer, str, ft_strlen(str));
	free(str);
}

void	ft_getlunbr(t_buf_f *buffer, va_list ap, char *format)
{
	long unsigned int		nb;
	char	*str;

	nb = va_arg(ap, long unsigned int);
	str = ft_ulitoa(nb);
	str = ft_flagit(buffer, str);
	ft_buffit(buffer, str, ft_strlen(str));
	free(str);
}

void	ft_gethexa(t_buf_f *buffer, va_list ap, char *format)
{
	unsigned int		nb;
	char	*str;

	nb = va_arg(ap, unsigned int);
	str = ft_itoabase(nb, "0123456789abcdef");
	str = ft_flagit(buffer, str);
	ft_buffit(buffer, str, ft_strlen(str));
	free(str);
}

void	ft_getlhexa(t_buf_f *buffer, va_list ap, char *format)
{
	unsigned int		nb;
	char	*str;

	nb = va_arg(ap, unsigned long int);
	str = ft_itoabase(nb, "0123456789ABCDEF");
	str = ft_flagit(buffer, str);
	ft_buffit(buffer, str, ft_strlen(str));
	free(str);
}

void	ft_getchar(t_buf_f *buffer, va_list ap, char *format)
{
	char	c;

	c = (char)va_arg(ap, int);
	ft_buffit(buffer, &c, 1);
}
void	ft_getwchar(t_buf_f *buffer, va_list ap, char *format)
{
	unsigned int		c;

	c = va_arg(ap, unsigned int);
	ft_bufwchar(buffer, c);
}

void	ft_getpercent(t_buf_f *buffer, va_list ap, char *format)
{
	char	*str;

	str = ft_strdup("%");
	str = ft_flagit(buffer, str);
	ft_buffit(buffer, str, ft_strlen(str));
	free(str);

}


void	ft_bufwchar(t_buf_f *buffer, int c)
{
	if (c <= 128)
		ft_buffit(buffer, &c, 1);
	else if (c <= 2048)
		ft_bufwchartwo(buffer, c);
	else if (c <= 65536)
		ft_bufwcharthree(buffer, c);
	else
		ft_bufwcharfour(buffer, c);
}
void	ft_bufwchartwo(t_buf_f *buffer, int c)
{
	unsigned int					tab[2];
	tab[1] = c % 64 + 128;
	c /= 64;
	tab[0] = c + 192;

	ft_buffit(buffer, tab, 1);
	ft_buffit(buffer, tab + 1, 1);
}
void	ft_bufwcharthree(t_buf_f *buffer, int c)
{
	unsigned int					tab[3];
	tab[2] = c % 64 + 128;
	c /= 64;
	tab[1] = c % 64 + 128;
	c /= 64;
	tab[0] = c + 224;

	ft_buffit(buffer, tab, 1);
	ft_buffit(buffer, tab + 1, 1);
	ft_buffit(buffer, tab + 2, 1);
}
void	ft_bufwcharfour(t_buf_f *buffer, int c)
{
	unsigned int					tab[4];
	tab[3] = c % 64 + 128;
	c /= 64;
	tab[2] = c % 64 + 128;
	c /= 64;
	tab[1] = c % 64 + 128;
	c /= 64;
	tab[0] = c + 240;

	ft_buffit(buffer, tab, 1);
	ft_buffit(buffer, tab + 1, 1);
	ft_buffit(buffer, tab + 2, 1);
	ft_buffit(buffer, tab + 3, 1);
}
char	*color_tab[8] = {
	"black",
	"red",
	"green",
	"yellow",
	"blue",
	"pink",
	"cyan",
	"grey"
};
void	ft_getcolor(t_buf_f *buffer, va_list ap, char *format)
{
	int		i;
	char	*str;

	i = 0;
	while (format[i] != '}')
		i++;
	str = ft_strsub(format, 1, i - 1);
	ft_colorize(buffer, str);
	free(str);
}

void	ft_colorize(t_buf_f *buffer, char *format)
{
	char	str[2];
	int		i;

	i = 0;
	if (*format == 'b' && *(format + 1) == 'g')
	{
		str[0] = '4';
		format += 2;
	}
	else
		str[0] = '3';
	str[1] == 0;
	while (i < 8)
	{
		if (ft_strcmp(format, color_tab[i]) == 0)
			str[1] = i + '0';
		i++;
	}
	ft_buffit(buffer, "\033[",2);
	if (str[1] != 0)
		ft_buffit(buffer, str, 2);
	else
		ft_buffit(buffer, "0", 1);
	ft_buffit(buffer, "m", 1);
}

