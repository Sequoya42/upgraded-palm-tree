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

void							verify_last(char *s)
{
	int							i;

	i = 0;
	while (s[i++])
		if (s[i] == EOL_CHAR)
			s[i] = '\0';
	i = 0;
	while (s[i++])
		if (match_char(s[i], BREAK_CHAR))
			s[i] = '\0';
}

void							manage_label(char *s, t_core *core, int type)
{
	int							i;

	i = type + 1;
	while (s[i])
	{
		if (!match_char(s[i], LABEL_CHARS))
			ft_exit(NULL, s, "Bad label");
			i++;
	}
	fill_token(type, s , core);

}

void							manage_direct(char *s, t_core *c, int j, int op)
{
	int							i;
	int							n;

	i = 1;
	if (!IS_IN(T_DIR, op, j))
		ft_exit("T_DIR", " not in", GOT(op).name);
	if (s[i] == LABEL_CHAR)
		manage_label(s, c, DIRECT);
	else if ((n = ft_atoi(s + 1)))
		fill_token(DIRECT, s, c);
	else if (s[1] == '0')
		fill_token(DIRECT, s, c);
	else
		ft_exit(NULL, s, "Bad direct instruction");


}

void							determine_arg(char *s, t_core *c, int j, int op)
{
	int							n;

	if (s[0] == 'r' && (ft_strlen(s) == 2 || ft_strlen(s) == 3))
	{
		if ((n = ft_atoi(s + 1)))
		{
			if (!IS_IN(T_REG, op, j))
				ft_exit("T_REG", " not in", GOT(op).name);
			fill_token(REGISTER, s, c);
		}
	}
	else if (s[0] == DIRECT_CHAR)
		manage_direct(s, c, j, op);
	else if (s[0] == LABEL_CHAR)
	{
		if (!IS_IN(T_IND, op, j))
			ft_exit("T_IND", " not in", GOT(op).name);
		manage_label(s, c, INDIRECT);
	}
	else if ((n = ft_atoi(s)))
	{
		if (!IS_IN(T_IND, op, j))
			ft_exit("T_IND", " not in", GOT(op).name);
		fill_token(INDIRECT, s, c);
	}
}

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
		n++;
	}
	// exit(0);
}