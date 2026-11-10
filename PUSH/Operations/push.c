/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 21:17:47 by asuarez           #+#    #+#             */
/*   Updated: 2026/11/10 21:16:44 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
// Pushes the first element from to 
void	push(t_list **from,t_list **to)
{
	ft_lstadd_top(from, *to);
	ft_lstdelfirst(from);
}