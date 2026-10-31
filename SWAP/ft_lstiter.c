/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 15:10:58 by asuarez           #+#    #+#             */
/*   Updated: 2026/10/15 19:01:46 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
check de content
mientras el nodo no sea vacio
aplicamos la funcio al content que es lo que modifica void*
el adres lst se mueve amb nodo siguiente lst es puntero 
 * lst pointr to the first t_list
 * f void modifies a t_list.content
 * parse the *list wich is a t-lsit then acces the content
 * because we modifi lst with the (*lst).next the condition 
 * to stop is lst but lst is the lsit it has to be lst 
 * lst es un t_struct  *   
 *
 * */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst && f)
	{
		while (lst)
		{
			f((*lst).content);
			lst = (*lst).next;
		}
	}
}
