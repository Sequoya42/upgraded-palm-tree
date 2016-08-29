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

void							print_token(t_token *tmp)
{
	ft_colstr(KRED, "\t\t***TOKENS***\n");
	while (tmp)
	{
		if (tmp->type == LABEL)
			ft_putstr(KRED);
		else
			ft_putstr(KGRN);
		ft_print("Token name\t\t\t:"KNRM" %s\nsize: %d\t\tnb_byte: %d\n",
		 tmp->value, tmp->size, tmp->nb_bytes);
		tmp = tmp->next;
	}

}

void						print_label(t_label *tmp)
{
	ft_colstr(KRED, "\t\t***LABEL***\n");

	while (tmp)
	{
		ft_print("Label name: \t"KGRN"%s"KNRM"\tnb_byte:"KYEL"\t%d\n", tmp->value, tmp->nb_bytes);
		tmp = tmp->next;
	}
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
	sleep(1000);
	return (0);
}
