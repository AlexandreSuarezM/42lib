/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 15:33:50 by asuarez           #+#    #+#             */
/*   Updated: 2026/11/04 18:02:02 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Lis is the header to the dirst pointer of alist */

#include "libft.h"

void	ft_lstadd_up(t_list **lst, t_list *new)
{
	if (!new || !lst)
		return ;
	new->down = *lst;
	if (*lst !=NULL)
		(*lst)->up = new;
	*lst = new;
}

