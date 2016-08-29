/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 19:51:47 by rbaum             #+#    #+#             */
/*   Updated: 2016/08/16 19:51:50 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

# include "op.h"
# include "libft.h"
# include <fcntl.h>
# include "definition.h"

typedef enum e_type				t_type;
typedef	struct s_core			t_core;
typedef struct s_file			t_file;
typedef struct s_token			t_token;
typedef struct s_label			t_label;

struct							s_core
{
	int							output;
	int							current_op;
	int							op_index;
	char						*name;
	t_file						*file;
	header_t					*header;
	t_token						*token;
	t_label						*label;
};

struct							s_file
{
	int							fd;
	unsigned int				index;
	unsigned int				line;
	char						*content;
	unsigned int				size;
};

struct							s_token
{
	unsigned int				nb_bytes;
	unsigned int				size;
	char						*value;
	t_type						type;
	t_token						*next;
};

struct							s_label
{
	unsigned int				nb_bytes;
	char						*value;
	t_label						*next;
};

typedef void					(*t_fptr)(t_core *c, t_token *t);

unsigned int					ft_endian(unsigned int val);
int								match_array(char *s1);
char							*ft_get_line(t_file *file);
char							*get_word(char **s);
void							ft_init(t_core *core, char *arg);
void							ft_parse(t_core *core);
void							get_header(header_t *h);
void							write_header(t_core *core);
void							get_instructions(t_core *core);
void							match_operator(char *w, char *s, t_core *core);
void							match_label(char *t, char *s, t_core *core);
void							match_label_t(t_token *t, t_core *c);
void							fill_token(int type, char *w, t_core *core);
void							add_new(t_token **alst, t_token *new);
void							add_new_label(t_label **alst, t_label *new);
void							manage_arg(int op, char *s, t_core *core);
void							write_file(t_core *core);
void							write_label(t_core *c, t_token *t);
void							verify_last(char *s);
t_file							*single_file(void);
t_token							*test(t_token *t);
t_label							*test_two(t_label *t);
#endif
