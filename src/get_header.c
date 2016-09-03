/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_header.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 01:34:51 by rbaum             #+#    #+#             */
/*   Updated: 2016/08/17 01:34:54 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

static void						fill(t_header *h, char *t, char *t2)
{
	int							i;

	i = -1;
	while (t[++i] && (i < PROG_NAME_LENGTH))
		h->prog_name[i] = t[i];
	i = -1;
	while (t2[++i] && (i < COMMENT_LENGTH))
	{
		h->comment[i] = t2[i];
	}
	free(t);
	free(t2);
}

void							get_header(t_header *h)
{
	t_file						*file;
	char						*t;
	char						*t2;
	char						*s;

	file = single_file();
	h->magic = COREWAR_EXEC_MAGIC;
	h->prog_size = 0;
	s = ft_get_line(file, '"');
	if (!match(s, "*" NAME_CMD_STRING "*"))
	{
		ft_print(KRED "%s\n", s);
		ft_exit("Bad ", NAME_CMD_STRING "*", " header");
	}
	t = ft_get_line(file, '"');
	free(s);
	s = ft_get_line(file, '"');
	if (!match(s, "*" COMMENT_CMD_STRING "*"))
		ft_exit(s, "\t" COMMENT_CMD_STRING "*", " header");
	t2 = ft_get_line(file, '"');
	free(s);
	fill(h, t, t2);
}
