/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match_operator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 00:27:31 by rbaum             #+#    #+#             */
/*   Updated: 2016/08/21 00:27:38 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void							match_operator(char *w, char *s, t_core *core)
{
	core->current_op = match_array(w);
	fill_token(OPERATOR, w, core);
	manage_arg(core->current_op, s, core);
}
