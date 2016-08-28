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

void							match_label(char *t, char *s, t_core *core)
{
	char						*w;
	t_label						*n;

	if (!(n = ft_memalloc(sizeof(t_label))))
		ft_exit(NULL, NULL, "Bad alloc");
	n->nb_bytes = core->token->nb_bytes;
	n->value = ft_strsub(t, 0, ft_strlen(t) -1);
	add_new_label(&core->label, n);
	ft_putendl("All good");
	verify_last(s);
	if (*s)
	{
		// s = ft_strtrim(s);
		ft_putendl(s);
		w = get_word(&s);
		ft_putendl(w);
		match_operator(w, s, core);
	}
}


// void						match_label_t(t_token *t, t_core *c)
// {
// 	t_label					*n;
// 	char					*s;

// 	s = t->value;
// 	if (!(n = ft_memalloc(sizeof(t_label))))
// 		ft_exit(NULL, NULL, "Bad alloc");
// 	n->nb_bytes = t->nb_bytes;
// 	n->value = ft_strsub(s, 0, ft_strlen(s) -1);
// 	add_new_label(&c->label, n);

// }