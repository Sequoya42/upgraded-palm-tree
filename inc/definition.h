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
// x=T_REG|T_DIR|T_IND
// y= STI|LD etc, operator
// z = number of arg
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



// typedef union u_info			t_info;
// typedef struct s_operator		t_operator;
// // typedef struct s_reg			t_r;
// typedef struct s_dir			t_d;
// typedef struct s_idir			t_i;
// typedef struct s_label			t_l;

// sti	r1, %:live, %1			; 0b 68 01 00 45 00 01
// sti	r1, %:live2, %1			; 0b 68 01 00 22 00 01
// ld	%1, r3					; 02 90 00 00 00 01 03
// ld	%33, r6					; 02 90 00 00 00 21 06

// forks:
// add	r2, r3, r2				; 04 54 02 03 02
// xor	r2, %15, r4				; 08 64 02 00 00 00 0f  04

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

// const char	*g_code_name[] =
// {
// 	[0] = "NONE",
// 	[LIVE] = "live",
// 	[LD] = "ld",
// 	[ST] = "st",
// 	[ADD] = "add",
// 	[SUB] = "sub",
// 	[AND] = "and",
// 	[OR] = "or",
// 	[XOR] = "xor",
// 	[ZJMP] = "zjmp",
// 	[LDI] = "ldi",
// 	[STI] = "sti",
// 	[FORK] = "fork",
// 	[LLD] = "lld",
// 	[LLDI] = "lldi",
// 	[LFORK] = "lfork",
// 	[AFF] = "aff"
// };

// struct	s_operator {
// 	t_opcode					opc;
// 	unsigned int				params;
// 	unsigned int				size_params;
// };

// // struct	s_reg {

// // };

// struct	s_dir {

// };

// struct	s_idir {

// };

// struct	s_label {
// 	char						*name;

// };

// union	u_info {
// 	// t_r							reg;
// 	unsigned int				reg;
// 	t_d							dir;
// 	t_i							ind;
// 	t_l							lab;
// };


#endif
