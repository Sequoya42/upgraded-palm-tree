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


int								little_thing(char **s)
{
	int							n;
	int							j;

	n = -1;
	j = 0;
	while ((*s)[++n])
	{
		if ((*s)[n] == COMMENT_CHAR || (*s)[n] == EOL_CHAR)
		{
			(*s)[n] = '\0';
			break;
		}
		if ((*s)[n] == SEPARATOR_CHAR)
			j++;
	}
	return (j);
}

void							manage_arg(int op, char *s, t_core *core)
{
	char						**arg;
	int							n;
	int							nb_sep;

	n = (int)GOT(op).params;
	nb_sep = little_thing(&s);
	if ((nb_sep + 1) != n)
		msg_exit("too many arguments");
	arg = ft_strsplit(s, SEPARATOR_CHAR);
	ft_trim_tab(arg);
	verify_last(arg[n - 1]);
	if (ft_nb_tab(arg) != n)
		msg_exit("Wrond number of arg in : %s\n", s);
	n = -1;
	while (arg[++n])
	{
		determine_arg(arg[n], core, n, op);
		free(arg[n]);
	}
	free(arg);
}
