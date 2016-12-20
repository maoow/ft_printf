/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 13:41:53 by cbinet            #+#    #+#             */
/*   Updated: 2016/12/19 20:26:26 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_getstr(t_buf_f *buffer, va_list ap, char *format)
{
	char	*str;

	if (!buffer->flags.l)
	{
	str = ft_strdup(va_arg(ap, char *));
	if (!str)
		str = ft_strdup("(null)");
	buffer->flags.string = true;
		str = ft_flagit(buffer, str);
	ft_buffit(buffer, str, ft_strlen(str));
	free(str);
	}
	else
		ft_getsstr(buffer, ap, format);
	return (format);
}

char	*ft_getsstr(t_buf_f *buffer, va_list ap, char *format)
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

	return (format);
}

char	*ft_getptr(t_buf_f *buffer, va_list ap, char *format)
{
	unsigned long int		nb;
	char	*str;

	nb = va_arg(ap, unsigned long int);
	if (nb || buffer->flags.precision || !buffer->flags.isprecision)
	{
	buffer->flags.sharp = true;
	str = ft_litoabase(nb, "0123456789abcdef");
		str = ft_flagit(buffer, str);
	ft_buffit(buffer, str, ft_strlen(str));
	free(str);
	}
	else
		ft_buffit(buffer, "0x", 2);
	return (format);
}

char	*ft_getnbr(t_buf_f *buffer, va_list ap, char *format)
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
	return (format);
}

char	*ft_getmnbr(t_buf_f *buffer, va_list ap, char *format)
{
	intmax_t	nb;
	char		*str;

	nb = va_arg(ap, intmax_t);
	str = ft_mitoa(nb);
		str = ft_flagit(buffer, str);
	ft_buffit(buffer, str, ft_strlen(str));
	free(str);
	return (format);
}

char	*ft_getlnbr(t_buf_f *buffer, va_list ap, char *format)
{
	long int		nb;
	char	*str;

	nb = va_arg(ap, long int);
	str = ft_litoa(nb);
		str = ft_flagit(buffer, str);
	ft_buffit(buffer, str, ft_strlen(str));
	free(str);
	return (format);
}
char	*ft_getllnbr(t_buf_f *buffer, va_list ap, char *format)
{
	long long int		nb;
	char	*str;

	nb = va_arg(ap, long long int);
	str = ft_llitoa(nb);
		str = ft_flagit(buffer, str);
	ft_buffit(buffer, str, ft_strlen(str));
	free(str);
	return (format);
}

char	*ft_getoctal(t_buf_f *buffer, va_list ap, char *format)
{
	unsigned int		nb;
	char	*str;

	if (!buffer->flags.l && !buffer->flags.ll)
	{
	nb = va_arg(ap, unsigned int);
	str = ft_itoabase(nb, "01234567");
		str = ft_flagit(buffer, str);
	ft_buffit(buffer, str, ft_strlen(str));
	free(str);
	}
	else
		ft_getloctal(buffer, ap, format);
	return (format);
}

char	*ft_getloctal(t_buf_f *buffer, va_list ap, char *format)
{
	unsigned long int		nb;
	char	*str;

	nb = va_arg(ap, unsigned long int);
	str = ft_litoabase(nb, "01234567");
		str = ft_flagit(buffer, str);
	ft_buffit(buffer, str, ft_strlen(str));
	free(str);
	return (format);
}

char	*ft_getunbr(t_buf_f *buffer, va_list ap, char *format)
{
	unsigned int		nb;
	char	*str;

	if (!buffer->flags.l && !buffer->flags.ll)
	{
	nb = va_arg(ap, unsigned int);
	str = ft_uitoa(nb);
		str = ft_flagit(buffer, str);
	ft_buffit(buffer, str, ft_strlen(str));
	free(str);
	}
	else
		ft_getlunbr(buffer, ap, format);
	
	return (format);
}

char	*ft_getlunbr(t_buf_f *buffer, va_list ap, char *format)
{
	long unsigned int		nb;
	char	*str;

	nb = va_arg(ap, long unsigned int);
	str = ft_ulitoa(nb);
		str = ft_flagit(buffer, str);
	ft_buffit(buffer, str, ft_strlen(str));
	free(str);
	return (format);
}

char	*ft_gethexa(t_buf_f *buffer, va_list ap, char *format)
{
	unsigned int		nb;
	char	*str;

	if (!buffer->flags.l && !buffer->flags.ll)
	{
	nb = va_arg(ap, unsigned int);
	str = ft_itoabase(nb, "0123456789abcdef");
		str = ft_flagit(buffer, str);
	ft_buffit(buffer, str, ft_strlen(str));
	free(str);
	}
	else
		ft_getllhexa(buffer, ap, format);
	return (format);
}
char	*ft_getllhexa(t_buf_f *buffer, va_list ap, char *format)
{
	unsigned long int		nb;
	char	*str;

	nb = va_arg(ap, unsigned long int);
	str = ft_litoabase(nb, "0123456789abcdef");
		str = ft_flagit(buffer, str);
	ft_buffit(buffer, str, ft_strlen(str));
	free(str);
	return (format);
}

char	*ft_getlhexa(t_buf_f *buffer, va_list ap, char *format)
{
	unsigned long int		nb;
	char	*str;

	nb = va_arg(ap, unsigned long int);
	str = ft_litoabase(nb, "0123456789ABCDEF");
		str = ft_flagit(buffer, str);
	ft_buffit(buffer, str, ft_strlen(str));
	free(str);
	return (format);
}

char	*ft_getchar(t_buf_f *buffer, va_list ap, char *format)
{
	char	c;

	if (!buffer->flags.l)
	{
	c = (char)va_arg(ap, int);
	if (c && c != 0)
	ft_buffit(buffer, &c, 1);
	else
	ft_buffit(buffer, "", 1);
	}
	else
		ft_getwchar(buffer, ap, format);
	return (format);
}
char	*ft_getwchar(t_buf_f *buffer, va_list ap, char *format)
{
	unsigned int		c;
	
	c = va_arg(ap, unsigned int);
	if (c && c != 0)
		ft_bufwchar(buffer, c);
	else
	ft_buffit(buffer, "", 1);
//	else
//	ft_buffit(buffer, "0", 1);
	return (format);
}

char	*ft_getpercent(t_buf_f *buffer, va_list ap, char *format)
{
	char	*str;

	str = ft_strdup("%");
//		str = ft_flagit(buffer, str);
	ft_buffit(buffer, str, ft_strlen(str));
	free(str);
	return (format);

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
char	*color_tab[9] = {
	"black",
	"red",
	"green",
	"yellow",
	"blue",
	"pink",
	"cyan",
	"grey",
	"eoc"
};
char	*ft_getcolor(t_buf_f *buffer, va_list ap, char *format)
{
	int		i;
	int		j;
	char	*str;
	bool	color;

	color = false;
	i = 0;
	j = 0;
	while (format[i] != '}')
		i++;
	str = ft_strsub(format, 1, i - 1);
	while (j < 9)
	{
		if (ft_strcmp(str, color_tab[j]) == 0 || ft_strcmp(str + 2, color_tab[j]) == 0)
			color = true;
		j++;
	}
	free(str);
	if (color == true)
	{
		ft_colorize(buffer, str);
		return (format + i);
	}
	ft_buffit(buffer,"{",1);
	return (format);
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

