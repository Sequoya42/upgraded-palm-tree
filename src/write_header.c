/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 21:53:14 by rbaum             #+#    #+#             */
/*   Updated: 2016/08/17 21:53:18 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void							fill_blank(int i, int fd)
{
	int							j;

	j = -1;
	char t[i];
	ft_bzero(t, i);
	write(fd, t, i);
}

unsigned int					ft_endian(unsigned int val)
{
    val = ((val << 8) & 0xFF00FF00 ) | ((val >> 8) & 0xFF00FF ); 
    return (val << 16) | (val >> 16);
}

void							write_header(t_core *core)
{
	unsigned int				length;

	length = ft_endian(core->header->magic);
	write(core->output, &length, sizeof(int));
	ft_putstr_fd(core->header->prog_name, core->output);
	length = PROG_NAME_LENGTH - ft_strlen(core->header->prog_name);
	fill_blank(length, core->output);
	length = ft_endian(0);
	write(core->output, &length, sizeof(int));
	length = ft_endian(core->header->prog_size);
	write(core->output, &length, sizeof(int));
	ft_putstr_fd(core->header->comment, core->output);
	length = COMMENT_LENGTH - ft_strlen(core->header->comment);
	fill_blank(length, core->output);
	length = ft_endian(0);
	write(core->output, &length, sizeof(int));
}
