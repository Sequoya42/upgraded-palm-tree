/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 04:31:35 by rbaum             #+#    #+#             */
/*   Updated: 2016/08/26 04:31:42 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

int								get_offset(char *s)
{
	t_label						*l;

	l = LBL_HEAD;
	s = s + 2;
	while (l)
	{
		if (!ft_strcmp(s, l->value))
			return ((l->nb_bytes));
		l = l->next;
	}
	return (0);
}

// void							write_shit(int fd, int n, int size)
// {
// 	int							v;

// 	v = 0;
// 	while (size-- > 1)
// 		write(fd, &v, 1);
// 	write()
// }

void							write_label(t_core *c, t_token *t)
{
	int							n;
	int							z;
	int							y;
	unsigned int				k;
	char						*s;

	s = (t->type == DIRECT) ? (t->value + 2) : (t->value + 1);
	z = get_offset(t->value);
	n = z - c->op_index;
	if (n < 0)
	{
		y = (~n) + 1;
		n = 0x00010000 - y;
	}
	k  = SWAP(n);
	// ft_print(KRED"z: %d\tsize: %d\t N\t%d\t k : %d\n"KNRM,z,t->nb_bytes , n, k);
	write(c->output, &k, t->size);
}
