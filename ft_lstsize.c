/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 15:55:05 by asuarez           #+#    #+#             */
/*   Updated: 2026/11/12 19:33:42 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

unsigned int	ft_lstsize(t_list *lst)
{
	unsigned int	count_nodes;
	t_list	*aux;

	aux = lst;
	if (!lst)
		return (0);
	count_nodes = 0;
	while (lst->down != aux)
	{
		lst = lst->down;
		count_nodes++;
	}
	count_nodes++;
	return (count_nodes);
}
