/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 00:36:20 by rbaum             #+#    #+#             */
/*   Updated: 2016/08/23 00:36:24 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void							manage_arg(int op, char *s, t_core *core)
{
	char						**arg;
	int							n;

	n = (int)GOT(op).params;
	arg = ft_strsplit(s, SEPARATOR_CHAR);
	ft_trim_tab(arg);
	verify_last(arg[n - 1]);
	if (ft_nb_tab(arg) != n)
		ft_exit(ft_itoa(core->file->line), ft_itoa(ft_nb_tab(arg)),
			"Wrong number of " "arg");
	n = 0;
	while (arg[n])
	{
		determine_arg(arg[n], core, n, op);
		free(arg[n]);
		n++;
	}
	free(arg);
}
