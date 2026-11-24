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
void	swap(t_list **lst)
{
	t_list	*aux;

	if (!lst || !(*lst) || !(*lst)->down)
		return ;
	// save queue node
	aux = (*lst)->up; 
	// top node up now points to the switched node     
	(*lst)->up = (*lst)->down;
	// bottom part of the node now points to what the bottom node points down
	// first node points well
	(*lst)->down = (*lst)->down->down;
	// new top of the stack is b wich was accesed via top up
	*lst = (*lst)->up;
	// update queue node now up to b  
	aux->up = *lst;
	// b down now poits to a    rpevious b up
	(*lst)->down = (*lst)->up;
	// b up is queue
	(*lst)->up = aux;	
}

