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
	unsigned int				r;

	r = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF);
	return ((r << 16) | (r >> 16));
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

int								format_int(int n, int size)
{
	int							y;

	if (n < 0)
	{
		y = (~n) + 1;
		n = 0x00010000 - y;
	}
	if (size == T_DIR)
		n = SWAP(n);
	else if (size == T_IND)
		n = ft_endian(n);
	return (n);
}
