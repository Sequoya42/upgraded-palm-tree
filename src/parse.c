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

void							ft_parse(t_core *core)
{
	if (!(core->header = ft_memalloc(sizeof(header_t))))
		ft_exit(NULL, "header", "bad alloc");
	get_header(core->header);
	get_instructions(core);
	core->header->prog_size = core->token->nb_bytes;
	write_header(core);
	write_file(core);
}