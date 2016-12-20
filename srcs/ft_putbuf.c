/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbuf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 11:31:01 by cbinet            #+#    #+#             */
/*   Updated: 2016/12/15 21:41:02 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putbuf(t_buf_f *buffer)
{
	write(1, buffer->buf, buffer->cursor);
	buffer->total += buffer->cursor;
	buffer->cursor = 0;
}
