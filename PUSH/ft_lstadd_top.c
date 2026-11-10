/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_top.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 15:33:50 by asuarez           #+#    #+#             */
/*   Updated: 2026/11/10 16:23:11 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Lis is the header to the dirst pointer of alist */
// options for last each node recalls alst
// no operations but updates when it chcanges 
// las is acecile from top
// eaasy acces but each operations has to search it 
// we keep it in som extra variable *last
// swap works fine rotate is a update of las wich is accecible fast 
// 

#include "libft.h"

void	ft_lstadd_top(t_list **lst, t_list *new)
{
	if (!new || !lst)
		return ;
	if(!*lst)
	{
		new->up = new;
		new->down = new;
		*lst = new;
		return ;
	}
	new->down = *lst;
	new->up = (*lst)->up;
	(*lst)->up->down = new;
	(*lst)->up = new;
	*lst = new;
}

