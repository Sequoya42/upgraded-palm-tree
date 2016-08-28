/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 20:20:17 by rbaum             #+#    #+#             */
/*   Updated: 2016/08/16 20:20:22 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"


static void						ft_prepare_header(t_core *core, char *arg)
{
	int							i;
	int							flag;

	i = -1;
	flag = 0;
	core->name = ft_memalloc(ft_strlen(arg + 3));
	while (arg[++i] != '.')
		core->name[i] = arg[i];
	core->name[i] = '\0';
	core->name = ft_strjoin(core->name, ".cor");
	// flag |= O_CREAT | O_APPEND | O_WRONLY | O_TRUNC;
	// core->output = open(core->name, flag, 0644);
	// if (core->output <= -1)
	// 	ft_exit(NULL, NULL, "Could not create file .cor");
}

void							ft_init(t_core *core, char *arg)
{
	t_file						*file;
	unsigned int				flag;

	flag = 0;
	file = single_file();
	ft_prepare_header(core, arg);
	if ((file->fd = open(arg, O_RDONLY)) <= -1)
		ft_exit(NULL, "Bad fd", "Could not open file");
	file->size = (int)lseek(file->fd, 0, SEEK_END) + 1;
	file->index = 0;
	lseek(file->fd, 0, SEEK_SET);
	if (!(file->content = ft_memalloc(file->size * sizeof(char))))
		ft_exit(NULL, "file->content", "Bad alloc");
	read(file->fd, file->content, file->size);
	core->file = file;
	flag |= O_CREAT | O_APPEND | O_WRONLY | O_TRUNC;
	core->output = open(core->name, flag, 0644);
	if (core->output <= -1)
		ft_exit(NULL, NULL, "Could not create file .cor");

	// core->token = NULL;
}