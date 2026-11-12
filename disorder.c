/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 15:52:56 by asuarez           #+#    #+#             */
/*   Updated: 2026/11/10 17:47:53 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
// given a list returns the metric of misplaced with.
double	disorder(t_list *lst)
{
	int		total;
	int		mistakes;
	t_list	*aux;

	mistakes = 0;
	total = 0;
	aux = lst;
	while(lst->down != aux)
	{
		if(lst->rel_pos < lst->down->rel_pos)
			mistakes++;
		total++;
		lst = lst->down;
	}
	return (((double)mistakes)/total);
}



