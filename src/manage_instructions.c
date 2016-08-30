/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 16:36:32 by rbaum             #+#    #+#             */
/*   Updated: 2016/08/30 16:36:36 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void							manage_reg(char *s, t_core *core, int j, int op)
{
	int							n;

	if ((n = ft_atoi(s + 1)))
	{
		if (n < 10 && ft_strlen(s) != 2)
			msg_exit("Bad register, 1 to %d\n", REG_NUMBER);
		if (!IS_IN(T_REG, op, j))
			ft_exit("T_REG", " not in", GOT(op).name);
		else if (n > REG_NUMBER || n <= 0)
			msg_exit("Bad register, 1 to %d\n", REG_NUMBER);
		fill_token(REGISTER, s, core);
	}
	else
		msg_exit("Bad register, 1 to %d\n", REG_NUMBER);
}

void							manage_label(char *s, int type)
{
	int							i;

	i = type == DIRECT ? 3 : 2;
	while (s[i])
	{
		if (!match_char(s[i], LABEL_CHARS))
			ft_exit(NULL, s, "Bad label");
		i++;
	}
}

void							manage_direct(char *s, t_core *c, int j, int op)
{
	int							i;

	i = 1;
	if (!IS_IN(T_DIR, op, j))
		ft_exit("T_DIR", " not in", GOT(op).name);
	else if (s[1] == LABEL_CHAR)
		manage_label(s, DIRECT);
	else
	{
		while (s[i])
		{
			if (!match_char(s[i], NUM_CHAR))
				msg_exit("%s\t: Bad direct instruction\n", s);
			i++;
		}
	}
	fill_token(DIRECT, s, c);
}

void							manage_ind(char *s, t_core *c, int j, int op)
{
	int							i;

	i = 0;
	if (!IS_IN(T_IND, op, j))
		ft_exit("T_IND", " not in", GOT(op).name);
	else if (s[0] == LABEL_CHAR)
		manage_label(s, INDIRECT);
	else
	{
		while (s[i])
		{
			if (!match_char(s[i], NUM_CHAR))
				msg_exit("%s\t: Bad indirect instruction\n", s);
			i++;
		}
	}
	fill_token(INDIRECT, s, c);
}

void							determine_arg(char *s, t_core *c, int j, int op)
{
	if (s[0] == 'r' && (ft_strlen(s) == 2 || ft_strlen(s) == 3))
		manage_reg(s, c, j, op);
	else if (s[0] == DIRECT_CHAR)
		manage_direct(s, c, j, op);
	else
		manage_ind(s, c, j, op);
}
