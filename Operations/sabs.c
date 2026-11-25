/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sabs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 20:14:08 by asuarez           #+#    #+#             */
/*   Updated: 2026/11/12 18:31:37 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
//swap the 2 first elements of stack a b or both 
// for wenever i forguet
// **lst is the adress of the struct 
// *lst acces the struct 
// -> acces de content of the pointer struct
// so *lst -> is basically (**lst). 
// why do we need to parse ** lst instead of *lst for structures in void to keep the data modified ? isnt it suficient for a linked list to modify the content ? oh because *lst is alreadu the position were the eleemnt of the list resides 
// so we want to update the posiion of the first element of the lsit ?
// i might have made it confusing for 0 reson...
// circular list: bottom <-> A <-> B <-> C ... -> bottom
// after swap:    bottom <-> B <-> A <-> C ... -> bottom
// with 2 nodes the circle is A <-> B, so swapping = moving the top pointer
// op: OP_SA / OP_SB to print it, OP_SILENT to stay quiet
void	swap(t_list **lst, int op)
{
	t_list	*a;
	t_list	*b;

	if (!lst || !*lst || (*lst)->down == *lst)
		return ;
	a = *lst;
	b = a->down;
	*lst = b;
	op_log(op);
	if (b->down == a)
		return ;
	a->up->down = b;
	b->down->up = a;
	a->down = b->down;
	b->up = a->up;
	a->up = b;
	b->down = a;
}

// ss: sa and sb at the same time, counts as ONE operation
void	ss(t_list **a, t_list **b)
{
	swap(a, OP_SILENT);
	swap(b, OP_SILENT);
	op_log(OP_SS);
}

