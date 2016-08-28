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
			match_label(w, s, core);
			// fill_token(LABEL, w, core);
		else
			ft_exit(w, s, KGRN"\tNOPE nope NOPE! not valid");
	}
	// implement pointer array to choose right func according to label
	// can use the enum for simplication
	
}

void							get_instructions(t_core *core)
{
	char						*s;
	t_token						*t;

	t = TKN_HEAD;
	if (!(core->token = ft_memalloc(sizeof(t_token))))
		ft_exit(NULL, "core->token", "bad alloc");;
	while ((s = ft_get_line(core->file)))
		find_token(s, core);
	while (t)
	{
		if (t->type == LABEL)
			match_label_t(t, core);
		t = t->next;
	}
	(void)core;
}