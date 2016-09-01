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

#if 0
void FAIRE LE TRUC POUR LenRuLE AVEC PARENTHESE " " POUR \n
	
#endif

static char						*get_last_quote(t_file *f, char *b)
{
	int							i;
	char						*s;
	char						*r;

	r = b;
	while((s = ft_get_line(f)))
	{
		i = -1;
		while (s[++i])
		{
			if (s[i] == '"')
			{
				return (ft_strjoin(r, ft_strsub(s, 0, i)));
			}
		}
		r = ft_strjoin(b, s);
	}
	msg_exit("Error in header");
	return (NULL);
}

static char						*get_quote(char *s)
{
	int							i;
	int							j;

	i = 0;
	j = -1;
	while (s[i++])
	{
		if (s[i] == '"')
		{
			if (j != -1)
				return (ft_strsub(s, j + 1, i - j - 1));
			j = i;
		}
	}
	return (get_last_quote(single_file(), ft_strsub(s, j + 1, i - j - 1)));
}

static void						fill(t_header *h, char *t, char *t2)
{
	int							i;

	i = -1;
	while (t[++i] && (i < PROG_NAME_LENGTH))
		h->prog_name[i] = t[i];
	i = -1;
	while (t2[++i] && (i < COMMENT_LENGTH))
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
		x = ft_strtrim(s);
		if ((x[0] != COMMENT_CHAR && x[0] != EOL_CHAR))
			break ;
		free(s);
	}
	free(s);
	return (x);
}

void							get_header(t_header *h)
{
	t_file						*file;
	char						*t;
	char						*t2;
	char						*s;

	file = single_file();
	h->magic = 0xea83f3;
	h->prog_size = 0;
	s = skipp(file);
	if (!match(s, NAME_CMD_STRING "*"))
		ft_exit("Bad ", NAME_CMD_STRING "*", " header");
	t = get_quote(s);
	free(s);
	s = skipp(file);
	if (!match(s, COMMENT_CMD_STRING "*"))
		ft_exit("Bad ", COMMENT_CMD_STRING "*", " header");
	t2 = get_quote(s);
	free(s);
	fill(h, t, t2);
}
