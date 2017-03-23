/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <abarriel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 19:36:08 by abarriel          #+#    #+#             */
/*   Updated: 2017/03/23 04:06:15 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** RID RDI FOR SILENCE WARNING
**/
#include "asm.h"
#define RID T_REG | T_IND | T_DIR
#define RDI T_REG | T_DIR | T_IND

void	init_op(void **res)
{
	static const t_op op[] = {{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
		{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
		{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
		{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
		{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
		{"and", 3, {RDI, RID, T_REG}, 6, 6, "r1,r2,r3. r1&r2 -> r3", 1, 0},
		{"or", 3, {RID, RID, T_REG}, 7, 6, "r1,r2,r3. r1 | r2 -> r3", 1, 0},
		{"xor", 3, {RID, RID, T_REG}, 8, 6, "r1,r2,r3. r1^r2 -> r3", 1, 0},
		{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
		{"ldi", 3, {RDI, T_DIR | T_REG, T_REG}, 10, 25, "load index", 1, 1},
		{"sti", 3, {T_REG, RDI, T_DIR | T_REG}, 11, 25, "store index", 1, 1},
		{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
		{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
		{"lldi", 3, {RDI, T_DIR | T_REG, T_REG}, 14, 50, "lng lod idx", 1, 1},
		{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
		{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
		{0, 0, {0}, 0, 0, 0, 0, 0}};

	*res = (void*)op;
}

t_op	*get_op(void)
{
	void **get_op;
	t_op *res;

	*get_op = NULL;
	init_op(get_op);
	res = (t_op*)*get_op;
	return (res);
}

int		skip_space(char **s)
{
	while ((**s) == ' ' || (**s) == '\t')
		(*s)++;
	return (0);
}

t_asm	*init_asm(void)
{
	t_asm		*a;

	if (!(a = (t_asm*)malloc(sizeof(t_asm))))
		ft_exit("Failed to Malloc Asm/Struct");
	a->champ_name = NULL;
	a->cor = NULL;
	a->fd_champ = -1;
	a->len_line = 0;
	a->count_line = 0;
	a->header_passage = 0;
	a->fd_cor = -1;
	return (a);
}

t_header		*init_header(void)
{
	t_header	*h;

	if (!(h = (t_header*)malloc(sizeof(t_header))))
		ft_exit("Failed to Malloc Asm/Struct");
	return (h);
}

t_lab		*init_lab(void)
{
	t_lab	*l;

	if (!(l = (t_lab*)malloc(sizeof(t_lab))))
		ft_exit("Failed to Malloc Asm/Struct");
	l->next = NULL;
	return (l);
}

void 		add_back_lab(t_lab **l_t)
{
	t_lab *l;

	l = *l_t;
	if(!l)
	{
		(*l_t) = init_lab();
		return ;
	}
	while (l->next)
		l = l->next;
	l->next = init_lab();
	l = l->next;
}
