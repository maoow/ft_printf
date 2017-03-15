/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 23:25:53 by cbinet            #+#    #+#             */
/*   Updated: 2016/11/19 13:05:45 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	int i;

	if (s1 && s2)
	{
		i = 0;
		while (s1[i] == s2[i] && (s1[i] || s2[i]))
			i++;
		if (s1[i] || s2[i])
			return (0);
		return (1);
	}
	return (0);
}
