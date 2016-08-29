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
	ft_putchar_fd(n, c->output);
}

void							write_direct(t_core *c, t_token *t)
{
	char						*s;
	unsigned int				n;
//DIRECT CANNOT BE NEGATIVE?
	s = t->value + 1;
	if (s[0] == LABEL_CHAR)
		write_label(c, t);
	else
	{
	n = ft_atoi(s);
	if (t->size == T_DIR)
		n = SWAP(n);
	else if (t->size == T_IND)
		n = ft_endian(n);
	write(c->output, &n, t->size);
	}

}

void							write_indirect(t_core *c, t_token *t)
{
	int n;

	char *s = t->value;
	if (s[0] == LABEL_CHAR)
		write_label(c, t);
	else
	{
	n = ft_atoi(s);
	int y;
	if (n < 0)
	{
		y = (~n) + 1;
		n = 0x10000 - y;
	}
	if (t->size == T_DIR)
		n = SWAP(n);
	else if (t->size == T_IND)
		n = ft_endian(n);
	write(c->output, &n, t->size);
	}
}

int								add_arg(int a, int b, int c)
{
	int							r;

	r = 0;
	r = (r + a);
	r = r << 2;
	r = (r + b);
	r = r << 2;
	r = (r + c);
	r = r << 2;
	return (r);
}

void							write_operator(t_core *core, t_token *t)
{
	int							a;
	int							b;
	int							c;
	int							r;

	int k = match_array(t->value);
	int n = GOT(k).params;
	core->op_index = t->nb_bytes - t->size;
	a = (n >= 1) ? ARG_ONE->type : 0;
	b = (n >= 2) ? ARG_TWO->type : 0;
	c = (n >= 3) ? ARG_THREE->type : 0;
	r = add_arg(a, b, c);
	ft_putchar_fd(k, core->output);
	if ((T_OPERATOR(k)) == 2)
		ft_putchar_fd(r, core->output);
}

static t_fptr		toto[TYPE_LEN] = 
{
	NULL,
	&write_register, /* REGISTER */
	&write_direct,  /* DIRECT */
	&write_indirect, /* INDIRECT */
	&write_label, /* LABEL */
	&write_operator, /* OPERATOR */

};

void							write_file(t_core *core)
{
	t_token						*t;

	t = TKN_HEAD;
	(void)core;
	while (t)
	{
		toto[t->type](core, t);
		// if (t->type == OPERATOR){
		// 	write_operator(core, t);
		// }
		// else if (t->type == REGISTER)
		// {
		// 	write_register(core, t);
		// }
		// else if (t->type == DIRECT)
		// {
		// 	write_direct(core, t);
		// }
		// else if (t->type == INDIRECT)
		// {
		// 	write_indirect(core, t);
		// }
		// (void)toto[t->type];
		t = t->next;
	}
}
