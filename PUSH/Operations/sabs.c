/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sabs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 20:14:08 by asuarez           #+#    #+#             */
/*   Updated: 2026/11/11 15:37:54 by asuarez          ###   ########.fr       */
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
void	swap(t_list **lst)
{
	t_list	*aux;

	if (!lst || !(*lst) || !(*lst)->down)
		return ;
	// first linkers save queue
	aux = (*lst)->up;      
	(*lst)->up = (*lst)->down;
	(*lst)->down = (*lst)->down->down;
	aux->down = *lst;
	//now the postion of A is good 
	// B positions 
	*lst = (*lst)->up;
	(*lst)->down = (*lst)->up;
	(*lst)->up = aux;
}

//
//
//aux = lst->up;
//lst->up = lst->down
//lst->down = lst->down->down
//// aux last in list
//// b node points up to a and bot top c 
//// bot up points 
//// make c top point ot a 
//// c was lst -> down ->down
//// but lst->down is now ->down -.down
//lst->down->up = lst;
////c points a a points c and b
//// b becomes lst 
//lst = lst->up; 
//aux->down = lst
//// b points to queue and a 
//// a is on top of b  
//lst->down = lst->up;
//lst->up = aux;
//
//()
//