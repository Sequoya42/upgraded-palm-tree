/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 00:28:51 by rbaum             #+#    #+#             */
/*   Updated: 2016/08/21 00:28:56 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

int								get_nb_bytes(int type, int op)
{
	if (type == OPERATOR)
		return (T_OPERATOR(op));
	if (type == REGISTER)
		return (T_REG);
	if (type == DIRECT)
		return (DIR_OP(op));
	if (type == INDIRECT)
		return (IDIR_OP(op));
	else
		return (0);
}

void							fill_token(int type, char *w, t_core *core)
{
	static unsigned int			t_byte = 0;
	int							i;
	t_token						*n;

	if (!(n = ft_memalloc(sizeof(t_token))))
		ft_exit(NULL, "token", "Bad Alloc");
	n->type = type;
	n->value = ft_strdup(w);
	n->next = NULL;
	i = get_nb_bytes(type, core->current_op);
	t_byte += i;
	n->nb_bytes = t_byte;
	n->size = i;
	add_new(&core->token, n);
}
