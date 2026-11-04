/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sabs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 20:14:08 by asuarez           #+#    #+#             */
/*   Updated: 2026/11/04 21:38:08 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//swap the 2 first elements of stack a b or both 
// for wenever i forguet
// **lst is the adress of the struct 
// *lst acces the struct 
// -> acces de content of the pointer struct
// so *lst -> is basically (**lst). 
// why do we need to parse ** lst instead of *lst for structures in void to keep the data modified ? isnt it suficient for a linked list to modify the content ? oh because *lst is alreadu the position were the eleemnt of the list resides 
// so we want to update the posiion of the first element of the lsit ?
// i might have made it confusing for 0 reson...
void	flip(t_list **lst)
{
	t_list	*aux;

	if (!lst || !(*lst) || !(*lst)->down)
		return ;
	// first linkers save queue
	aux = (*lst)->top;
	(*lst)->top = (*lst)->down;
	(*lst)->down = (*lst)->down->down;
	(*lst)->down->up = *lst;
	//now the postion of A is good 
	// B positions 
	*lst = (*lst)->up;
	(*lst)->down = (*lst)->up;
	(*lst)->up = aux;
}
