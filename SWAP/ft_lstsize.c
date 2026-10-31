/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 15:55:05 by asuarez           #+#    #+#             */
/*   Updated: 2026/10/31 19:12:09 by asuarez          ###   ########.fr       */
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
		// content is a void at base maybe adapt it on the def
		ft_printf("%d\n",lst->content);
		lst = lst->next;
		count_nodes++;
	}
	return (count_nodes);
}
