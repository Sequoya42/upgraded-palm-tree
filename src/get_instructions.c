/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instructions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 23:50:08 by rbaum             #+#    #+#             */
/*   Updated: 2016/08/18 23:50:12 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include <stdio.h>

void							find_token(char *s, t_core *core)
{
	char						*w;

	if ((w = get_word(&s)))
	{
		if (match_array(w))
			match_operator(w, s, core);
		else if (match(w, "*:"))
		{
			ft_print(KRED "%s\n" KNRM , w);
			match_label(w, s, core);
		}
		else
			ft_exit(w, s, KGRN"\tNOPE nope NOPE! not valid");
	}
}

void							get_instructions(t_core *core)
{
	char						*s;

	if (!(core->token = ft_memalloc(sizeof(t_token))))
		ft_exit(NULL, "core->token", "bad alloc");;
	while ((s = ft_get_line(core->file)))
	{
		ft_putendl(s);
		find_token(s, core);
		ft_colendl("Found");
	}
	(void)core;
}