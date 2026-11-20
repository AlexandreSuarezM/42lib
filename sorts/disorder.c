/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 15:52:56 by asuarez           #+#    #+#             */
/*   Updated: 2026/11/20 14:29:46 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
// given a list returns the metric of misplaced with.
double	disorder(t_list *lst)
{
	int		total;
	int		mistakes;
	t_list	*aux;
	t_list	*aux2;

	if (!lst || lst->down == lst)
    	return (0.0);
	mistakes = 0;
	total = 0;
	aux = lst;
	while(lst->down != aux)
	{
		aux2 = lst->down;
		while (aux2 != lst)
		{
			total++;
			if(aux2->rel_pos > lst->rel_pos)
				mistakes++;
			aux2 = aux2->down;
		}
		lst = lst->down;
	}
	return (((double)mistakes)/total);
}
