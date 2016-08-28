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


// use g_op_tab to verify

// 1: LIVE | ZJMP | FORK | LFORK | AFF | 5
// 2: LD | ST | LLD | 3
// 3: ADD | SUB |AND | OR | XOR | LDI | STI | LLDI 8

// & to find if match
// T_REG						1
// T_IND						2
// T_REG | T_IND				3
// T_DIR						4

// T_REG | T_DIR				5
// T_DIR | T_IND				6
// T_REG | T_DIR | T_IND		7


#if 0
sti r1, r2, r3
op ARG1,arg2,arg3

#endif

void							match_operator(char *w, char *s, t_core *core)
{
	core->current_op = match_array(w);
	// ()pass operator, w, core directly, 
	fill_token(OPERATOR, w, core);
	manage_arg(core->current_op, s, core);
	// Manage arg directly by sending them all and the OP_CODE
	// get the name, thus the TYPE, and verify with G_OP_TAB
	// func to determine if right number and kind of arg
	// and inside trhose, call fill_token
	// print_arg(arg);
}
