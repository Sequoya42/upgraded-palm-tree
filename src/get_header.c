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


static char						*get_quote(char *s)
{
	int							i;
	int							j;

	i = 0;
	j = 0;
	while (s[i++])
	{
		if (s[i] == '"')
		{
			if (j != 0)
				return (ft_strsub(s, j + 1, i - j - 1));
			j = i;
		}
	}
	ft_exit(NULL, NULL, "Syntax error");
	return (NULL);
}

static char						*get_match(char *s, char *m)
{
	if (!match(s, m))
		ft_exit("Bad ", m, " header");
	return (get_quote(s));

}

static void						fill(header_t *h, char *t, char *t2)
{
	int							i;

	i = -1;
	while(t[++i])
		h->prog_name[i] = t[i];
	i = -1;
	while(t2[++i])
		h->comment[i] = t2[i];
	free(t);
	free(t2);
}


char							*skipp(t_file *file)
{
	char						*s;
	char						*x;

	while ((s = ft_get_line(file)))
	{
		if ((x = ft_strtrim(s))[0] != '#')
			break;
		free(s);
	}
	free(s);
	return (x);
}

void							get_header(header_t *h)
{
	t_file						*file;
	char						*t;
	char						*t2;
	char						*s;

	file = single_file();
	h->magic = 0xea83f3;
	h->prog_size = 0;
	s = skipp(file);
	t = get_match(s, NAME_CMD_STRING "*");
	free(s);
	s = skipp(file);
	t2 = get_match(s, COMMENT_CMD_STRING "*");
	free(s);
	fill(h, t, t2);
}