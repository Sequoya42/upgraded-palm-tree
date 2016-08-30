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

void							write_label(t_core *c, t_token *t)
{
	int							n;
	int							z;
	char						*s;

	s = (t->type == DIRECT) ? (t->value + 2) : (t->value + 1);
	z = get_offset(t->value);
	n = z - c->op_index;
	n = format_int(n, t->type);
	write(c->output, &n, t->size);
}
