/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 13:59:19 by asuarez           #+#    #+#             */
/*   Updated: 2026/11/17 15:54:29 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_list *popfirst(t_list **lst)
{
    t_list *node;

    if (!lst || !*lst)
        return NULL;
    node = *lst;
    if ((*lst)->down == *lst)
        *lst = NULL;
    else
    {
        (*lst)->down->up = (*lst)->up;
        (*lst)->up->down = (*lst)->down;
        *lst = (*lst)->down;
    }
    node->up = node;
    node->down = node;
    return node;
}