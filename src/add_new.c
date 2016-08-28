/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 00:34:35 by rbaum             #+#    #+#             */
/*   Updated: 2016/08/22 00:34:48 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>

t_token							*test(t_token *t)
{
	static t_token				*ret;

	if (t)
		ret = t;
	return (ret);
}

t_label							*test_two(t_label *t)
{
	static t_label				*ret;

	if (t)
		ret = t;
	return (ret);
}

void							add_new(t_token **alst, t_token *new)
{
	static int					i = 0;

	if (new)
	{
		if (i == 0)
		{
			*alst = new;
			i = 1;
			test(new);
		}
		else
		{
			(*alst)->next = new;
			(*alst) = (*alst)->next;
		}
	}
}

void							add_new_label(t_label **alst, t_label *new)
{
	static int					i = 0;

	if (new)
	{
		if (i == 0)
		{
			*alst = new;
			i = 1;
			test_two(new);
		}
		else
		{
			(*alst)->next = new;
			(*alst) = (*alst)->next;
		}
	}
}