/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 16:08:54 by asuarez           #+#    #+#             */
/*   Updated: 2026/10/15 18:38:54 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// prebuild <> users "" 

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	while ((*lst)->next)
	{
		lst = &(*lst)->next;
	}
	(*lst)->next = new;
}
