/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 16:58:13 by asuarez           #+#    #+#             */
/*   Updated: 2026/10/31 18:05:13 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// move from to to the first element
// **from so from point to (outer fucntion) so accesing *from modifies the adress ence the real one

static void (*del)(void *num)
{
	int *i;
	i = (int *) num;
	*num = 0;
}



void	(t_list **from, t_list **to)
{
	if (*from)
	{
	// adds *from node to too list and updates it .
		*ft_lstadd_front(**to,*from);
		*from = (*to)->down;
	}
	ft_lstdelone(from, del);
}