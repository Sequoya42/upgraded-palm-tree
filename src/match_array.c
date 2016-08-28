/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 23:38:29 by rbaum             #+#    #+#             */
/*   Updated: 2016/08/20 23:38:36 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

int								match_array(char *s1)
{
	int							i;

	i = 1;
	while (i <= AFF)
	{
		// if (!ft_strcmp(s1, g_code_name[i]))
		if (!ft_strcmp(s1, g_op_tab[i - 1].name))
			return (i);
		i++;
	}
	return (0);
}
