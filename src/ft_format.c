/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 16:30:47 by rbaum             #+#    #+#             */
/*   Updated: 2016/08/30 16:30:53 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

unsigned int					ft_endian(unsigned int val)
{
	val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF);
	return ((val << 16) | (val >> 16));
}

void							verify_last(char *s)
{
	int							i;

	i = 0;
	if (s && *s)
	{
		while (s[i])
		{
			if (s[i] == EOL_CHAR || match_char(s[i], BREAK_CHAR))
				s[i] = '\0';
			i++;
		}
	}
}

unsigned int					ft_swap(unsigned int val)
{
	return ((val << 8) | (val >> 8));
}

int								format_int(int n, int size)
{
	int							y;

	if (n < 0)
	{
		y = (~n) + 1;
		n = size == T_DIR ? 0x10000 - y : - y; 
	}
	if (size == T_DIR)
		n = ft_swap(n);
	else if (size == T_IND)
		n = ft_endian(n);
	return (n);
}
