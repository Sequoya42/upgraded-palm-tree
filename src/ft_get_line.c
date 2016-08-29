/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 01:32:54 by rbaum             #+#    #+#             */
/*   Updated: 2016/08/17 01:33:01 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"


void						print_local_info(t_file *file, char *s)
{
	ft_putstr("index:");
	ft_putnbrendl(file->index);
	ft_putstr("line ");
	ft_putnbrn(file->line);
	ft_putendl(s);
}

char							*get_word(char **s)
{
	char						*t;

	if (!*s || **s == '\0')
		return (NULL);
	while (match_char(**s, BREAK_CHAR))
		(*s)++;
	t = *s;
	while (**s)
	{
		if (**s == ';' || **s == COMMENT_CHAR)
			return (NULL);
		if (match_char(**s, BREAK_CHAR))
			return (ft_strsub(t, 0, (*s) - t));
		(*s)++;
	}
	return(ft_strdup(t));
}

char							*ft_get_line(t_file *file)
{
	static int					line = 0;
	int							j;
	int							i;
	char						*s;
	char						*ret;

	i = file->index;
	j = file->index;
	s = file->content;
	if (file->index >= file->size)
		return (NULL);
	while (s[i])
	{
		if (s[i] == '\n')
			break;
		i++;
	}
	ret = ft_strsub(s, j, i - j);
	file->index = i + 1;
	file->line = line++;
	if (is_blank(ret))
	{
		free(ret);
		return (ft_get_line(file));
	}
	// print_local_info(file, ret);
	return (ret);
}