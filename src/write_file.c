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

// static t_fptr		toto[TYPE_LEN] = 
// {
// 	&write_register, /* REGISTER */
// 	NULL,  INDIRECT 
// 	NULL, /* DIRECT */
// 	NULL, /* LABEL */
// 	NULL, /* OPERATOR */

// };

void							write_register(t_core *c, t_token *t)
{
	// int							w;
	int							n;
	char						*s;

	s = t->value + 1;
	n = ft_atoi(s);
	// n = SWAP(n);
	ft_putchar_fd(n, c->output);
}

void							write_direct(t_core *c, t_token *t)
{
	char						*s;
	unsigned int							n;
//DIRECT CANNOT BE NEGATIVE?
	s = t->value + 1;
	if (s[0] == LABEL_CHAR)
		write_label(c, t);
	else
	{
	n = ft_atoi(s);
	// n = SWAP(n);
	if (t->size == 2)
		n = SWAP(n);
	else if (t->size == 4)
		n = ft_endian(n);
	ft_print("%s \tsize is \t%d\n", t->value, t->size);
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
	// if (n < 0)
	// {
	// 	if (t->size == 2)
	// 	n = SWAP(n);
	// else if (t->size == 4)
	// 	n = ft_endian(n);

	// }
	int y;
	if (n < 0)
	{
		y = (~n) + 1;
		n = 0x00010000 - y;
		n = SWAP(n);
	}


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

	ft_colendl(t->value);
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
	// {
	// }
}

void							write_file(t_core *core)
{
	t_token						*t;

	t = TKN_HEAD;
	(void)core;
	while (t)
	{
		if (t->type == OPERATOR){
			write_operator(core, t);
		}
		else if (t->type == REGISTER)
		{
			write_register(core, t);
		}
		else if (t->type == DIRECT)
		{
			write_direct(core, t);
		}
		else if (t->type == INDIRECT)
		{
			write_indirect(core, t);
		}
		// (void)toto[t->type];
		t = t->next;
	}
}
