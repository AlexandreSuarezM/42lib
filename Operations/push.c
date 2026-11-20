/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 21:17:47 by asuarez           #+#    #+#             */
/*   Updated: 2026/11/20 13:17:57 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
// Pushes the first element from to 
void push(t_list **from, t_list **to)
{
    t_list *node;
    node = popfirst(from);
    if (!node)
        return;
    ft_lstadd_top(to, node);
	
}