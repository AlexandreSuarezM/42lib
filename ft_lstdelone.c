/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 13:59:19 by asuarez           #+#    #+#             */
/*   Updated: 2026/11/16 20:10:15 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_list	*popfirst(t_list **lst)
{
	if (!*lst)
		return NULL ;
	if((*lst)->down == *lst)
		return (*lst);
	else
	{
		(*lst)->down->up = (*lst)->up;
		(*lst)->up->down = (*lst)->down;
		*lst = (*lst)->down;
	}
	return (*lst);
}
