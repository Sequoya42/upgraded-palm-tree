/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 19:49:08 by rbaum             #+#    #+#             */
/*   Updated: 2016/08/16 19:49:10 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "core.h"

void							print_token(t_token *tmp)
{
	ft_colstr(KRED, "\t\t***TOKENS***\n");
	while (tmp)
	{
		if (tmp->type == LABEL)
			ft_putstr(KRED);
		else
			ft_putstr(KGRN);
		ft_print("Token name\t\t\t:"KNRM" %s\nsize: %d\t\tnb_byte: %d\n",
		 tmp->value, tmp->size, tmp->nb_bytes);
		tmp = tmp->next;
	}

}

void						print_label(t_label *tmp)
{
	ft_colstr(KRED, "\t\t***LABEL***\n");

	while (tmp)
	{
		ft_print("Label name: \t"KGRN"%s"KNRM"\tnb_byte:"KYEL"\t%d\n", tmp->value, tmp->nb_bytes);
		tmp = tmp->next;
	}
}

// & to find if match
// T_REG						1
// T_IND						2
// T_REG | T_IND				3
// T_DIR						4

// T_REG | T_DIR				5
// T_DIR | T_IND				6
// T_REG | T_DIR | T_IND		7

int								main(int ac, char **av)
{
	t_core				*core;

	if (ac != 2 || !match(av[1], "*.s"))
		return ft_error(NULL, NULL, "Only one parameter [file.s]");
	if (!(core = ft_memalloc(sizeof(t_core))))
		ft_exit(NULL, "core", "bad alloc");
	ft_init(core, av[1]);
	ft_parse(core);
	// ft_putnbrendl(core->token->nb_bytes);
	// print_token(TKN_HEAD);
	// print_label(LBL_HEAD);
	return (0);
}


// 4 * 8
// 00000000 00000000 00000000 00000000  || 00000010

// 011010

// int				main(void)
// {
// 	int a;
// 	int b; 
// 	int c;
// 	int r;

// 	a = REG_CODE;
// 	b = DIR_CODE;
// 	c = IND_CODE;
// 	r = add_arg(a, b, b);
// 	// r = (r <<2) + b;
// 	// r = r << 2;
// 	ft_putnbrendl(r);
// 	char *s = ft_base(r, 2);
// 	ft_putendl(s);
// }