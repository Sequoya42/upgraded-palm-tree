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

void							find_token(char **s, t_core *core)
{
	char						*w;

	if ((w = get_word(s)))
	{
		ft_colendl(w);
		if (match_array(w))
			match_operator(w, *s, core);
		else if (match(w, "*:"))
		{
			ft_putendl(w);
			ft_putendl(*s);
			match_label(w, s, core);
		}
		else
			ft_exit(w, *s, KGRN"\tNOPE nope NOPE! not valid");
	}
	free(w);
}

void							get_instructions(t_core *core)
{
	char						*s;
	void						*t;

	while ((s = ft_get_line(core->file)))
	{
		t = s;
		find_token(&s, core);
		free(t);
	}
}
