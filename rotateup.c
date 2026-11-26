/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotateup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 21:36:42 by asuarez           #+#    #+#             */
/*   Updated: 2026/11/10 17:17:31 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pushswap.h"

// ra / rb: the top goes to the bottom
// circular list, so it is just moving the top pointer one down
void	rotateup(t_list **lst, int op)
{
	if (!lst || !*lst)
		return ;
	*lst = (*lst)->down;
	op_log(op);
}

// rr: ra and rb at the same time, counts as ONE operation
void	rr(t_list **a, t_list **b)
{
	rotateup(a, OP_SILENT);
	rotateup(b, OP_SILENT);
	op_log(OP_RR);
}
