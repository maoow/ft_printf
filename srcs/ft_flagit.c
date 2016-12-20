/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 16:59:51 by cbinet            #+#    #+#             */
/*   Updated: 2016/12/19 20:26:26 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*ft_initstr(t_buf_f *buffer, char *str)
{
	int		i;

	i = 0;
	str[buffer->flags.minimum] = '\0';
	while (i < buffer->flags.minimum || i < buffer->flags.precision)
	{
		if (buffer->flags.zero || (buffer->flags.precision >= buffer->flags.minimum && !buffer->flags.string && i >= buffer->flags.minimum - buffer->flags.precision))
			str[i] = '0';
		else
			str[i] = ' ';
		i++;
	}
	return (str);
}

static char		*ft_placestr(t_buf_f *buffer, char *str, char *dst)
{
	int		i;
	int		size;

	size = ft_strlen(str);
	if (buffer->flags.string)
		size -= buffer->flags.precision;
	if (!buffer->flags.m)
	{
		if (!buffer->flags.string && buffer->flags.minimum < buffer->flags.precision)
			buffer->flags.minimum  = buffer->flags.precision;
		i = buffer->flags.minimum - size;


	}
	else 
		i = 0;
	while (*str && i < buffer->flags.minimum)
	{
		dst[i] = *str;
		i++;
		str++;
	}
	return (dst);

}

static char		*ft_plusstr(char *str)
{
	char	*dst;

	if (str[0] == '0' || str[0] == ' ')
	{
		str[0] = '+';
		dst = str;
	}
	else
	{
		dst = (char *)malloc((ft_strlen(str) + 1) * sizeof(*dst));
		dst[0] = '+';
		ft_strcpy(dst + 1, str);
	}
	return (dst);
}

static char		*ft_spacestr(t_buf_f *buffer, char *str)
{
	char	*dst;

	if (!buffer->flags.p && buffer->flags.space)
	{
		if (str[0] == '0')
		{
			str[0] = ' ';
			dst = str;
		}
		else if (str[0] == ' ')
			return (str);
		else
		{
			dst = (char *)malloc((ft_strlen(str) + 1) * sizeof(*dst));
			dst[0] = ' ';
			ft_strcpy(dst + 1, str);
		}
		return (dst);
	}
	if (buffer->flags.p)
		return (ft_plusstr(str));
	return (str);
}

char	*ft_mallocflag(t_buf_f *buffer, char *str)
{
	if (buffer->flags.string || buffer->flags.minimum > buffer->flags.precision)
	{
		if((str = (char *)malloc((buffer->flags.minimum + 1) * sizeof(*str)))
				== NULL)
			return (NULL);
	}
	else
		if((str = (char *)malloc((buffer->flags.precision + 1) * sizeof(*str)))
				== NULL)
			return (NULL);
	return (str);
}

char	*ft_typeit(t_buf_f *buffer, char *str)
{
	char	*dst;
	int		i;

	i = 2;
	if((dst = (char *)malloc((ft_strlen(str) + 3) * sizeof(*dst)))
			== NULL)
		return (NULL);
	dst[0] = '0';
	dst[1] = 'x';
	while (*str)
	{
		dst[i] = *str;
		i++;
		str++;
	}
	return (dst);
}

char	*ft_flagit(t_buf_f *buffer, char *str)
{
	char	*dst;

	if (buffer->flags.sharp)
		str = ft_typeit(buffer, str);
	if (buffer->flags.minimum > ft_strlen(str))
	{
		dst = ft_mallocflag(buffer, dst);
		dst = ft_initstr(buffer, dst);
		dst = ft_placestr(buffer, str, dst);
		if (str[0] != '-')
			dst = ft_spacestr(buffer, dst);
		free(str);
		str = dst;
	}
	else
		str = ft_spacestr(buffer, str);
	return (str);
}
