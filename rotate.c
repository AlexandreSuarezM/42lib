/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 21:34:35 by asuarez           #+#    #+#             */
/*   Updated: 2026/11/10 17:17:35 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pushswap.h"

// rra / rrb: the bottom comes to the top
// circular list, so it is just moving the top pointer one up
void	rotatedown(t_list **lst, int op)
{
	if (!lst || !*lst)
		return ;
	*lst = (*lst)->up;
	op_log(op);
}

// rrr: rra and rrb at the same time, counts as ONE operation
void	rrr(t_list **a, t_list **b)
{
	rotatedown(a, OP_SILENT);
	rotatedown(b, OP_SILENT);
	op_log(OP_RRR);
}
