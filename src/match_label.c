/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 00:27:44 by rbaum             #+#    #+#             */
/*   Updated: 2016/08/21 00:27:49 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

int								something_else(char *s)
{
	int							i;

	i = 0;
	if (!s || !*s)
		return (0);
	while (s[i])
	{
		if (match_char(s[i], LABEL_CHARS))
			return (1);
		i++;
	}
	return (0);
}

void							match_label(char *t, char **s, t_core *core)
{
	char						*w;
	t_label						*n;

	if (!(n = ft_memalloc(sizeof(t_label))))
		ft_exit(NULL, NULL, "Bad alloc");
	if (core->token)
		n->nb_bytes = core->token->nb_bytes;
	else
		n->nb_bytes = 0;
	n->value = ft_strsub(t, 0, ft_strlen(t) - 1);
	add_new_label(&core->label, n);
	if (something_else(*s))
	{
		w = get_word(s);
		if (w)
			match_operator(w, *s, core);
	}
}
