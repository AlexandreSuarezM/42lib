/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 14:14:03 by asuarez           #+#    #+#             */
/*   Updated: 2026/11/19 19:11:44 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// la reserva de memoria ya esta liberada por nodos .
// vale aqui pasta code con la del mejor 
// del borra todo el interior de la estructura sin perder al guia.
void	ft_lstclear(t_list **lst, char **args)
{
	t_list	*aux;
	int	i;

	i = 0;
	if (lst && *lst)
	{
		(*lst)->up->down = NULL;
		while (*lst)
		{
			(*lst)->content = 0;
			aux = ((*lst)->down);
			free(*lst);
			*lst = aux;
		}
		*lst = NULL;
	}
	if (!args)
		return ;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}
