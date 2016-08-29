/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 19:49:08 by rbaum             #+#    #+#             */
/*   Updated: 2016/08/16 19:49:10 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "core.h"

void							free_token(t_token *t, t_label *l, t_core *core)
{
	t_token						*tmp;
	t_label						*tl;

	tmp = NULL;
	while (t)
	{
		tmp = t;
		t = t->next;
		free(tmp->value);
		free(tmp);
	}
	while ((l = l->next))
	{
		tl = l;
		// l = l->next;
		free(tl->value);
		free(tl);
	}
	free(core->name);
	free(core->header);
	free(core);
}

int								main(int ac, char **av)
{
	t_core				*core;

	if (ac != 2 || !match(av[1], "*.s"))
		return ft_error(NULL, NULL, "Only one parameter [file.s]");
	if (!(core = ft_memalloc(sizeof(t_core))))
		ft_exit(NULL, "core", "bad alloc");
	ft_init(core, av[1]);
	ft_parse(core);
	free_token(TKN_HEAD, LBL_HEAD, core);
	return (0);
}
