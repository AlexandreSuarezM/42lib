/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 13:59:19 by asuarez           #+#    #+#             */
/*   Updated: 2026/11/04 21:33:28 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


void	ft_lstdelone(t_list **lst)
{
	t_list	*aux;

	if (!*lst)
		return ;
	aux = *lst;
	if((*lst)->down = *lst)
		*lst = NULL;
	else
	{
		(*lst)->down->up = (*lst)->up;
		(*lst)->up->down = (*lst)->down;
		*lst = (*lst)->down;
	}
	free(aux);
}
