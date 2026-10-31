/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sasb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 16:03:15 by asuarez           #+#    #+#             */
/*   Updated: 2026/10/31 17:16:00 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//swaps the first 2 elements of stack a if avaialble
// the linked list i have *lst is the top of the stack
// the linked list is the struc
// what needs to be sorted is the node itself not just the content.
// A node position is determined by who point at him and to who it points to
// to swap the 2 first i take the bottom one and but it on top
// that is the *lst tha
// update the real one not the copy

void	sa(t_list **lst)
{
	t_list	*aux;
	// aux is a memory allocation that pints to it.
	//lst is the pointer that point to the adress 
	// i want to modify the adrss that is *lst
	// now wich adresses i want to modify ?
	// the *lst -> (*lst)->next -> (*lst)->next->next
	// save the adress of B in -*lst>A -B -B keept in A-> down

	// check if those exist because nodes are initialize with null on adress no nned to chekc for 3d node swap. 
	if (!lst || !(*lst)->down)
		return (NULL);
	aux = (*lst)-> down;
	// make A point at C that si keept into B-> down
	(*lst)->down = aux->down;
	// make b point to A 
	aux -> down = *lst;
	// update the value of lst in the program not the copy 
	*lst = aux;
}

// So i basically get the 
// sa & sb & ss is both at the same time
