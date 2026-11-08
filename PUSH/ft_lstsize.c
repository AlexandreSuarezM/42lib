/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 15:55:05 by asuarez           #+#    #+#             */
/*   Updated: 2026/10/15 19:04:43 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_lstsize(t_list *lst)
{
	unsigned int	count_nodes;

	if (!lst)
		return (0);
	count_nodes = 0;
	while (lst)
	{
		lst = lst->next;
		count_nodes++;
	}
	return (count_nodes);
}
