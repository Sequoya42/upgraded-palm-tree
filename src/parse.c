/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 01:18:31 by rbaum             #+#    #+#             */
/*   Updated: 2016/08/17 01:18:34 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void							fill_file(t_core *core)
{
	int							flag;

	flag = 0;
	flag |= O_CREAT | O_APPEND | O_WRONLY | O_TRUNC;
	core->output = open(core->name, flag, 0644);
	if (core->output <= -1)
		ft_exit(NULL, NULL, "Could not create file .cor");
	if (core->token)
		core->header->prog_size = core->token->nb_bytes;
	else
		core->header->prog_size = 0;
	write_header(core);
	if (core->token)
		write_file(core);
}

void							ft_parse(t_core *core)
{
	if (!(core->header = ft_memalloc(sizeof(t_header))))
		ft_exit(NULL, "header", "bad alloc");
	get_header(core->header);
	get_instructions(core);
	free(core->file->content);
	fill_file(core);
}
