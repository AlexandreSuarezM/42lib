/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 14:14:03 by asuarez           #+#    #+#             */
/*   Updated: 2026/11/04 22:01:26 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// la reserva de memoria ya esta liberada por nodos .

void	ft_lstclear(t_list **lst)
{
	t_list	*aux;

	if (lst && del)
	{
		while (*lst)
		{
			aux = ((**lst).down);
			free(*lst);
			*lst = aux;
		}
		*lst = NULL;
	}
}
