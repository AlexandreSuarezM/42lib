/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 14:14:03 by asuarez           #+#    #+#             */
/*   Updated: 2026/11/10 17:53:47 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// la reserva de memoria ya esta liberada por nodos .
// vale aqui pasta code con la del mejor 
// del borra todo el interior de la estructura sin perder al guia.
void	ft_lstclear(t_list **lst)
{
	t_list	*aux;

	if (lst)
	{
		while (*lst)
		{
			free((*lst)->content);
			aux = ((*lst)->down);
			free(*lst);
			*lst = aux;
		}
		*lst = NULL;
	}
}
