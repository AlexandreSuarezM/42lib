/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 15:26:59 by asuarez           #+#    #+#             */
/*   Updated: 2026/11/19 21:25:17 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// node -> value es (*node)->value accede al nodo i luego al valor que es *int
t_list	*ft_lstnew(int num)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = num;
	node->up = NULL;
	node->down = NULL;
	node->rel_pos = 0;
	return (node);
}
