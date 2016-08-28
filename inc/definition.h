/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definition.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 03:13:46 by rbaum             #+#    #+#             */
/*   Updated: 2016/08/18 03:14:01 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINITION_H
# define DEFINITION_H

typedef enum e_code				t_opcode;

# define BREAK_CHAR				"," " " "\t" "\0" "\r" "\n"
# define GOT(x)					g_op_tab[x - 1]

# define TKN_HEAD				test(NULL)
# define LBL_HEAD				test_two(NULL)
# define IS_IN(x, y, z)			(x == (x & GOT(y).arg[z]) ? 1 : 0)
# define T_OPERATOR(x)			(x == LIVE || x == ZJMP || x == FORK || x == LFORK) ? 1 : 2
# define DIR_OP(x)				(x == LLD || x <= XOR) ? T_IND : T_DIR
# define IDIR_OP(x)				(x == LLD || x <= XOR) ? T_DIR : T_IND

# define WRITE_INT(x)			ft_endian(x)
# define SWAP(x)				((x >> T_LAB) | (x << T_LAB))
# define ARG_ONE				t->next
# define ARG_TWO				t->next->next
# define ARG_THREE				t->next->next->next

enum							e_type
{
	REGISTER = 1,
	DIRECT,
	INDIRECT,
	LABEL,
	OPERATOR,
	TYPE_LEN
};

enum							e_code 
{
	LIVE = 1,
	LD,
	ST,
	ADD,
	SUB,
	AND,
	OR,
	XOR,
	ZJMP,
	LDI,
	STI,
	FORK,
	LLD,
	LLDI,
	LFORK,
	AFF,
};

#endif
