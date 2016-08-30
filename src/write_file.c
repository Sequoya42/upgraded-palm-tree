/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 19:41:37 by rbaum             #+#    #+#             */
/*   Updated: 2016/08/25 19:41:42 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void							write_register(t_core *c, t_token *t)
{
	int							n;
	char						*s;

	s = t->value + 1;
	n = ft_atoi(s);
	if (n > REG_NUMBER || n < 0)
		ft_exit(NULL, s, "Invalid register");
	ft_putchar_fd(n, c->output);
}

void							write_direct(t_core *c, t_token *t)
{
	char						*s;
	unsigned int				n;
	long						l;

	s = t->value + 1;
	if (s[0] == LABEL_CHAR)
		write_label(c, t);
	else
	{
		l = ft_atol(s) % INT_MAX;
		n = l;
		n = format_int(n, t->size);
		write(c->output, &n, t->size);
	}
}

void							write_indirect(t_core *c, t_token *t)
{
	int							n;
	long						l;
	char						*s;

	s = t->value;
	if (s[0] == LABEL_CHAR)
		write_label(c, t);
	else
	{
		l = ft_atol(s) % INT_MAX;
		n = l % INT_MAX;
		n = format_int(n, t->size);
		write(c->output, &n, t->size);
	}
}

void							write_operator(t_core *core, t_token *t)
{
	int							a;
	int							r;
	int							k;
	int							n;

	r = 0;
	k = match_array(t->value);
	n = GOT(k).params;
	core->op_index = t->nb_bytes - t->size;
	a = (n >= 1) ? ARG_ONE->type : 0;
	r = (r + a) << 2;
	a = (n >= 2) ? ARG_TWO->type : 0;
	r = (r + a) << 2;
	a = (n >= 3) ? ARG_THREE->type : 0;
	r = (r + a) << 2;
	ft_putchar_fd(k, core->output);
	if ((T_OPERATOR(k)) == 2)
		ft_putchar_fd(r, core->output);
}

static t_fptr		g_toto[TYPE_LEN] =
{
	NULL,
	&write_register,
	&write_direct,
	&write_indirect,
	&write_label,
	&write_operator

};

void							write_file(t_core *core)
{
	t_token						*t;

	t = TKN_HEAD;
	while (t)
	{
		g_toto[t->type](core, t);
		t = t->next;
	}
}
